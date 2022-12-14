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
	
	FakeGrid occupied_positions;


	void setup()
	{
		occupied_positions = init_grid();
	}

	void teardown()
	{
		for(int i = 0; i < 8; i ++)
			delete[] occupied_positions[i];
		delete[] occupied_positions;
	}
};

TEST(TestKnight, test_at_inital_position)
{
	// testing white knight
	Knight white_knight(7, 1, WHITE);
	std::vector<Position> possible_moves(white_knight.get_valid_positions(occupied_positions));
	CHECK_EQUAL(2, possible_moves.size());

	CHECK_EQUAL(Position(5, 2), possible_moves[0]);
	CHECK_EQUAL(Position(5, 0), possible_moves[1]);

	// testing black knight
	Knight black_knight(0, 1, BLACK);
	possible_moves = black_knight.get_valid_positions(occupied_positions);
	CHECK_EQUAL(2, possible_moves.size());
	
	CHECK_EQUAL(Position(2, 0), possible_moves[0]);
	CHECK_EQUAL(Position(2, 2), possible_moves[1]);
}

TEST(TestKnight, test_case_1)
{
	// testing white knight
	Knight white_knight(5, 2, WHITE);
	occupied_positions[5][2] = WHITE;
	occupied_positions[7][1] = EMPTY;

	std::vector<Position> possible_moves(white_knight.get_valid_positions(occupied_positions));
	CHECK_EQUAL(5, possible_moves.size());

	CHECK_EQUAL(Position(3, 3), possible_moves[0]);
	CHECK_EQUAL(Position(3, 1), possible_moves[1]);
	CHECK_EQUAL(Position(4, 4), possible_moves[2]);
	CHECK_EQUAL(Position(7, 1), possible_moves[3]);
	CHECK_EQUAL(Position(4, 0), possible_moves[4]);

	// testing black knight
	Knight black_knight(2, 2, BLACK);
	occupied_positions[2][2] = BLACK;
	occupied_positions[0][1] = EMPTY;
	
	possible_moves = black_knight.get_valid_positions(occupied_positions);
	CHECK_EQUAL(5, possible_moves.size());

	CHECK_EQUAL(Position(0, 1), possible_moves[0]);
	CHECK_EQUAL(Position(3, 4), possible_moves[1]);
	CHECK_EQUAL(Position(4, 1), possible_moves[2]);
	CHECK_EQUAL(Position(4, 3), possible_moves[3]);
	CHECK_EQUAL(Position(3, 0), possible_moves[4]);
}

TEST(TestKnight, test_case_2)
{
	// testing white knight
	Knight white_knight(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;
	occupied_positions[7][1] = EMPTY;

	std::vector<Position> possible_moves(white_knight.get_valid_positions(occupied_positions));
	CHECK_EQUAL(8, possible_moves.size());

	CHECK_EQUAL(Position(1, 4), possible_moves[0]);
	CHECK_EQUAL(Position(1, 2), possible_moves[1]);
	CHECK_EQUAL(Position(4, 5), possible_moves[2]);
	CHECK_EQUAL(Position(2, 5), possible_moves[3]);
	CHECK_EQUAL(Position(5, 2), possible_moves[4]);
	CHECK_EQUAL(Position(5, 4), possible_moves[5]);
	CHECK_EQUAL(Position(2, 1), possible_moves[6]);
	CHECK_EQUAL(Position(4, 1), possible_moves[7]);
	
	// testing black knight
	Knight black_knight(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;
	occupied_positions[0][1] = EMPTY;

	possible_moves = black_knight.get_valid_positions(occupied_positions);
	CHECK_EQUAL(8, possible_moves.size());

	CHECK_EQUAL(Position(2, 4), possible_moves[0]);
	CHECK_EQUAL(Position(2, 2), possible_moves[1]);
	CHECK_EQUAL(Position(5, 5), possible_moves[2]);
	CHECK_EQUAL(Position(3, 5), possible_moves[3]);
	CHECK_EQUAL(Position(6, 2), possible_moves[4]);
	CHECK_EQUAL(Position(6, 4), possible_moves[5]);
	CHECK_EQUAL(Position(3, 1), possible_moves[6]);
	CHECK_EQUAL(Position(5, 1), possible_moves[7]);
}
