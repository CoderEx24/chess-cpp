#include "core/pawn.hpp"

const std::vector<Position>& Pawn::get_valid_positions(FakeGrid occupied_positions) //override
{
	std::vector<Position> *pos = new std::vector<Position>(0);
	return *pos;
}

