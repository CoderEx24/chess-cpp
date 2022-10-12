#include "ui/grid_renderer.hpp"

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

	letters[0].setString(sf::String("P"));
	letters[1].setString(sf::String("R"));
	letters[2].setString(sf::String("B"));
	letters[3].setString(sf::String("k"));
	letters[4].setString(sf::String("Q"));
	letters[5].setString(sf::String("K"));

	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
		{
			FakeChessPiece piece = grid[i][j];

			if (piece.color == -1)
				continue;

			std::cout << "Piece type = " << piece.type << '\n';
			sf::Text text = letters[piece.type];
			text.setColor((piece.color == WHITE) ? sf::Color::White : sf::Color::Black);
			text.setPosition(piece.x * tile_size.x, piece.y * tile_size.y);

			target->draw(text);
		}

	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)


	target->display();
	state_changed = false;
}

