#include <CppUTest/TestHarness.h>
#include "core/queen.hpp"
#include "test_common.hpp"

// Queen test case
// The Queen can move in all 8 directions, as far as it can
// this means that the Queen can by modelled as a pawn and a bishop at the same time
//
// this test case provides 2 sets of tests.
// 
// The Normal Implementation tests
// -------------------------------
// these tests assume that the code generates the possible moves by itself
// the moves are ordered by starting from the north, going clockwise
//
//  \   |   /
//   \  |  /
//    8 1 2
//     \|/
// ---7-Q-3---
//     /|\
//    6 5 4
//   /  |  \
//  /   |   \
//
//  The Eazy Implementation tests
//  -----------------------------
//  these tests assume that the code reuses rook and bishop's code.
//  the moves of the rook are tested first, then the moves of the bishop.
//
//   \   |   /
//    \  |  /
//     8 1 5
//      \|/
//  ---4-Q-2---
//      /|\
//     7 3 6
//    /  |  \
//   /   |   \
//

TEST_GROUP(TestQueen)
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


TEST(TestQueen, test_at_inital_position)
{
	// testing white queen
	Queen white_queen(7, 3, WHITE);
	
	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(0, possible_moves.size());

	// testing black queen
	Queen black_queen(0, 3, BLACK);

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(0, possible_moves.size());
}

#ifndef QUEEN_EZ_IMP

TEST(TestQueen, test_case_1_normal_implementation)
{
	// testing white queen
	Queen white_queen(5, 5, WHITE);
	occupied_positions[5][5] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(17, possible_moves.size());

	CHECK_EQUAL(Position(4, 5), possible_moves[ 0]);
	CHECK_EQUAL(Position(4, 6), possible_moves[ 1]);
	CHECK_EQUAL(Position(5, 6), possible_moves[ 2]);
	CHECK_EQUAL(Position(5, 4), possible_moves[ 3]);
	CHECK_EQUAL(Position(4, 4), possible_moves[ 4]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 5]);
	CHECK_EQUAL(Position(3, 7), possible_moves[ 6]);
	CHECK_EQUAL(Position(5, 7), possible_moves[ 7]);
	CHECK_EQUAL(Position(5, 3), possible_moves[ 8]);
	CHECK_EQUAL(Position(3, 3), possible_moves[ 9]);
	CHECK_EQUAL(Position(2, 5), possible_moves[10]);
	CHECK_EQUAL(Position(5, 2), possible_moves[11]);
	CHECK_EQUAL(Position(2, 2), possible_moves[12]);
	CHECK_EQUAL(Position(1, 5), possible_moves[13]);
	CHECK_EQUAL(Position(5, 1), possible_moves[14]);
	CHECK_EQUAL(Position(1, 1), possible_moves[15]);
	CHECK_EQUAL(Position(5, 0), possible_moves[16]);

	// testing black queen
	// there is a white queen in (5, 5)
	Queen black_queen(2, 5, BLACK);
	occupied_positions[2][5] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(16, possible_moves.size());

	CHECK_EQUAL(Position(2, 6), possible_moves[ 0]);
	CHECK_EQUAL(Position(3, 6), possible_moves[ 1]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 2]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 3]);
	CHECK_EQUAL(Position(2, 4), possible_moves[ 4]);
	CHECK_EQUAL(Position(2, 7), possible_moves[ 5]);
	CHECK_EQUAL(Position(4, 7), possible_moves[ 6]);
	CHECK_EQUAL(Position(4, 5), possible_moves[ 7]);
	CHECK_EQUAL(Position(4, 3), possible_moves[ 8]);
	CHECK_EQUAL(Position(2, 3), possible_moves[ 9]);
	CHECK_EQUAL(Position(5, 5), possible_moves[10]);
	CHECK_EQUAL(Position(5, 2), possible_moves[11]);
	CHECK_EQUAL(Position(2, 2), possible_moves[12]);
	CHECK_EQUAL(Position(6, 1), possible_moves[13]);
	CHECK_EQUAL(Position(2, 1), possible_moves[14]);
	CHECK_EQUAL(Position(2, 0), possible_moves[15]);
}

TEST(TestQueen, test_case_2_normal_implementation)
{
	// testing white queen
	Queen white_queen(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(19, possible_moves.size());

	CHECK_EQUAL(Position(2, 3), possible_moves[ 0]);
	CHECK_EQUAL(Position(2, 4), possible_moves[ 1]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 2]);
	CHECK_EQUAL(Position(4, 4), possible_moves[ 3]);
	CHECK_EQUAL(Position(4, 3), possible_moves[ 4]);
	CHECK_EQUAL(Position(4, 2), possible_moves[ 5]);
	CHECK_EQUAL(Position(3, 2), possible_moves[ 6]);
	CHECK_EQUAL(Position(2, 2), possible_moves[ 7]);
	CHECK_EQUAL(Position(1, 3), possible_moves[ 8]);
	CHECK_EQUAL(Position(1, 5), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 5), possible_moves[10]);
	CHECK_EQUAL(Position(5, 5), possible_moves[11]);
	CHECK_EQUAL(Position(5, 3), possible_moves[12]);
	CHECK_EQUAL(Position(5, 1), possible_moves[13]);
	CHECK_EQUAL(Position(3, 1), possible_moves[14]);
	CHECK_EQUAL(Position(1, 1), possible_moves[15]);
	CHECK_EQUAL(Position(3, 6), possible_moves[16]);
	CHECK_EQUAL(Position(3, 0), possible_moves[17]);
	CHECK_EQUAL(Position(3, 7), possible_moves[18]);

	// testing black queen
	// note that there is a white queen above that black queen
	Queen black_queen(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;
	
	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(18, possible_moves.size());	
	
	CHECK_EQUAL(Position(3, 3), possible_moves[ 0]);
	CHECK_EQUAL(Position(3, 4), possible_moves[ 1]);
	CHECK_EQUAL(Position(4, 4), possible_moves[ 2]);
	CHECK_EQUAL(Position(5, 4), possible_moves[ 3]);
	CHECK_EQUAL(Position(5, 3), possible_moves[ 4]);
	CHECK_EQUAL(Position(5, 2), possible_moves[ 5]);
	CHECK_EQUAL(Position(4, 2), possible_moves[ 6]);
	CHECK_EQUAL(Position(3, 2), possible_moves[ 7]);
	CHECK_EQUAL(Position(2, 5), possible_moves[ 8]);
	CHECK_EQUAL(Position(4, 5), possible_moves[ 9]);
	CHECK_EQUAL(Position(6, 5), possible_moves[10]);
	CHECK_EQUAL(Position(6, 3), possible_moves[11]);
	CHECK_EQUAL(Position(6, 1), possible_moves[12]);
	CHECK_EQUAL(Position(4, 1), possible_moves[13]);
	CHECK_EQUAL(Position(2, 1), possible_moves[14]);
	CHECK_EQUAL(Position(4, 6), possible_moves[15]);
	CHECK_EQUAL(Position(4, 0), possible_moves[16]);
	CHECK_EQUAL(Position(4, 7), possible_moves[17]);
}

#else

TEST(TestQueen, test_case_1_easy_implementation)
{
	// testing white queen
	Queen white_queen(5, 5, WHITE);
	occupied_positions[5][5] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(17, possible_moves.size());

	CHECK_EQUAL(Position(4, 5), possible_moves[ 0]);
	CHECK_EQUAL(Position(5, 6), possible_moves[ 1]);
	CHECK_EQUAL(Position(5, 4), possible_moves[ 2]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 3]);
	CHECK_EQUAL(Position(5, 7), possible_moves[ 4]);
	CHECK_EQUAL(Position(5, 3), possible_moves[ 5]);
	CHECK_EQUAL(Position(2, 5), possible_moves[ 6]);
	CHECK_EQUAL(Position(5, 2), possible_moves[ 7]);
	CHECK_EQUAL(Position(1, 5), possible_moves[ 8]);
	CHECK_EQUAL(Position(5, 1), possible_moves[ 9]);
	CHECK_EQUAL(Position(5, 0), possible_moves[10]);
	CHECK_EQUAL(Position(4, 6), possible_moves[11]);
	CHECK_EQUAL(Position(4, 4), possible_moves[12]);
	CHECK_EQUAL(Position(3, 7), possible_moves[13]);
	CHECK_EQUAL(Position(3, 3), possible_moves[14]);
	CHECK_EQUAL(Position(2, 2), possible_moves[15]);
	CHECK_EQUAL(Position(1, 1), possible_moves[16]);

	// testing black queen
	// note that there is a white queen in (5, 5)
	Queen black_queen(2, 5, BLACK);
	occupied_positions[2][5] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(16, possible_moves.size());

	CHECK_EQUAL(Position(2, 6), possible_moves[ 0]);
	CHECK_EQUAL(Position(3, 5), possible_moves[ 1]);
	CHECK_EQUAL(Position(2, 4), possible_moves[ 2]);
	CHECK_EQUAL(Position(2, 7), possible_moves[ 3]);
	CHECK_EQUAL(Position(4, 5), possible_moves[ 4]);
	CHECK_EQUAL(Position(2, 3), possible_moves[ 5]);
	CHECK_EQUAL(Position(5, 5), possible_moves[ 6]);
	CHECK_EQUAL(Position(2, 2), possible_moves[ 7]);
	CHECK_EQUAL(Position(2, 1), possible_moves[ 8]);
	CHECK_EQUAL(Position(2, 0), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 6), possible_moves[10]);
	CHECK_EQUAL(Position(3, 4), possible_moves[11]);
	CHECK_EQUAL(Position(4, 7), possible_moves[12]);
	CHECK_EQUAL(Position(4, 3), possible_moves[13]);
	CHECK_EQUAL(Position(5, 2), possible_moves[14]);
	CHECK_EQUAL(Position(6, 1), possible_moves[15]);
}

TEST(TestQueen, test_case_2_eazy_implementation)
{
	// testing white queen
	Queen white_queen(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;

	std::vector<Position> possible_moves(white_queen.get_valid_positions(occupied_positions));
	CHECK_EQUAL(19, possible_moves.size());

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
	CHECK_EQUAL(Position(2, 4), possible_moves[11]);
	CHECK_EQUAL(Position(4, 4), possible_moves[12]);
	CHECK_EQUAL(Position(4, 2), possible_moves[13]);
	CHECK_EQUAL(Position(2, 2), possible_moves[14]);
	CHECK_EQUAL(Position(1, 5), possible_moves[15]);
	CHECK_EQUAL(Position(5, 5), possible_moves[16]);
	CHECK_EQUAL(Position(5, 1), possible_moves[17]);
	CHECK_EQUAL(Position(1, 1), possible_moves[18]);

	// testing black queen
	// note that there is a white queen above it
	Queen black_queen(4, 3, BLACK);
	occupied_positions[4][3] = BLACK;

	possible_moves = black_queen.get_valid_positions(occupied_positions);
	CHECK_EQUAL(18, possible_moves.size());

	CHECK_EQUAL(Position(3, 3), possible_moves[ 0]);
	CHECK_EQUAL(Position(4, 4), possible_moves[ 1]);
	CHECK_EQUAL(Position(5, 3), possible_moves[ 2]);
	CHECK_EQUAL(Position(4, 2), possible_moves[ 3]);
	CHECK_EQUAL(Position(4, 5), possible_moves[ 4]);
	CHECK_EQUAL(Position(6, 3), possible_moves[ 5]);
	CHECK_EQUAL(Position(4, 1), possible_moves[ 6]);
	CHECK_EQUAL(Position(4, 6), possible_moves[ 7]);
	CHECK_EQUAL(Position(4, 0), possible_moves[ 8]);
	CHECK_EQUAL(Position(4, 7), possible_moves[ 9]);
	CHECK_EQUAL(Position(3, 4), possible_moves[10]);
	CHECK_EQUAL(Position(5, 4), possible_moves[11]);
	CHECK_EQUAL(Position(5, 2), possible_moves[12]);
	CHECK_EQUAL(Position(3, 2), possible_moves[13]);
	CHECK_EQUAL(Position(2, 5), possible_moves[14]);
	CHECK_EQUAL(Position(6, 5), possible_moves[15]);
	CHECK_EQUAL(Position(6, 1), possible_moves[16]);
	CHECK_EQUAL(Position(2, 1), possible_moves[17]);
}

#endif
