#ifndef BISHOP_H
#define BISHOP_H

#include "core/abstract_chess_piece.hpp"

class Bishop : public AbstractChessPiece
{
	public:
		Bishop(): AbstractChessPiece() {}
		Bishop(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		std::vector<Position> get_valid_positions(bool **occupied_positions) override;
		
};

#endif

