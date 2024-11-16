#include "pch.h"
#include "Plang.h"

sf::String Plang::m_currentLang = "none";

Plang::Plang(sf::String currentLang)
{
    this->m_currentLang = currentLang;
}


sf::String Plang::GetString(sf::String id_string, sf::String scene)
{
    std::wstring test = L"Data/Lang/" + scene.toWideString() + L"/" + m_currentLang.toWideString() + L".Plang";

    return Config::Read(L"Data/Lang/" + scene.toWideString() + L"/" + m_currentLang.toWideString() + L".Plang", id_string.toWideString());
}
