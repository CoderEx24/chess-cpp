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
	FakeGrid grid = new PieceColor*[8];

	for (int i = 0; i < 8; i ++) 
	{
		if (i == 6 || i == 7)
			grid[i] = new PieceColor[8] {WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE};
		else if (i == 0 || i == 1)
			grid[i] = new PieceColor[8] {BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK};
		else
			grid[i] = new PieceColor[8] {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY};
	}

	return grid;
}

#endif
