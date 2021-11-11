#ifndef GRID_H
#define GRID_H

#include "core/abstract_chess_piece.hpp"
#include "core/pawn.hpp"
#include "core/rook.hpp"
#include "core/bishop.hpp"
#include "core/knight.hpp"
#include "core/queen.hpp"
#include "core/king.hpp"

class Grid
{
	AbstractChessPiece *grid[8][8];
	bool occupied_positions[8][8];
	PieceColor current_turn;
	King *threatened_king, *white_king, *black_king;
	std::vector<Position> current_possible_moves;

	void init_grid();
	void check_king_for_threats();

	public:
		Grid(): current_turn(PieceColor::White), threatened_king(nullptr) { init_grid(); }
		Grid(PieceColor turn): current_turn(turn), threatened_king(nullptr) { init_grid(); }

		void update(int x, int y);
};

#endif

