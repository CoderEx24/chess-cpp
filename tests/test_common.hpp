#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <CppUTest/SimpleString.h>
#include <string>
#include "core/abstract_chess_piece.hpp"

inline SimpleString StringFrom(const Position& pos)
{
	std::string str = "(" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ")";
	return SimpleString(str.data());
}

inline FakeGrid init_grid()
{
	FakeGrid grid = new FakeChessPiece*[8];

	for (int i = 0; i < 8; i ++)
		grid[i] = new FakeChessPiece[8];

	for (int i = 0; i < 8; i ++)
	{
		grid[1][i] = encode_piece(BLACK, PAWN, 1, i );
		grid[6][i] = encode_piece(WHITE, PAWN, 6, i);
	}

	grid[0][0] = encode_piece(BLACK, ROOK, 0, 0);
	grid[0][7] = encode_piece(BLACK, ROOK, 0, 7);

	grid[7][0] = encode_piece(WHITE, ROOK, 7, 0);
	grid[7][7] = encode_piece(WHITE, ROOK, 7, 7);

	grid[0][1] = encode_piece(BLACK, KNIGHT, 0, 1);
	grid[0][6] = encode_piece(BLACK, KNIGHT, 0, 6);

	grid[7][1] = encode_piece(BLACK, KNIGHT, 7, 1);
	grid[7][6] = encode_piece(BLACK, KNIGHT, 7, 6);

	grid[0][2] = encode_piece(BLACK, BISHOP, 0, 2);
	grid[0][5] = encode_piece(BLACK, BISHOP, 0, 5);

	grid[7][2] = encode_piece(WHITE, BISHOP, 7, 2);
	grid[7][5] = encode_piece(WHITE, BISHOP, 7, 5);

	grid[0][3] = encode_piece(BLACK, QUEEN, 0, 3);
	grid[0][4] = encode_piece(BLACK, KING, 0, 4);

	grid[7][3] = encode_piece(BLACK, QUEEN, 7, 3);
	grid[7][4] = encode_piece(BLACK, KING, 7, 4);


	return grid;
}

#endif
