#include "pch.h"
#include "Psound.h"
#include <EazyConfig.h>

Psound::Psound(sf::String path)
{
    buffer.loadFromFile(path);

    sound.setBuffer(buffer);
}

void Psound::PlayEffect()
{
    sound.setVolume(std::stof(Config::Read(L"Sound.ini", L"Music")));

    if (sound.getStatus() != sf::Sound::Playing)
    {
        sound.play();
    }
}

void Psound::SetPath(sf::String path)
{
    buffer.loadFromFile(path); 
    sound.setBuffer(buffer);
}

sf::Sound* Psound::GetSound()
{
    return &sound;
}
