#include <CppUTest/TestHarness.h>
#include "core/knight.hpp"
#include "test_common.hpp"

// Knight test case
// the knight moves in all possible rotations and flips of a L-shaped path
//
// The moves are ordered as follows, we start with position towards the northeast
// then the position towards the northwest. We label the northeast position 1, and 
// the northwest 2. We then rotate a 90 degrees clockwise. Position 1 would be the 
// one pointing downwards and Position 2 would be upwards. We add those in that order
//
//    2_ _1
//      |
// 7    |   4
// |	|   |
//  ----K---
// |    |   |
// 8    |   3
//    5_|_6
//


TEST_GROUP(TestKnight)
{
	PieceColor occupied_positions[8][8] {
		{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
		{BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK, BLACK},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
		{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
		{WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE, WHITE},
	};
};

TEST(TestKnight, test_at_inital_position)
{
	// testing white knight
	Knight white_knight(7, 1, WHITE);
	std::vector<Position> possible_moves(white_knight.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 2);

	CHECK_EQUAL(possible_moves[0], Position(5, 2));
	CHECK_EQUAL(possible_moves[1], Position(5, 0));

	// testing black knight
	Knight black_knight(0, 1, BLACK);
	possible_moves = black_knight.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 2);
	
	CHECK_EQUAL(possible_moves[0], Position(2, 2));
	CHECK_EQUAL(possible_moves[1], Position(2, 0));
}

TEST(TestKnight, test_case_1)
{
	// testing white knight
	Knight white_knight(5, 2, WHITE);
	occupied_positions[5][2] = WHITE;
	occupied_positions[7][1] = EMPTY;

	std::vector<Position> possible_moves(white_knight.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 5);

	CHECK_EQUAL(possible_moves[0], Position(3, 3));
	CHECK_EQUAL(possible_moves[1], Position(3, 1));
	CHECK_EQUAL(possible_moves[2], Position(4, 4));
	CHECK_EQUAL(possible_moves[3], Position(4, 0));
	CHECK_EQUAL(possible_moves[4], Position(7, 1));

	// testing black knight
	Knight black_knight(2, 2, BLACK);
	occupied_positions[2][2] = BLACK;
	occupied_positions[0][1] = EMPTY;
	
	possible_moves = black_knight.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 5);

	CHECK_EQUAL(possible_moves[0], Position(0, 1));
	CHECK_EQUAL(possible_moves[1], Position(3, 5));
	CHECK_EQUAL(possible_moves[2], Position(4, 3));
	CHECK_EQUAL(possible_moves[3], Position(4, 1));
	CHECK_EQUAL(possible_moves[4], Position(3, 0));
}

TEST(TestKnight, test_case_2)
{
	// testing white knight
	Knight white_knight(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;
	occupied_positions[7][1] = EMPTY;

	std::vector<Position> possible_moves(white_knight.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 8);

	CHECK_EQUAL(possible_moves[0], Position(1, 4));
	CHECK_EQUAL(possible_moves[1], Position(1, 2));
	CHECK_EQUAL(possible_moves[2], Position(4, 5));
	CHECK_EQUAL(possible_moves[3], Position(2, 5));
	CHECK_EQUAL(possible_moves[4], Position(5, 2));
	CHECK_EQUAL(possible_moves[5], Position(5, 4));
	CHECK_EQUAL(possible_moves[6], Position(4, 1));
	CHECK_EQUAL(possible_moves[7], Position(2, 1));
	
	// testing black knight
	Knight black_knight(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;
	occupied_positions[0][1] = EMPTY;

	possible_moves = black_knight.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 8);

	CHECK_EQUAL(possible_moves[0], Position(2, 4));
	CHECK_EQUAL(possible_moves[1], Position(2, 2));
	CHECK_EQUAL(possible_moves[2], Position(5, 5));
	CHECK_EQUAL(possible_moves[3], Position(3, 5));
	CHECK_EQUAL(possible_moves[4], Position(5, 2));
	CHECK_EQUAL(possible_moves[5], Position(5, 4));
	CHECK_EQUAL(possible_moves[6], Position(3, 1));
	CHECK_EQUAL(possible_moves[7], Position(5, 1));
}
