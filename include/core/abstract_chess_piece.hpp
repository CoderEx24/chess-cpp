#ifndef ABSTRACT_CHESS_PIECE_H
#define ABSTRACT_CHESS_PIECE_H

#include <vector>

#define EMPTY 0
#define WHITE 1
#define BLACK 2

#define PAWN 	0x0
#define ROOK 	0x1
#define BISHOP 	0x2
#define KNIGHT 	0x3
#define QUEEN 	0x4
#define KING 	0x5

using PieceColor = unsigned short;
using PieceType  = unsigned short;

struct Position
{
	int x, y;
	Position(): x(0), y(0) {}
	Position(int x, int y): x(x), y(y) {}

	bool operator==(const Position& rhs) { return x == rhs.x && y == rhs.y; }
	bool operator!=(const Position& rhs) { return x != rhs.x || y != rhs.y; }
};

class AbstractChessPiece
{
	protected:
		PieceColor color;
		Position pos;

	public:
		AbstractChessPiece() {}
		AbstractChessPiece(int x, int y, PieceColor c): color(c), pos(x, y) {}
		AbstractChessPiece(const AbstractChessPiece& obj): color(obj.color), pos(obj.pos) {}

  	 	void set_position(const Position& pos) { this->pos = pos; }
		void set_position(int x, int y) { this->pos = Position(x, y); }

		const Position& get_position() const { return this->pos; }
		PieceColor get_color() const { return this->color; }
		
		// this function should return a list of absolute positions that the chess piece can occupy
		virtual const std::vector<Position>& get_valid_positions(PieceColor **occupied_positions) = 0;

	friend class FakeChessPiece;
};

class FakeChessPiece
{
	const AbstractChessPiece *piece;
	PieceType type;

	public:
		FakeChessPiece(const AbstractChessPiece *p);

		PieceType get_type() const { return type; }
		PieceColor get_color() const { return piece->color; }
		const Position& get_position() const { return piece->pos; }
		
		bool is_valid();
};

#endif
