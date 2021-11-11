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
	std::vector<FakeChessPiece*> fake_pieces_list;
	bool occupied_positions[8][8], game_over;
	PieceColor current_turn, winner;
	King *threatened_king, *white_king, *black_king;
	std::vector<Position> current_possible_moves;

	void init_grid();
	void check_king_for_threats();

	public:
		Grid(): current_turn(WHITE), threatened_king(nullptr) { init_grid(); }
		Grid(PieceColor turn): current_turn(turn), threatened_king(nullptr) { init_grid(); }

		bool is_game_over() const { return game_over; }
		PieceColor get_winner() const { return winner; }
		const std::vector<FakeChessPiece*> get_fake_piece_list() const { return fake_pieces_list; }

		void move(const Position& piece, const Position& dest);
		const std::vector<Position>& get_possible_moves(const Position& piece);
				
};

#endif

