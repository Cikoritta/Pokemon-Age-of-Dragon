#pragma once
#include "EazyConfig.h"
#include "SFML/Graphics.hpp"

class Plang
{
    static sf::String      m_currentLang;

public:

    Plang() = default;

    Plang(sf::String currentLang);

    
    static sf::String      GetString(sf::String id_string, sf::String scene);

    static void            SetLang(sf::String lang);

    static sf::String      GetLang();
};
