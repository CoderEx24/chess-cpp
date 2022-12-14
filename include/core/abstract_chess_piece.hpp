#ifndef ABSTRACT_CHESS_PIECE_H
#define ABSTRACT_CHESS_PIECE_H

#include <string>
#include <vector>
#include <cmath>

#define EMPTY 0
#define WHITE 1
#define BLACK 2

#define PAWN 	0x0
#define ROOK 	0x1
#define BISHOP 	0x2
#define KNIGHT 	0x3
#define QUEEN 	0x4
#define KING 	0x5

#define OPPOSITE_COLOR(c) ((c == WHITE) ? BLACK : WHITE)

using PieceColor = unsigned short;
using PieceType  = unsigned short;

union FakeChessPiece
{
	struct
	{
		PieceColor color: 2;
		PieceType type: 3;
		unsigned int x: 3;
		unsigned int y: 3;
	};
	
	uint16_t data: 11;

	FakeChessPiece operator=(int rhs)
	{
		this->data = rhs;
		return *this;
	}
};

inline uint16_t encode_piece(PieceColor color, PieceType type, int x, int y)
{
	return color |
		(type << 2) |
		(x << 5) |
		(y << 8);
}

using FakeGrid   = FakeChessPiece**;

struct Position
{
	int x, y;
	Position(): x(0), y(0) {}
	Position(int x, int y): x(x), y(y) {}
	Position(const std::string&);
	
    	float len() const { return sqrt(pow(this->x, 2) + pow(this->y, 2)); }

	bool operator==(const Position& rhs) const { return x == rhs.x && y == rhs.y; }
	bool operator!=(const Position& rhs) const { return x != rhs.x || y != rhs.y; }
	Position operator+(const Position& rhs) const { return Position(this->x + rhs.x, this->y + rhs.y); }
	Position operator-(const Position& rhs) const { return *this + (rhs * -1); }
	Position operator*(float a) const { return Position(a * this->x, a * this->y); }

    std::string to_string() const;
};

inline uint16_t encode_piece(PieceColor color, PieceType type, Position pos)
{
	return encode_piece(color, type, pos.x, pos.y);
}

std::ostream& operator<<(std::ostream&, const Position&);

template<> struct std::hash<Position>
{
    std::size_t operator()(const Position&) const;
};

inline bool in_bounds(const Position& point)
{
	return point.x >= 0 && point.x < 8 && point.y >= 0 && point.y < 8;
}

class AbstractChessPiece
{
	protected:
		PieceType type;
		PieceColor color;
		Position pos;
		std::vector<Position> possible_moves;

	public:
		AbstractChessPiece(PieceType t): type(t) {}
		AbstractChessPiece(PieceType t, int x, int y, PieceColor c): type(t), color(c), pos(x, y) {}
		AbstractChessPiece(PieceType t, const AbstractChessPiece& obj): type(t), color(obj.color), pos(obj.pos) {}
	        virtual ~AbstractChessPiece() { this->possible_moves.clear(); };

  	 	void set_position(const Position& pos) { this->pos = pos; }
		void set_position(int x, int y) { this->pos = Position(x, y); }

		const Position& get_position() const { return this->pos; }
		PieceColor get_color() const { return this->color; }
		PieceType  get_type() const { return this->type; }

		// this function should return a list of absolute positions that the chess piece can occupy
		virtual const std::vector<Position>& get_valid_positions(FakeGrid occupied_positions) = 0;

};

inline uint16_t encode_piece(const AbstractChessPiece* piece)
{
	return (piece) ? encode_piece(piece->get_color(), piece->get_type(), piece->get_position()) : encode_piece(-1, 0, 0, 0);
}

#endif
