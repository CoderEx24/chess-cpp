#ifndef KING_H
#define KING_H

#include "core/abstract_chess_piece.hpp"

class King : public AbstractChessPiece
{
	public:
		King(): AbstractChessPiece(KING) {}
		King(int x, int y, PieceColor c): AbstractChessPiece(KING, x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
};

#endif

