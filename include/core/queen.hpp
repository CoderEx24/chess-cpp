#ifndef QUEEN_H
#define QUEEN_H

#include "core/abstract_chess_piece.hpp"

class Queen : public AbstractChessPiece
{
	public:
		Queen(): AbstractChessPiece(QUEEN) {}
		Queen(int x, int y, PieceColor c): AbstractChessPiece(QUEEN, x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
};

#endif

