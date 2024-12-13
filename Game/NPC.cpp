#include "NPC.h"

sf::Uint16 NPC::id = 1U;

NPC::NPC(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::IntRect rect, Player* player)
{
    this->window = window;

    this->event = event;

    this->texturePath = texturePath;

    this->rect = rect;

    this->player = player;


    speed.x = 2.0f * std::stof(Config::Read(L"Config.ini", L"windowScaleWidth"));
    speed.y = 2.0f * std::stof(Config::Read(L"Config.ini", L"windowScaleHeight"));


    sprite = new PanimatedSprite(window, event, texturePath, new sf::IntRect(0, 0, 16, 23));
    sprite->SetScale({ 4.6f, 4.6f });
    sprite->SetLoop(true);
    sprite->SetFrameTime(0.2f);

    colader = new Pcolader(window, event, sprite->GetPosition(), { 0.0f,  0.0f }, "NPC" + std::to_string(id));
    colader->SetSize({ sprite->GetSize().x * 0.9f,  sprite->GetSize().y * 0.3f }, false);
    colader->SetOrigin({ -0.05f, -1.95f });
    colader->SetSolid(true);

    id++;
}


void NPC::SetPosition(sf::Vector2f position)
{
    sprite->SetPixelPosition(position);
    colader->SetPixelPosition(position);
}


Pcolader* NPC::GetColader() const
{
    return colader;
}

PanimatedSprite* NPC::GetSprite()
{
    return sprite;
}

void NPC::ResetRect()
{
    sprite->GetSprite()->setTextureRect(previosRect);
}


void NPC::Walk(sf::Vector2f position1, sf::Vector2f position2, bool loop)
{
    if (!clockStart)
    {
        this->position1 = position1;
        this->position2 = position2;

        if (this->position1.y != this->position2.y)
        {
            isWalkingY = true;

            sprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));

            if (this->position1.y < this->position2.y)
            {
                walkVector = true;

                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
            }
        }
        else if (this->position1.x != this->position2.x)
        {
            isWalking = true;

            sprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));

            if (this->position1.x < this->position2.x)
            {
                walkVector = true;

                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));
            }
        }

        walkClock.restart();

        clockStart = true;
    }

    if (!endWalk && !isDialog)
    {
        if (isWalkingY)
        {
            if (!player->GetColader()->IsColision(colader) ||
                (player->GetColader()->GetRealPosition().x >= (colader->GetRealPosition().x + colader->GetSize().x)) ||
                ((player->GetColader()->GetRealPosition().x + player->GetColader()->GetSize().x) <= colader->GetRealPosition().x) ||
                (walkVector && player->GetColader()->IsColision(colader)) && player->GetColader()->GetRealPosition().y <= colader->GetRealPosition().y ||
                (!walkVector && player->GetColader()->IsColision(colader)) && player->GetColader()->GetRealPosition().y >= colader->GetRealPosition().y)
            {
                if (walkClock.getElapsedTime().asSeconds() >= 0.01f)
                {
                    if (this->position1.y != this->position2.y)
                    {
                        if (walkVector)
                        {
                            sprite->GetSprite()->move(0.0f, speed.y);

                            if (sprite->GetSprite()->getPosition().y > this->position2.y)
                            {
                                sprite->GetSprite()->setPosition(sprite->GetSprite()->getPosition().x, this->position2.y);

                                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));

                                endWalk = true;
                                isWalkingY = false;
                            }
                        }
                        else
                        {
                            sprite->GetSprite()->move(0.0f, -speed.y);
                            if (sprite->GetSprite()->getPosition().y < this->position2.y)
                            {
                                sprite->GetSprite()->setPosition(sprite->GetSprite()->getPosition().x, this->position2.y);

                                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));

                                endWalk = true;
                                isWalkingY = false;
                            }
                        }
                    }

                    walkClock.restart();
                }

                if (isWalking)
                {
                    sprite->Animate(16, 16, 0);
                }

                if (isWalkingY)
                {
                    sprite->Animate(16, 16, 16);
                }
            }
            else
            {
                if (player->GetColader()->GetRealPosition().y <= colader->GetRealPosition().y)
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));
                }
                else
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
                }
            }
        }
        else
        {
            if (!player->GetColader()->IsColision(colader) ||
                (player->GetColader()->GetRealPosition().y >= (colader->GetRealPosition().y + colader->GetSize().y)) ||
                ((player->GetColader()->GetRealPosition().y + player->GetColader()->GetSize().y) <= colader->GetRealPosition().y) ||
                (walkVector && player->GetColader()->IsColision(colader)) && player->GetColader()->GetRealPosition().x <= colader->GetRealPosition().x ||
                (!walkVector && player->GetColader()->IsColision(colader)) && player->GetColader()->GetRealPosition().x >= colader->GetRealPosition().x)
            {
                if (walkClock.getElapsedTime().asSeconds() >= 0.01f)
                {
                    if (this->position1.x != this->position2.x)
                    {
                        if (walkVector)
                        {
                            sprite->GetSprite()->move(speed.x, 0.0f);

                            if (sprite->GetSprite()->getPosition().x > this->position2.x)
                            {
                                sprite->GetSprite()->setPosition(sprite->GetSprite()->getPosition().x, this->position2.x);

                                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));

                                endWalk = true;
                                isWalking = false;
                            }
                        }
                        else
                        {
                            sprite->GetSprite()->move(-speed.x, 0.0f);

                            if (sprite->GetSprite()->getPosition().x < this->position2.x)
                            {
                                sprite->GetSprite()->setPosition(sprite->GetSprite()->getPosition().x, this->position2.x);

                                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));

                                endWalk = true;
                                isWalking = false;
                            }
                        }
                    }

                    walkClock.restart();
                }

                if (isWalking)
                {
                    sprite->Animate(16, 16, 0);
                }

                if (isWalkingY)
                {
                    sprite->Animate(16, 16, 16);
                }
            }
            else
            {
                if (player->GetColader()->GetRealPosition().x <= colader->GetRealPosition().x)
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));
                }
                else
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));
                }
            }
        }

        colader->SetPixelPosition(sprite->GetPixelPosition());
    }
    else if (loop && !isDialog)
    {
        if (!walkreturn)
        {
            sf::Vector2f temp = this->position1;

            this->position1 = this->position2;

            this->position2 = temp;

            walkreturn = true;
        }
        else
        {
            clockStart = false;
            walkreturn = false;
        }
        
        if (this->position1.y != this->position2.y)
        {
            isWalkingY = true;

            sprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));

            if (this->position1.y < this->position2.y)
            {
                walkVector = true;

                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
            }
        }
        else if (this->position1.x != this->position2.x)
        {
            isWalking = true;

            sprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));

            if (this->position1.x < this->position2.x)
            {
                walkVector = true;

                sprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));
            }
        }


        endWalk = false;

        walkVector = !walkVector;

        walkClock.restart();
    }
}

void NPC::Dialog(bool* eventDialog, Pdialog* dialog)
{
    if (Pinput::IsKeyPressed(sf::Keyboard::Enter))
    {
        if (player->GetColader()->IsColision(colader))
        {
            *eventDialog = true;

            isDialog = true;

            dialog->SetPosition({ 0.5f, 1.0f }, true);

            previosRect = sprite->GetSprite()->getTextureRect();


            if (isWalkingY)
            {
                if ((player->GetColader()->GetRealPosition().x >= (colader->GetRealPosition().x + colader->GetSize().x)) ||
                    ((player->GetColader()->GetRealPosition().x + player->GetColader()->GetSize().x) <= colader->GetRealPosition().x))
                {
                    if (player->GetColader()->GetRealPosition().x <= colader->GetRealPosition().x)
                    {
                        sprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));
                    }
                    else
                    {
                        sprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));
                    }
                }
            }
            else
            {
                if (player->GetColader()->GetRealPosition().y <= colader->GetRealPosition().y)
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));
                }
                else
                {
                    sprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
                }
            }
        }
    }
}


void NPC::Draw(bool draw) const
{
    if (draw)
    {
        if (player->GetSprite()->GetPixelPosition().y < sprite->GetPixelPosition().y)
        {
            sprite->Draw();

            if (debug == 1U)
            {
                colader->Draw();
            }
            
        }

        return;
    }

    sprite->Draw();

    if (debug == 1U)
    {
        colader->Draw();
    }
}
