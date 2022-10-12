#include <SFML/Window/WindowStyle.hpp>
#include <TGUI/TGUI.hpp>
#include "ui/grid_renderer.hpp"

int main()
{
	bool started_game = false;
	
	GridRenderer grid_render;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Chess", sf::Style::Titlebar);
	tgui::GuiSFML gui(window);

	auto main_screen_group = tgui::Group::create();
	
	auto button = tgui::Button::create("Play");
	button->setSize(200, 70);
	button->setPosition("50%", "67%");
	button->setOrigin(0.5f, 0.5f);

	auto grid_group = tgui::Group::create();
	grid_group->setVisible(false);

	auto play_onpress = [&main_screen_group, &grid_group, &started_game]()
	{
		started_game = true;
		main_screen_group->setVisible(false);
		grid_group->setVisible(true);
	};

	button->onPress(play_onpress);
	main_screen_group->add(button);

	auto game_title = tgui::Label::create("Chess");
	game_title->setTextSize(20);
	game_title->setPosition("50%", "33%");
	game_title->setOrigin(0.5f, 0.5f);

	main_screen_group->add(game_title);

	auto panel = tgui::Canvas::create();

	grid_group->add(panel);

	gui.add(main_screen_group);
	
	gui.add(grid_group);

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			gui.handleEvent(evt);

			if (evt.type == sf::Event::Closed ||
				(evt.type == sf::Event::KeyPressed && (evt.key.code == sf::Keyboard::Escape || evt.key.code == sf::Keyboard::Q)))
				window.close();
		}

		window.clear(sf::Color(0xfffeff));

		if (started_game)
		{
			grid_render.render(panel);			
		}
		
		gui.draw();
		window.display();
	}
}
