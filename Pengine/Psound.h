#pragma once
#include <SFML/Audio.hpp>

class Psound
{
    sf::SoundBuffer        buffer;

    sf::Sound              sound;

public:

    Psound() = default;

    Psound(sf::String path);


    void                    PlayEffect();

    void                    SetPath(sf::String path);

    sf::Sound*              GetSound();
};
