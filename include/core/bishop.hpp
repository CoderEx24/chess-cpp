#ifndef BISHOP_H
#define BISHOP_H

#include "core/abstract_chess_piece.hpp"

#ifdef QUEEN_EZ_IMP
#include "core/queen.hpp"
#endif

class Bishop : public AbstractChessPiece
{
	public:
		Bishop(): AbstractChessPiece() {}
		Bishop(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		const std::vector<Position>& get_valid_positions(PieceColor **occupied_positions) override;
#ifdef QUEEN_EZ_IMP
	friend class Queen;
#endif	
};

#endif

