#include "pch.h"
#include "Pmusic.h"
#include <EazyConfig.h>

Pmusic::Pmusic(sf::String path)
{
    music.openFromFile(path);
}

void Pmusic::PlayMusic(bool loop)
{
    music.setLoop(loop);

    music.setVolume(std::stof(Config::Read(L"Sound.ini", L"Music")));

    if (!music.getStatus() != sf::Music::Playing)
    {
        music.play();
    }
}

void Pmusic::SetPath(sf::String path)
{
    music.openFromFile(path);
}

sf::Music* Pmusic::GetMusic()
{
    return &music;
}
