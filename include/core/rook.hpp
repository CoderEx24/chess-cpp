#ifndef ROOK_H
#define ROOK_H

#include "core/abstract_chess_piece.hpp"

class Rook : public AbstractChessPiece
{
	public:
		Rook(): AbstractChessPiece(ROOK) {}
		Rook(int x, int y, PieceColor c): AbstractChessPiece(ROOK, x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
};

#endif

