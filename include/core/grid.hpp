#ifndef GRID_H
#define GRID_H

#include "core/abstract_chess_piece.hpp"
#include "core/pawn.hpp"
#include "core/rook.hpp"
#include "core/bishop.hpp"
#include "core/knight.hpp"
#include "core/queen.hpp"
#include "core/king.hpp"

using PlaceCommand = uint16_t;

class Grid
{
	protected:
		AbstractChessPiece ***grid;
		FakeGrid fake_grid;
		bool game_over;
		PieceColor current_turn, winner;
		King *threatened_king, *white_king, *black_king;
		std::vector<Position> current_possible_moves;

		void init_grid() {};

	public:
		Grid(): current_turn(WHITE), threatened_king(nullptr) { init_grid(); }
		Grid(PieceColor turn): current_turn(turn), threatened_king(nullptr) { init_grid(); }
		Grid(PlaceCommand *commands, int size);
		
		inline static PlaceCommand encode(Position pos, PieceType type, PieceColor color);
		bool is_game_over() const { return game_over; }
		PieceColor get_winner() const { return winner; }
		FakeGrid get_fake_grid() const { return fake_grid; }

		void move(const Position& piece, const Position& dest);
		const std::vector<Position>& get_possible_moves(const Position& piece);
				
};

#endif

