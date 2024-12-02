#include "pch.h"
#include "Pmap.h"

Pmap::Pmap(sf::RenderWindow* window, sf::Event* event)
{
    this->window = window;

    this->event = event;

    if (editor)
    {
        editorRectString = L"0x0";
        editorRect = new Ptext(window, event, "Data/Fonts/Upheaval Pro/UpheavalPro.ttf", editorRectString, sf::Color::White);
        editorRect->SetOrigin({ 0.5f, 0.0f }, true);
        editorRect->GetTamplate()->setCharacterSize(45U);
        editorRect->GetTamplate()->setOutlineThickness(5.0f);
        editorRect->GetTamplate()->setOutlineColor(sf::Color::Black);

        editorMode = new Ptext(editorRect, L"none");
        editorMode->SetTamplate(editorRect->GetTamplate());
        editorMode->SetOrigin({ 0.5f, 0.0f }, true);

        editorSolidText = L"no.";
        editorSolid = new Ptext(editorRect, editorSolidText);
        editorSolid->SetTamplate(editorRect->GetTamplate());
        editorSolid->SetOrigin({ 0.5f, 0.0f }, true);
    }
}


void Pmap::LoadMap(std::wstring pathMap, std::string texturePath)
{
    this->pathMap = pathMap;
    this->texturePath = texturePath;

    sizeTile.x = std::stoi(Config::Read(pathMap, L"sizeTileX"));
    sizeTile.y = std::stoi(Config::Read(pathMap, L"sizeTileY"));

    originalSizeTile.x = std::stoi(Config::Read(pathMap, L"sizeTileX"));
    originalSizeTile.y = std::stoi(Config::Read(pathMap, L"sizeTileY"));

    countTile = std::stoi(Config::Read(pathMap, L"countTile"));


    sf::Vector2f positionTile = sf::Vector2f(0.0f, 0.0f);

    for (sf::Uint16 numberTile = 0; numberTile < countTile; numberTile++)
    {
        std::wstring tileInfo = Config::Read(pathMap, L"sprite" + std::to_wstring(numberTile + 1));


        sf::Uint16 left = 0U;

        sf::Uint16 top = 0U;


        left = std::stoi(tileInfo.substr(tileInfo.find(L"$") + 1, tileInfo.find(L"x")));

        top = std::stoi(tileInfo.substr(tileInfo.find(L"x") + 1, tileInfo.find(L"|")));


        positionTile.x = std::stoi(tileInfo.substr(0, tileInfo.find(L"r"))) * sizeTile.x;

        positionTile.y = std::stoi(tileInfo.substr(tileInfo.find(L"r") + 1, tileInfo.find(L"$"))) * sizeTile.y;


        Psprite* tile = new Psprite(window, event, texturePath, new sf::IntRect(left, top, sizeTile.x, sizeTile.y));

        tile->SetPixelPosition(positionTile);


        Pcolader* colader = new Pcolader(window, event, tile->GetPosition(), { sizeTile.x, sizeTile.y }, L"sprite" + std::to_wstring(numberTile + 1));

        colader->SetSprite(tile);

        if (tileInfo.substr(tileInfo.find(L"|") + 1, tileInfo.find(L".")) == L"yes.")
        {
            colader->SetSolid(true);

            solidColaders.push_back(colader);
        }


        coladers.push_back(colader);

        tiles.push_back(tile);
    }
}


void Pmap::SetScale(sf::Vector2f scale)
{
    sizeTile.x *= scale.x;
    sizeTile.y *= scale.y;

    for (sf::Uint16 i = 0; i < tiles.size(); i++)
    {
        tiles[i]->SetScale({ scale.x, scale.y });

        tiles[i]->SetPixelPosition({ tiles[i]->GetPixelPosition().x * scale.x * windowScale.x, tiles[i]->GetPixelPosition().y * scale.y * windowScale.y });

        coladers[i]->SetSize({ sizeTile.x, sizeTile.y });

        coladers[i]->SetPixelPosition(tiles[i]->GetPixelPosition());
    }
}

std::vector<Pcolader*> Pmap::GetColaders()
{
    return coladers;
}

std::vector<Pcolader*> Pmap::GetConstColaders() const
{
    return coladers;
}

std::vector<Psprite*> Pmap::GetTile() const
{
    return tiles;
}

std::vector<Pcolader*> Pmap::GetSolidColaders()
{
    return solidColaders;
}


void Pmap::Update()
{
    if (editor)
    {
        editorRect->GetTamplate()->setPosition(window->mapPixelToCoords({ int(window->getSize().x / 2U), 0 }));

        editorMode->GetTamplate()->setPosition(window->mapPixelToCoords({ int(window->getSize().x / 1.5f), 0 }));

        editorSolid->GetTamplate()->setPosition(window->mapPixelToCoords({ int(window->getSize().x / 1.3f), 0 }));
    }
}

void Pmap::Events()
{
    if (editor)
    {
        if (Pinput::IsKeyPressed(sf::Keyboard::F7))
        {
            if (editorSolidText.find(L"*") == editorSolidText.npos)
            {
                editorSolidText = L"*" + editorSolidText;
            }
            else
            {
                editorSolidText.replace(editorSolidText.find(L"*"), 1, L"");
            }

            editorSolid->SetText(editorSolidText);
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::F6))
        {
            if (editorRectString.find(L"*") == editorRectString.npos)
            {
                editorRectString = L"*" + editorRectString;
            }
            else
            {
                editorRectString.replace(editorRectString.find(L"*"), 1, L"");
            }

            editorRect->SetText(editorRectString);
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::F5))
        {
            if (editorModeText != 2)
            {
                editorModeText++;

                if (editorModeText == 1)
                {
                    editorMode->SetText(L"draw");
                }
                else
                {
                    editorMode->SetText(L"delete");
                }
            }
            else
            {
                editorModeText = 0;

                editorMode->SetText(L"none");
            }
        }

        if (editorRectString.find(L"*") != editorRectString.npos)
        {
            Pinput::IsKeyEntered(&editorRectString);

            editorRect->SetText(editorRectString);
        }

        if (editorSolidText.find(L"*") != editorSolidText.npos)
        {
            Pinput::IsKeyEntered(&editorSolidText);

            editorSolid->SetText(editorSolidText);
        }

        if (editorModeText == 1U)
        {
            if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
            {
                countTile++;

                sf::Uint16 left = std::stoi(editorRectString.substr(0, editorRectString.find(L"x")));

                sf::Uint16 top = std::stoi(editorRectString.substr(editorRectString.find(L"x") + 1));


                sf::Vector2f positionTile;

                positionTile.x = floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x / (sizeTile.x * windowScale.x));

                positionTile.y = floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y / (sizeTile.y * windowScale.y));


                std::wstring tileInfo;

                tileInfo = tileInfo + std::to_wstring(int(positionTile.x)) + L"r" + std::to_wstring(int(positionTile.y)) + L"$";

                tileInfo = tileInfo + std::to_wstring(left) + L"x" + std::to_wstring(top) + L"|" + editorSolidText;

                Config::Create(pathMap, L"sprite" + std::to_wstring(countTile), tileInfo);

                Config::Write(pathMap, L"countTile", std::to_wstring(countTile));


                positionTile.x = std::stoi(tileInfo.substr(0, tileInfo.find(L"r"))) * originalSizeTile.x;

                positionTile.y = std::stoi(tileInfo.substr(tileInfo.find(L"r") + 1, tileInfo.find(L"$"))) * originalSizeTile.y;

                Psprite* tile = new Psprite(window, event, texturePath, new sf::IntRect(left, top, originalSizeTile.x, originalSizeTile.y));

                tile->SetPixelPosition(positionTile);


                Pcolader* colader = new Pcolader(window, event, tile->GetPosition(), { sizeTile.x, sizeTile.y }, L"sprite" + std::to_wstring(countTile));

                colader->SetSprite(tile);


                if (tiles[0]->GetScale().x != 1.0f)
                {
                    tile->SetScale({ tiles[0]->GetScale().x, tiles[0]->GetScale().y });

                    tile->SetPixelPosition({ tile->GetPixelPosition().x * tiles[0]->GetScale().x * windowScale.x, tile->GetPixelPosition().y * tiles[0]->GetScale().y * windowScale.y });

                    colader->SetSize({ sizeTile.x, sizeTile.y });

                    colader->SetPixelPosition(tile->GetPixelPosition());
                }


                if (tileInfo.substr(tileInfo.find(L"|") + 1, tileInfo.find(L".")) == L"yes.")
                {
                    colader->SetSolid(true);

                    solidColaders.push_back(colader);
                }

                coladers.push_back(colader);

                tiles.push_back(tile);
            }
        }

        if (editorModeText == 2U)
        {
            if (Pinput::IsMouseButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f positionTile;

                positionTile.x = floor(floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x / (sizeTile.x * windowScale.x)) * originalSizeTile.x * tiles[0]->GetScale().x * windowScale.x);

                positionTile.y = floor(floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y / (sizeTile.y * windowScale.y)) * originalSizeTile.y * tiles[0]->GetScale().y * windowScale.y);

                for (sf::Uint16 i = 0; i < tiles.size(); i++)
                {
                    if (floor(tiles[i]->GetPixelPosition().x) == positionTile.x && floor(tiles[i]->GetPixelPosition().y) == positionTile.y)
                    {
                        tiles.erase(tiles.begin() + i);

                        countTile--;

                        Config::Delete(pathMap, L"sprite" + std::to_wstring(i + 1));

                        Config::Write(pathMap, L"countTile", std::to_wstring(countTile));

                        if ((i + 1) != (countTile + 1))
                        {
                            std::wfstream file(pathMap);

                            std::wstring line;

                            std::wstring text;

                            while (std::getline(file, line))
                            {
                                text += line + L"\n";
                            }

                            sf::Uint16 j = (i + 2);

                            while (j != (countTile + 2))
                            {
                                text.replace(text.find(L"sprite" + std::to_wstring(j)), text.find(L" ") - 1, L"sprite" + std::to_wstring(j - 1));

                                j++;
                            }

                            file.close();

                            file.open(pathMap, std::ios::out);

                            file << text;

                            file.close();
                        }
                    }
                }

                for (sf::Uint16 i = 0; i < coladers.size(); i++)
                {
                    if (floor(coladers[i]->GetPixelPosition().x) == positionTile.x && floor(coladers[i]->GetPixelPosition().y) == positionTile.y)
                    {
                        coladers.erase(coladers.begin() + i);
                    }
                }
            }

            if (Pinput::IsMouseButtonPressed(sf::Mouse::Right))
            {
                sf::Vector2f positionTile;

                positionTile.x = floor(floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).x / (sizeTile.x * windowScale.x)) * originalSizeTile.x * tiles[0]->GetScale().x * windowScale.x);

                positionTile.y = floor(floor(window->mapPixelToCoords(sf::Mouse::getPosition(*window)).y / (sizeTile.y * windowScale.y)) * originalSizeTile.y * tiles[0]->GetScale().y * windowScale.y);

                for (sf::Uint16 i = 0; i < coladers.size(); i++)
                {
                    if (floor(coladers[i]->GetPixelPosition().x) == positionTile.x && floor(coladers[i]->GetPixelPosition().y) == positionTile.y)
                    {
                        coladers.erase(coladers.begin() + i);
                    }
                }
            }
        }
    }
}

void Pmap::Draw() const
{
    for (sf::Uint16 i = 0; i < tiles.size(); i++)
    {
        tiles[i]->Draw();
    }

    if (debug)
    {
        for (sf::Uint16 i = 0; i < coladers.size(); i++)
        {
            coladers[i]->Draw();
        }
    }

    if (editor)
    {
        editorRect->Draw();
        editorMode->Draw();
        editorSolid->Draw();
    }
}
