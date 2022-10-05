#include <SFML/Window/WindowStyle.hpp>
#include <TGUI/TGUI.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Chess", sf::Style::Titlebar);
	tgui::GuiSFML gui(window);
	
	auto button = tgui::Button::create("Play");
	button->setSize(200, 79);
	button->setPosition("50%", "67%");
	button->setOrigin(0.5f, 0.5f);

	gui.add(button);

	auto game_title = tgui::Label::create("Chess");
	game_title->setTextSize(20);
	game_title->setPosition("50%", "33%");
	game_title->setOrigin(0.5f, 0.5f);

	gui.add(game_title);

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			gui.handleEvent(evt);

			if (evt.type == sf::Event::Closed ||
				(evt.type == sf::Event::KeyPressed && evt.key.code == sf::Keyboard::Escape))
				window.close();
		}

		window.clear(sf::Color(0xffeeff));
		gui.draw();
		window.display();
	}
}
