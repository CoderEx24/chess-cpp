#ifndef ROOK_H
#define ROOK_H

#include "core/abstract_chess_piece.hpp"

class Rook : public AbstractChessPiece
{
	public:
		Rook(): AbstractChessPiece() {}
		Rook(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		const std::vector<Position>& get_valid_positions(bool **occupied_positions) override;
};

#endif

