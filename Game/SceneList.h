#pragma once
#include <vector>
#include <Pscene.h>

class SceneList
{
    static std::vector<Pscene*> scenes;

public:

    static void AddScene(Pscene* scene);

    static Pscene* GetScene(sf::String name);
};