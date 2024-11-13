#pragma once
#include "Psprite.h"

class PsplitSprite : public Psprite
{
    sf::Sprite topLeft;
    sf::Sprite top;
    sf::Sprite topRight;

    sf::Sprite left;
    sf::Sprite right;

    sf::Sprite bottomLeft;
    sf::Sprite bottom;
    sf::Sprite bottomRight;

    sf::Vector2u pixelOrigin = sf::Vector2u(0U, 0U);

    Psprite* relativeSprite = nullptr;

public:

    PsplitSprite() = default;

    PsplitSprite(sf::RenderWindow* window, sf::Event* event, sf::String texturePath, sf::IntRect* textureRect[9]) : Psprite(window, event, texturePath, textureRect[4])
    {
        if (texturePath != "none")
        {
            texture.loadFromFile(texturePath);

            topLeft.setTexture(texture);
            top.setTexture(texture);
            topRight.setTexture(texture);

            left.setTexture(texture);
            right.setTexture(texture);

            bottomLeft.setTexture(texture);
            bottom.setTexture(texture);
            bottomRight.setTexture(texture);


            topLeft.setTextureRect(*textureRect[0]);
            top.setTextureRect(*textureRect[1]);
            topRight.setTextureRect(*textureRect[2]);

            left.setTextureRect(*textureRect[3]);
            right.setTextureRect(*textureRect[5]);

            bottomLeft.setTextureRect(*textureRect[6]);
            bottom.setTextureRect(*textureRect[7]);
            bottomRight.setTextureRect(*textureRect[8]);
        }
    }


    void SetTexture(const sf::String texturePath, sf::IntRect* textureRect[9]);


    sf::Vector2u GetPixelPosition() const override;

    void SetPosition(float x, float y, Psprite* RelativeSprite = nullptr) override;

    void SetPixelPosition(sf::Uint16 x, sf::Uint16 y) override;


    void SetScale(float x, float y) override;

    void SetSmartScale(float x, float y);

    void SetBorderScale(float x, float y);


    virtual  sf::Vector2u GetPixelOrigin() const override;

    virtual void SetOrigin(float x, float y, bool local = false) override;


    virtual sf::Vector2u GetSize(bool local = false) const override;

    virtual sf::IntRect GetBounds(bool local = false) const override;


    virtual void Draw() const override;
};
