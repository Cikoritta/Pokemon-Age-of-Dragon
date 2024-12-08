#include "SceneList.h"

std::vector<Pscene*> SceneList::scenes;

void SceneList::AddScene(Pscene* scene)
{
    scenes.push_back(scene);
}

Pscene* SceneList::GetScene(sf::String name)
{
    for (sf::Uint16 numberScene = 0; numberScene < scenes.size(); numberScene++)
    {
        if (*scenes[numberScene]->GetSceneName() == name)
        {
            return scenes[numberScene];
        }
    }

    printf("Scene not found - %s\n", name.toAnsiString().c_str());
}
