#include "ui/grid_renderer.hpp"

void GridRenderer::render(tgui::Canvas::Ptr target)
{
	if (!this->state_changed)
		return;

	// draw the grid
	sf::Vector2f panel_size = target->getSize();
	sf::Vector2i tile_size = sf::Vector2i(panel_size.x / 8, panel_size.y / 8);

	sf::RectangleShape white_square(sf::Vector2f(panel_size.x / 8, panel_size.y / 8));
	white_square.setFillColor(sf::Color::White);
	
	white_square.setPosition(0, 0);
	
	target->clear();

	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
		{
			if ((i + j) % 2)
				continue;

			white_square.setPosition(tile_size.x * i, tile_size.y * j);
			target->draw(white_square);

		}

	target->display();
	state_changed = false;
}

