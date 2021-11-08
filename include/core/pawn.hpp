#ifndef PAWN_H
#define PAWN_H

#include "abstract_chess_piece.hpp"

class Pawn : public AbstractChessPiece
{
	bool is_first_move;

	public:
		Pawn(): AbstractChessPiece(), is_first_move(true) {}
		Pawn(int x, int y, PieceColor c): AbstractChessPiece(x, y, c), is_first_move(true) {}

		bool is_valid_position(bool **occupied_positions);

};

#endif

