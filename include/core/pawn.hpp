#ifndef PAWN_H
#define PAWN_H

#include "core/abstract_chess_piece.hpp"

class Pawn : public AbstractChessPiece
{
	protected:
		bool is_first_move;

	public:
		Pawn(): AbstractChessPiece(), is_first_move(true) {}
		Pawn(int x, int y, PieceColor c): AbstractChessPiece(x, y, c), is_first_move(true) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;

};

#endif

