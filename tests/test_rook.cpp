#include <CppUTest/TestHarness.h>
#include "core/rook.hpp"
#include "test_common.hpp"

TEST_GROUP(TestRook)
{
	PieceColor occupied_positions[8][8] = {
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

TEST(TestRook, test_at_initial_position)
{
	// testing white rook
	Rook white_rook(7, 0, WHITE);
	std::vector<Position> possible_moves(white_rook.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 0);	

	// testing black rook
	Rook black_rook(0, 0, BLACK);
	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 0);
}

TEST(TestRook, test_case_1)
{
	// testing white rook
	Rook white_rook(7, 0, WHITE);
	occupied_positions[6][0] = EMPTY;
	std::vector<Position> possible_moves(white_rook.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 5);

	CHECK_EQUAL(possible_moves[0], Position(6, 0));
	CHECK_EQUAL(possible_moves[1], Position(5, 0));
	CHECK_EQUAL(possible_moves[2], Position(4, 0));
	CHECK_EQUAL(possible_moves[3], Position(3, 0));
	CHECK_EQUAL(possible_moves[4], Position(2, 0));
	
	// testing black rook
	Rook black_rook(0, 0, BLACK);
	occupied_positions[0][0] = EMPTY;
	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 6);

	CHECK_EQUAL(possible_moves[0], Position(1, 0));
	CHECK_EQUAL(possible_moves[1], Position(2, 0));
	CHECK_EQUAL(possible_moves[2], Position(3, 0));
	CHECK_EQUAL(possible_moves[3], Position(4, 0));
	CHECK_EQUAL(possible_moves[4], Position(5, 0));
	CHECK_EQUAL(possible_moves[5], Position(6, 0));
}

TEST(TestRook, test_case_2)
{
	// testing whtie rook
	Rook white_rook(3, 0, WHITE);
	occupied_positions[3][0] = WHITE;
	occupied_positions[7][0] = EMPTY;

	std::vector<Position> possible_moves(white_rook.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 11);
	
	CHECK_EQUAL(possible_moves[0],  Position(2, 0));
	CHECK_EQUAL(possible_moves[1],  Position(3, 1));
	CHECK_EQUAL(possible_moves[2],  Position(4, 0));
	CHECK_EQUAL(possible_moves[3],  Position(1, 0));
	CHECK_EQUAL(possible_moves[4],  Position(3, 2));
	CHECK_EQUAL(possible_moves[5],  Position(5, 0));
	CHECK_EQUAL(possible_moves[6],  Position(3, 3));
	CHECK_EQUAL(possible_moves[7],  Position(3, 4));
	CHECK_EQUAL(possible_moves[8],  Position(3, 5));
	CHECK_EQUAL(possible_moves[9],  Position(3, 6));
	CHECK_EQUAL(possible_moves[10], Position(3, 7));

	// testing black rook
	Rook black_rook(3, 7, BLACK);
	occupied_positions[3][7] = BLACK;
	occupied_positions[0][7] = EMPTY;

	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 11);

	CHECK_EQUAL(possible_moves[0],  Position(2, 7));
	CHECK_EQUAL(possible_moves[1],  Position(4, 7));
	CHECK_EQUAL(possible_moves[2],  Position(3, 6));
	CHECK_EQUAL(possible_moves[3],  Position(1, 7));
	CHECK_EQUAL(possible_moves[4],  Position(5, 7));
	CHECK_EQUAL(possible_moves[5],  Position(3, 5));
	CHECK_EQUAL(possible_moves[6],  Position(3, 4));
	CHECK_EQUAL(possible_moves[7],  Position(3, 3));
	CHECK_EQUAL(possible_moves[8],  Position(3, 2));
	CHECK_EQUAL(possible_moves[9],  Position(3, 1));
	CHECK_EQUAL(possible_moves[10], Position(3, 0));
}

TEST(TestRook, test_case_3)
{
	// testing white rook
	Rook white_rook(3, 3, WHITE);
	occupied_positions[3][3] = WHITE;

	std::vector<Position> possible_moves(white_rook.get_valid_positions((FakeGrid) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 11);

	CHECK_EQUAL(possible_moves[0],  Position(2, 3));
	CHECK_EQUAL(possible_moves[1],  Position(3, 4));
	CHECK_EQUAL(possible_moves[2],  Position(4, 3));
	CHECK_EQUAL(possible_moves[3],  Position(2, 3));
	CHECK_EQUAL(possible_moves[4],  Position(1, 3));
	CHECK_EQUAL(possible_moves[5],  Position(3, 5));
	CHECK_EQUAL(possible_moves[6],  Position(5, 3));
	CHECK_EQUAL(possible_moves[7],  Position(3, 1));
	CHECK_EQUAL(possible_moves[8],  Position(3, 6));
	CHECK_EQUAL(possible_moves[9],  Position(3, 0));
	CHECK_EQUAL(possible_moves[10], Position(3, 7));
	
	// testing black rook
	Rook black_rook(4, 4, BLACK);
	occupied_positions[4][4] = BLACK;

	possible_moves.clear();
	possible_moves = black_rook.get_valid_positions((FakeGrid) occupied_positions);
	CHECK_EQUAL(possible_moves.size(), 11);

	CHECK_EQUAL(possible_moves[0],  Position(3, 4));
	CHECK_EQUAL(possible_moves[1],  Position(4, 5));
	CHECK_EQUAL(possible_moves[2],  Position(5, 4));
	CHECK_EQUAL(possible_moves[3],  Position(4, 3));
	CHECK_EQUAL(possible_moves[4],  Position(2, 4));
	CHECK_EQUAL(possible_moves[5],  Position(4, 6));
	CHECK_EQUAL(possible_moves[6],  Position(4, 2));
	CHECK_EQUAL(possible_moves[7],  Position(1, 4));
	CHECK_EQUAL(possible_moves[8],  Position(4, 7));
	CHECK_EQUAL(possible_moves[9],  Position(4, 1));
	CHECK_EQUAL(possible_moves[10], Position(4, 0));
}
