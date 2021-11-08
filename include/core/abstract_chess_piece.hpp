#ifndef ABSTRACT_CHESS_PIECE_H
#define ABSTRACT_CHESS_PIECE_H

enum PieceColor { Black, White };

struct Position
{
	int x, y;
	Position(): x(0), y(0) {}
	Position(int x, int y): x(x), y(y) {}
	Position(const Position& obj): x(obj.x), y(obj.y) {}
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

		void set_position(Position pos) { this->pos = pos; }
		void set_position(int x, int y) { this->pos = Position(x, y); }

		Position get_position() const { return this->pos; }
		PieceColor get_color() const { return this->color; }

		virtual bool is_valid_position(bool **occupied_positions) = 0;

};

#endif
