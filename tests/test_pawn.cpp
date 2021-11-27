#include <CppUTest/TestHarness.h>
#include "core/pawn.hpp"

class DummyPawn : public Pawn
{
	public: 
		DummyPawn(): Pawn() {}
		DummyPawn(int x, int y, PieceColor c = WHITE): Pawn(x, y, c) {}
		bool get_is_first_move() const { return is_first_move; }
};

TEST_GROUP(TestWhitePawn)
{
	bool occupied_positions[8][8] {
		{ true, true, true, true, true, true, true, true},  
		{ true, true, true, true, true, true, true, true}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ true, true, true, true, true, true, true, true},  
		{ true, true, true, true, true, true, true, true},  
	};

	TEST_SETUP();
	TEST_TEARDOWN();
};

TEST_GROUP(TestBlackPawn)
{
	bool occupied_positions[8][8] {
		{ true, true, true, true, true, true, true, true},  
		{ true, true, true, true, true, true, true, true}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ false, false, false, false, false, false, false, false}, 
		{ true, true, true, true, true, true, true, true},  
		{ true, true, true, true, true, true, true, true},  
	};

	TEST_SETUP();
	TEST_TEARDOWN();
};

TEST(TestWhitePawn, test_pawn_movement_before_first_move)
{
	DummyPawn pawn(6, 0);

	CHECK(pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(pawn.get_valid_positions((bool**) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 2);
	CHECK(possible_moves[0] == Position(5, 0));
	CHECK(possible_moves[1] == Position(4, 0));	
}

TEST(TestWhitePawn, test_pawn_movement_after_first_move)
{
	DummyPawn pawn(6, 0);
	CHECK(pawn.get_is_first_move());

	pawn.set_position(5, 0);
	CHECK(!pawn.get_is_first_move());
	
	std::vector<Position> possible_moves(pawn.get_valid_positions((bool**) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 1);
	CHECK(possible_moves[0] == Position(4, 0));	
}

TEST(TestBlackPawn, test_pawn_movement_before_first_move)
{
	DummyPawn pawn(1, 0);
	CHECK(pawn.get_is_first_move());

	std::vector<Position> possible_moves(pawn.get_valid_positions((bool**) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 2);
	CHECK(possible_moves[0] == Position(2, 0));
	CHECK(possible_moves[1] == Position(3, 0));
}

TEST(TestBlackPawn, test_pawn_movement_after_first_move)
{
	DummyPawn pawn(1, 0);
	CHECK(pawn.get_is_first_move());

	pawn.set_position(2, 0);
	CHECK(!pawn.get_is_first_move());

	std::vector<Position> possible_moves(pawn.get_valid_positions((bool**) occupied_positions));
	CHECK_EQUAL(possible_moves.size(), 1);
	CHECK(possible_moves[0] == Position(3, 0));
}
