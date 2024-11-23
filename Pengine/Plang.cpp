#include "pch.h"
#include "Plang.h"

sf::String Plang::m_currentLang = "none";

Plang::Plang(sf::String currentLang)
{
    this->m_currentLang = currentLang;
}


sf::String Plang::GetString(sf::String id_string, sf::String scene)
{
    std::wstring string = Config::Read(L"Data/Lang/" + scene.toWideString() + L"/" + m_currentLang.toWideString() + L".Plang", id_string.toWideString());

    while (string.find(L"&") != string.npos)
    {
        string.replace(string.find(L"&"), 1, L"\n");
    }

    return string;
}

void Plang::SetLang(sf::String lang)
{
    m_currentLang = lang;
}

sf::String Plang::GetLang()
{
    return m_currentLang;
}
