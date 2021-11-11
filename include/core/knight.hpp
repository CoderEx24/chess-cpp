#ifndef KNIGHT_H
#define KNIGHT_H

#include "core/abstract_chess_piece.hpp"

class Knight : public AbstractChessPiece
{
	public:
		Knight(): AbstractChessPiece() {}
		Knight(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		std::vector<Position> get_valid_positions(bool **occupied_positions) override;
};

#endif

