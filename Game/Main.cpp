#include <Pengine.h>

class MyScene : public Pscene
{
	Pcolader colader = Pcolader(window, event, { 0.2f, 0.5f }, { 100, 100 }, "colader");

    Pcolader colader2 = Pcolader(window, event, { 0.8f, 0.5f }, { 100, 100 }, "colader_2");

    Psprite sprite = Psprite(window, event, "image.png", new sf::IntRect(0, 0, 200, 200));

    PanimatedSprite sprite2 = PanimatedSprite(window, event, "image.png", new sf::IntRect(0, 0, 200, 200));

public:

    MyScene() = default;

    MyScene(sf::RenderWindow* window, sf::Event* event) : Pscene(window, event) {}


    void Start() override
    {
		colader.SetOrigin(sf::Vector2f(0.5f, 0.5f));

		colader2.SetOrigin(sf::Vector2f(0.5f, 0.5f));

		colader2.SetSolid(true);

        sprite.SetOrigin(0.5f, 0.5f);
        sprite2.SetOrigin(0.5f, 0.5f);

        sprite2.SetFrameTime(0.1f);

        sprite2.SetLoop(true);

        colader.SetSprite(&sprite);
        colader2.SetSprite(&sprite2);

        Pinput::SetWindow(window, event);
    }

    void Update() override
    {
        sprite2.Animate(200U);

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

        if (Pinput::IsMouseCollision(&colader2))
        {
            if (Pinput::IsMouseUpdatePressed(sf::Mouse::Left))
            {
                colader2.SetPixelPosition(sf::Vector2f(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y));
            }
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::W))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x, colader.GetPixelPosition().y - 5.0f));
        }

        if (Pinput::IsKeyPressed(sf::Keyboard::S))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x, colader.GetPixelPosition().y + 5.0f));
        }

		if (Pinput::IsKeyPressed(sf::Keyboard::A))
		{
			colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x - 5.0f, colader.GetPixelPosition().y));
		}

        if (Pinput::IsKeyPressed(sf::Keyboard::D))
        {
            colader.SetPixelPosition(sf::Vector2f(colader.GetPixelPosition().x + 5.0f, colader.GetPixelPosition().y));
        }
    }

    void Draw() const override
	{
        sprite2.Draw();
        sprite.Draw();

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