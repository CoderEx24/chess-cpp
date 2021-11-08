#ifndef ROOK_H
#define ROOK_H

#include "abstract_chess_piece.hpp"

class Rook : public AbstractChessPiece
{
	public:
		Rook(): AbstractChessPiece() {}
		Rook(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		bool is_valid_position(bool **occupied_positions);
};

#endif

