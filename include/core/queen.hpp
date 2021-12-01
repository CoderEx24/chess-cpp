#ifndef QUEEN_H
#define QUEEN_H

#include "core/abstract_chess_piece.hpp"

class Queen : public AbstractChessPiece
{
	public:
		Queen(): AbstractChessPiece() {}
		Queen(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		const std::vector<Position>& get_valid_positions(PieceColor **occupied_positions) override;
};

#endif

