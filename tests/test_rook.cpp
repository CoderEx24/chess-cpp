#include <CppUTest/TestHarness.h>
#include "core/rook.hpp"
#include "test_common.hpp"

// Rook test case
// The rook can move in straight lines, as far as it can.
//
// the moves are ordered starting with the north direction.
// and then going clockwise.
//
//      |
//      |
//      1
//      |
// ---4-R-2---
//      |
//      3
//      |
//      |

TEST_GROUP(TestRook)
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

TEST(TestRook, test_at_initial_position)
{
	// testing white rook
	Rook white_rook(7, 0, WHITE);
	std::vector<Position> possible_moves(white_rook.get_valid_positions(occupied_positions));
	CHECK_EQUAL(0, possible_moves.size());	

	// testing black rook
	Rook black_rook(0, 0, BLACK);
	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions(occupied_positions);
	CHECK_EQUAL(0, possible_moves.size());
}

TEST(TestRook, test_case_1)
{
	// testing white rook
	Rook white_rook(7, 0, WHITE);
	occupied_positions[6][0] = EMPTY;
	std::vector<Position> possible_moves(white_rook.get_valid_positions(occupied_positions));
	CHECK_EQUAL(6, possible_moves.size());

	CHECK_EQUAL(Position(6, 0), possible_moves[0]);
	CHECK_EQUAL(Position(5, 0), possible_moves[1]);
	CHECK_EQUAL(Position(4, 0), possible_moves[2]);
	CHECK_EQUAL(Position(3, 0), possible_moves[3]);
	CHECK_EQUAL(Position(2, 0), possible_moves[4]);
	CHECK_EQUAL(Position(1, 0), possible_moves[5]);
	
	// testing black rook
	Rook black_rook(0, 0, BLACK);
	occupied_positions[1][0] = EMPTY;
	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions(occupied_positions);
	CHECK_EQUAL(7, possible_moves.size());

	CHECK_EQUAL(Position(1, 0), possible_moves[0]);
	CHECK_EQUAL(Position(2, 0), possible_moves[1]);
	CHECK_EQUAL(Position(3, 0), possible_moves[2]);
	CHECK_EQUAL(Position(4, 0), possible_moves[3]);
	CHECK_EQUAL(Position(5, 0), possible_moves[4]);
	CHECK_EQUAL(Position(6, 0), possible_moves[5]);
	CHECK_EQUAL(Position(7, 0), possible_moves[6]);
}

TEST(TestRook, test_case_2)
{
	// testing whtie rook
	Rook white_rook(3, 0, WHITE);
	occupied_positions[3][0] = WHITE;
	occupied_positions[7][0] = EMPTY;

	std::vector<Position> possible_moves(white_rook.get_valid_positions(occupied_positions));
	CHECK_EQUAL(11, possible_moves.size());
	
	CHECK_EQUAL(Position(2, 0), possible_moves[ 0]);
	CHECK_EQUAL(Position(3, 1), possible_moves[ 1]);
	CHECK_EQUAL(Position(4, 0), possible_moves[ 2]);
	CHECK_EQUAL(Position(1, 0), possible_moves[ 3]);
	CHECK_EQUAL(Position(3, 2), possible_moves[ 4]);
	CHECK_EQUAL(Position(5, 0), possible_moves[ 5]);
	CHECK_EQUAL(Position(3, 3), possible_moves[ 6]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 7]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 8]);
	CHECK_EQUAL(Position(3, 6), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 7), possible_moves[10]);

	// testing black rook
	Rook black_rook(3, 7, BLACK);
	occupied_positions[3][7] = BLACK;
	occupied_positions[0][7] = EMPTY;

	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions(occupied_positions);
	CHECK_EQUAL(11, possible_moves.size());

	CHECK_EQUAL(Position(2, 7), possible_moves[ 0]);
	CHECK_EQUAL(Position(4, 7), possible_moves[ 1]);
	CHECK_EQUAL(Position(3, 6), possible_moves[ 2]);
	CHECK_EQUAL(Position(5, 7), possible_moves[ 3]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 4]);
	CHECK_EQUAL(Position(6, 7), possible_moves[ 5]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 6]);
	CHECK_EQUAL(Position(3, 3), possible_moves[ 7]);
	CHECK_EQUAL(Position(3, 2), possible_moves[ 8]);
	CHECK_EQUAL(Position(3, 1), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 0), possible_moves[10]);
}

TEST(TestRook, test_case_3)
{
	Rook white_rook(3, 3, WHITE);
	std::vector<Position> possible_moves(white_rook.get_valid_positions(occupied_positions));
	CHECK_EQUAL(11, possible_moves.size());

	CHECK_EQUAL(Position(2, 3), possible_moves[ 0]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 1]);
	CHECK_EQUAL(Position(4, 3), possible_moves[ 2]);
	CHECK_EQUAL(Position(3, 2), possible_moves[ 3]);
	CHECK_EQUAL(Position(1, 3), possible_moves[ 4]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 5]);
	CHECK_EQUAL(Position(5, 3), possible_moves[ 6]);
	CHECK_EQUAL(Position(3, 1), possible_moves[ 7]);
	CHECK_EQUAL(Position(3, 6), possible_moves[ 8]);
	CHECK_EQUAL(Position(3, 0), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 7), possible_moves[10]);
	
	// testing black rook
	Rook black_rook(4, 4, BLACK);
	occupied_positions[4][4] = BLACK;

	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions(occupied_positions);
	CHECK_EQUAL(11, possible_moves.size());

	CHECK_EQUAL(Position(3, 4), possible_moves[ 0]);
	CHECK_EQUAL(Position(4, 5), possible_moves[ 1]);
	CHECK_EQUAL(Position(5, 4), possible_moves[ 2]);
	CHECK_EQUAL(Position(4, 3), possible_moves[ 3]);
	CHECK_EQUAL(Position(2, 4), possible_moves[ 4]);
	CHECK_EQUAL(Position(4, 6), possible_moves[ 5]);
	CHECK_EQUAL(Position(6, 4), possible_moves[ 6]);
	CHECK_EQUAL(Position(4, 2), possible_moves[ 7]);
	CHECK_EQUAL(Position(4, 7), possible_moves[ 8]);
	CHECK_EQUAL(Position(4, 1), possible_moves[ 9]);
	CHECK_EQUAL(Position(4, 0), possible_moves[10]);
}
