#ifndef KING_H
#define KING_H

#include "abstract_chess_piece.hpp"

class King : public AbstractChessPiece
{
	public:
		King(): AbstractChessPiece() {}
		King(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		std::vector<Position> get_valid_positions(bool **occupied_positions) override;
};

#endif

