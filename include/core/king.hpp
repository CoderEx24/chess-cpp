#ifndef KING_H
#define KING_H

#include "core/abstract_chess_piece.hpp"

class King : public AbstractChessPiece
{
	public:
		King(): AbstractChessPiece() {}
		King(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		const std::vector<Position>& get_valid_positions(bool **occupied_positions) override;
};

#endif

