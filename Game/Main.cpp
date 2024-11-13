#include <Pengine.h>

class MyScene : public Pscene
{
	Pcolader colader = Pcolader(window, event, { 0.2f, 0.5f }, { 100, 100 }, "colader");

    Pcolader colader2 = Pcolader(window, event, { 0.8f, 0.5f }, { 100, 100 }, "colader_2");

public:

    MyScene() = default;

    MyScene(sf::RenderWindow* window, sf::Event* event) : Pscene(window, event) {}


    void Start() override
    {
		colader.SetOrigin(sf::Vector2f(0.5f, 0.5f));

		colader2.SetOrigin(sf::Vector2f(0.5f, 0.5f));

		colader2.SetSolid(true);

        Pinput::SetWindow(window, event);
    }

    void Update() override
    {
        colader.IsColision(&colader2);
    }

    void Events() override
    {
        if (Pinput::IsMouseCollision(&colader))
        {
            if (Pinput::IsMouseUpdatePressed(sf::Mouse::Left))
            {
                colader.SetPixelPosition(sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y));
            }
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::W))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x, colader.GetPixelPosition().y - 1.0f));
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::S))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x, colader.GetPixelPosition().y + 1.0f));
        }

		if (Pinput::IsKeyPressed(sf::Keyboard::A))
		{
			colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x - 1.0f, colader.GetPixelPosition().y));
		}

        if (Pinput::IsKeyPressed(sf::Keyboard::D))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x + 1.0f, colader.GetPixelPosition().y));
        }
    }

    void Draw() const override
	{
        colader2.Draw();
        colader.Draw();
    }

};

int main()
{ 
    Config::OnLog(true);

    Pwindow window(sf::VideoMode(200U, 200U), "Pengine", 7U, "Config.ini");

	window.GetSceneManager()->SetCurrentScene(new MyScene(&window, window.GetEvent()));

    window.GetSceneManager()->RenderScene();
}