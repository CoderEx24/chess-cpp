#include "core/king.hpp"

const std::vector<Position>& King::get_valid_positions(FakeGrid occupied_positions)
{
	possible_moves.clear();

	Position OFFSETS[8] {
		Position(-1, 0),
		Position(-1, 1),
		Position(0,  1),
		Position(1,  1),
		Position(1,  0),
		Position(1, -1),
		Position(0, -1),
		Position(-1,-1)
	};

	Position point_to_add;
	for (int i = 0; i < 8; i ++)
	{
		point_to_add = this->pos + OFFSETS[i];
		if (in_bounds(point_to_add) && 
				occupied_positions[point_to_add.x][point_to_add.y].color != this->color)
			possible_moves.push_back(point_to_add);
	}

	return possible_moves;
}



