#include "core/bishop.hpp"

const std::vector<Position>& Bishop::get_valid_positions(FakeGrid occupied_positions)
{
	static std::vector<Position> possible_moves(0);
	return possible_moves;
}



