#include "Player.h" 

Player::Player(sf::RenderWindow* window, sf::Event* event)
{
    this->window = window;

    this->event = event;

    playerSprite = new PanimatedSprite(window, event, "Data/Textures/Entites/Player/walk.png", new sf::IntRect(0, 0, 16, 23));

    speed.x = 5.0f * std::stof(Config::Read(L"Config.ini", L"windowScaleWidth"));
    speed.y = 5.0f * std::stof(Config::Read(L"Config.ini", L"windowScaleHeight"));

    playerSprite->SetPosition({ 0.5f, 0.5f });
    playerSprite->SetScale({ 4.6f, 4.6f });
    playerSprite->SetLoop(true);
    playerSprite->SetFrameTime(0.2f);

    colader = new Pcolader(window, event, playerSprite->GetPosition(), { playerSprite->GetSize().x * 1.25f,  playerSprite->GetSize().y / 2.0f }, "player");

    colader->SetOrigin({ -0.1f, -1.75f });

    colader->SetSprite(playerSprite);

    camera.setSize(static_cast<sf::Vector2f>(window->getSize()));

    playerOrigin = (playerSprite->GetSize() / 2.0f);

    camera.setCenter(playerSprite->GetPixelPosition() + playerOrigin);

    window->setView(camera);
}


Pcolader* Player::GetColader() const
{
    return colader;
}

PanimatedSprite* Player::GetSprite()
{
    return playerSprite;
}


void Player::Collision(std::vector<Pcolader*> solidColader)
{
    this->solidColader = solidColader;

    for (sf::Uint16 i = 0; i < solidColader.size(); i++)
    {
        colader->IsColision(solidColader[i]);
    }
}

void Player::Update()
{
    sf::Vector2f position = playerSprite->GetPixelPosition();

    if (!isWalking && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        playerSprite->GetSprite()->move(0.0f, -speed.y);

        colader->SetPixelPosition(playerSprite->GetPixelPosition());

        if (playerSprite->GetSprite()->getTextureRect().top != 23)
        {
            playerSprite->GetSprite()->setTextureRect(sf::IntRect(0, 23, 16, 23));
        }

        isWalkingY = true;
    }

    if (!isWalking && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        playerSprite->GetSprite()->move(0.0f, speed.y);

        colader->SetPixelPosition(playerSprite->GetPixelPosition());

        if (playerSprite->GetSprite()->getTextureRect().top != 0)
        {
            playerSprite->GetSprite()->setTextureRect(sf::IntRect(0, 0, 16, 23));
        }
        
        isWalkingY = true;
    }

    if (!isWalkingY && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        playerSprite->GetSprite()->move(-speed.x, 0.0f);

        colader->SetPixelPosition(playerSprite->GetPixelPosition());

        if (playerSprite->GetSprite()->getTextureRect().top != 46)
        {
            playerSprite->GetSprite()->setTextureRect(sf::IntRect(0, 46, 16, 23));
        }
        
        isWalking = true;
    }

    if (!isWalkingY && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        playerSprite->GetSprite()->move(speed.x, 0.0f);

        colader->SetPixelPosition(playerSprite->GetPixelPosition());

        if (playerSprite->GetSprite()->getTextureRect().top != 69)
        {
            playerSprite->GetSprite()->setTextureRect(sf::IntRect(0, 69, 16, 23));
        }
        
        isWalking = true;
    }


    if (isWalking)
    {
        playerSprite->Animate(16, 16, 0);
    }

    if (isWalkingY)
    {
        playerSprite->Animate(16, 16, 16);
    }

    camera.setCenter(playerSprite->GetPixelPosition() + playerOrigin);

    window->setView(camera);
}

void Player::Events()
{
    if (Pinput::IsKeyReleased(sf::Keyboard::A) || Pinput::IsKeyReleased(sf::Keyboard::D))
    {
        isWalking = false;

        playerSprite->GetSprite()->setTextureRect(sf::IntRect(16, playerSprite->GetSprite()->getTextureRect().top, 16, 23));
    }
    else if (Pinput::IsKeyReleased(sf::Keyboard::W) || Pinput::IsKeyReleased(sf::Keyboard::S))
    {
        isWalkingY = false;

        playerSprite->GetSprite()->setTextureRect(sf::IntRect(0, playerSprite->GetSprite()->getTextureRect().top, 16, 23));
    }
}

void Player::Draw() const
{
    playerSprite->Draw();

    if (debug)
    {
        colader->Draw();
    }
}
