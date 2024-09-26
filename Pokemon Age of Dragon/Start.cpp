#include "Window.h"
#include "MainMenu.h"

int main()
{
	Window::setIcon(new Icon("Data/Textures/Icon/icon.png"));

	Window::setStartScene(new MainMenu());

	Window::create(File::Read::int_read("Data/Configs/window.peconf", "create_size.x"), File::Read::int_read("Data/Configs/window.peconf", "create_size.y"), File::Read::wstring_read(Window::getLanguage(), L"window_title"), File::Read::int_read("Data/Configs/window.peconf", "style"));
}
