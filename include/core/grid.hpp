#ifndef GRID_H
#define GRID_H


#include "core/abstract_chess_piece.hpp"
#include "core/pawn.hpp"
#include "core/rook.hpp"
#include "core/bishop.hpp"
#include "core/knight.hpp"
#include "core/queen.hpp"
#include "core/king.hpp"

#include <unordered_map>
#include <vector>

using PlaceCommand = uint16_t;

class Grid
{
	protected:
		AbstractChessPiece ***grid;
		FakeGrid fake_grid;
		bool game_over;
		PieceColor current_turn, winner;
		King *threatened_king, *white_king, *black_king;
        std::unordered_map<Position, std::vector<Position>> current_possible_moves;
        std::vector<AbstractChessPiece*> *white_pieces, *black_pieces;

		void init_grid();

	public:
		Grid(): current_turn(WHITE), threatened_king(nullptr) { init_grid(); }
		Grid(PieceColor turn): current_turn(turn), threatened_king(nullptr) { init_grid(); }
		Grid(PlaceCommand *commands, int size);
        ~Grid();

		inline static PlaceCommand encode(Position pos, PieceType type, PieceColor color)
        {
            return pos.x |
                (pos.y << 3) |
                (type << 6) |
                ((color - 1) << 9);
        }

        inline static void decode(PlaceCommand cmd, Position& pos, PieceType& type, PieceColor& color)
        {
            pos   = Position(cmd & 0b111, (cmd & 0b111000) >> 3);
            type  = (cmd & 0b111000000) >> 6;
            color = 1 + ((cmd & 0b1000000000) >> 9);
        }

		bool is_game_over() const { return game_over; }
		PieceColor get_winner() const { return winner; }
		FakeGrid get_fake_grid() const { return fake_grid; }

		bool move(const Position& piece, const Position& dest);
		const std::vector<Position>& get_possible_moves(const Position& piece);

};

#endif

