#include <CppUTest/TestHarness.h>
#include "core/king.hpp"
#include "test_common.hpp"

// The King test case
// the king is like the queen, it can move in any direction.
// However, the king can only move one square
//
// 8 1 2
//  \|/
// 7-K-3
//  /|\
// 6 5 4

TEST_GROUP(TestKing)
{
	FakeGrid occupied_positions;


	void setup()
	{
		occupied_positions = (FakeGrid) new PieceColor [8][8] {
			{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
			{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
			{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
			{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
		};
	}

	void teardown()
	{
		for(int i = 0; i < 8; i ++)
			delete[] occupied_positions[i];
		delete[] occupied_positions;
	}


};

TEST(TestKing, test_at_initial_position)
{
	// testing white king
	King white_king(7, 4, WHITE);

	std::vector<Position> possible_moves(white_king.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 0);

	// testing black king
	King black_king(0, 4, BLACK);

	possible_moves = black_king.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 0);
}

TEST(TestKing, test_case_1)
{
	// testing white king
	King white_king(7, 4, WHITE);
	occupied_positions[6][4] = EMPTY;

	std::vector<Position> possible_moves(white_king.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 1);

	CHECK_EQUAL(possible_moves[0], Position(6, 4));

	// testing black king
	King black_king(0, 4, BLACK);
	occupied_positions[1][4] = EMPTY;

	possible_moves = black_king.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 1);
	
	CHECK_EQUAL(possible_moves[0], Position(1, 4));
}

TEST(TestKing, test_case_2)
{
	// testing white king
	King white_king(6, 4, WHITE);
	occupied_positions[7][4] = EMPTY;
	occupied_positions[6][4] = WHITE;

	std::vector<Position> possible_moves(white_king.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 4);

	CHECK_EQUAL(possible_moves[0], Position(5, 4));
	CHECK_EQUAL(possible_moves[1], Position(5, 5));
	CHECK_EQUAL(possible_moves[2], Position(7, 4));
	CHECK_EQUAL(possible_moves[3], Position(5, 3));

	// testing black king
	King black_king(1, 4, BLACK);
	occupied_positions[0][4] = EMPTY;
	occupied_positions[1][4] = BLACK;

	possible_moves = black_king.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 4);

	CHECK_EQUAL(possible_moves[0], Position(0, 4));
	CHECK_EQUAL(possible_moves[1], Position(2, 5));
	CHECK_EQUAL(possible_moves[2], Position(2, 4));
	CHECK_EQUAL(possible_moves[3], Position(2, 3));
}

TEST(TestKing, test_case_3)
{
	// testing white king
	King white_king(5, 4, WHITE);
	occupied_positions[7][4] = EMPTY;
	occupied_positions[6][4] = EMPTY;
	occupied_positions[5][4] = WHITE;

	std::vector<Position> possible_moves(white_king.get_valid_positions(occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 6);
	
	CHECK_EQUAL(possible_moves[0], Position(4, 4));
	CHECK_EQUAL(possible_moves[1], Position(4, 5));
	CHECK_EQUAL(possible_moves[2], Position(5, 5));
	CHECK_EQUAL(possible_moves[3], Position(6, 4));
	CHECK_EQUAL(possible_moves[4], Position(5, 3));
	CHECK_EQUAL(possible_moves[5], Position(4, 3));

	// testing black king
	King black_king(2, 4, BLACK);
	occupied_positions[0][4] = EMPTY;
	occupied_positions[1][4] = EMPTY;
	occupied_positions[2][4] = BLACK;

	possible_moves = black_king.get_valid_positions(occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 6);

	CHECK_EQUAL(possible_moves[0], Position(1, 4));
	CHECK_EQUAL(possible_moves[1], Position(2, 5));
	CHECK_EQUAL(possible_moves[2], Position(3, 5));
	CHECK_EQUAL(possible_moves[3], Position(3, 4));
	CHECK_EQUAL(possible_moves[4], Position(3, 3));
	CHECK_EQUAL(possible_moves[5], Position(2, 3));
}

