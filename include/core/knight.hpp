#ifndef KNIGHT_H
#define KNIGHT_H

#include "core/abstract_chess_piece.hpp"

class Knight : public AbstractChessPiece
{
	public:
		Knight(): AbstractChessPiece(KNIGHT) {}
		Knight(int x, int y, PieceColor c): AbstractChessPiece(KNIGHT, x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
};

#endif

