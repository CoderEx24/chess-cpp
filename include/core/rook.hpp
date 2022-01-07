#ifndef ROOK_H
#define ROOK_H

#include "core/abstract_chess_piece.hpp"

#ifdef QUEEN_EZ_IMP
#include "core/queen.hpp"
#endif

class Rook : public AbstractChessPiece
{
	public:
		Rook(): AbstractChessPiece() {}
		Rook(int x, int y, PieceColor c): AbstractChessPiece(x, y, c) {}

		const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) override;
#ifdef QUEEN_EZ_IMP
	friend class Queen;
#endif
};

#endif

