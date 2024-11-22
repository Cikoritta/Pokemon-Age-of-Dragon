#pragma once
#include <SFML/Audio.hpp>

class Pmusic
{
    sf::Music               music;

public:

    Pmusic() = default;

    Pmusic(sf::String path);


    void                    PlayMusic(bool loop = false);

    void                    SetPath(sf::String path);

    sf::Music*              GetMusic();
};
