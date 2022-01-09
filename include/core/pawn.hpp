#ifndef PAWN_H
#define PAWN_H

#include "core/abstract_chess_piece.hpp"

class Pawn : public AbstractChessPiece
{
	protected:
		bool is_first_move;

	public:
		Pawn(): AbstractChessPiece(PAWN), is_first_move(true) {}
		Pawn(int x, int y, PieceColor c): AbstractChessPiece(PAWN, x, y, c), is_first_move(true) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
		void set_position(const Position& rhs) { is_first_move = false; this->pos = rhs;            }
		void set_position(int x, int y)        { is_first_move = false; this->pos = Position(x, y); }
};

#endif

