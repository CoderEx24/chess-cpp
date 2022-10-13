#include "ui/grid_renderer.hpp"

#include <iomanip>
#include <sstream>

void GridRenderer::render(tgui::Canvas::Ptr target)
{
	if (!this->state_changed)
		return;

	// draw the grid
	sf::Vector2f panel_size = target->getSize();
	sf::Vector2i tile_size = sf::Vector2i(panel_size.x / 8, panel_size.y / 8);

	sf::RectangleShape white_square(sf::Vector2f(panel_size.x / 8, panel_size.y / 8));
	white_square.setFillColor(sf::Color::Cyan);
	
	white_square.setPosition(0, 0);
	
	target->clear(sf::Color::Yellow);

	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
		{
			if ((i + j) % 2)
				continue;

			white_square.setPosition(tile_size.x * i, tile_size.y * j);
			target->draw(white_square);

		}

	FakeGrid grid = this->grid.get_fake_grid();

	sf::Text letters[6];
	sf::Font font;
	font.loadFromFile("/usr/share/fonts/TTF/Hack-Bold.ttf");

	letters[0].setString(sf::String("P"));
	letters[1].setString(sf::String("R"));
	letters[2].setString(sf::String("B"));
	letters[3].setString(sf::String("k"));
	letters[4].setString(sf::String("Q"));
	letters[5].setString(sf::String("K"));

	for (int i = 0; i < 6; i ++)
		letters[i].setFont(font);

	int piece_count = 0;
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
		{
			FakeChessPiece piece = grid[i][j];

			if (piece.data == 0x7ff)
				continue;

			piece_count ++;
			
			sf::Text text(letters[piece.type]);

			text.setFillColor((piece.color == WHITE) ? sf::Color::White : sf::Color::Black);
			text.setOutlineColor((piece.color == WHITE) ? sf::Color::Black : sf::Color::White);
			text.setOutlineThickness(2);
			text.setPosition(piece.y * tile_size.y,	piece.x * tile_size.x);

			target->draw(text);
		}


	target->display();
	state_changed = false;
}

