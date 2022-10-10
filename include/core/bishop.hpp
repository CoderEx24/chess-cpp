#ifndef BISHOP_H
#define BISHOP_H

#include "core/abstract_chess_piece.hpp"

class Bishop : public AbstractChessPiece
{
	public:
		Bishop(): AbstractChessPiece(BISHOP) {}
		Bishop(int x, int y, PieceColor c): AbstractChessPiece(BISHOP, x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
};

#endif

