#include "core/bishop.hpp"

const std::vector<Position>& Bishop::get_valid_positions(FakeGrid occupied_positions) 
{
	possible_moves.clear();

	Position OFFSETS[4] { Position(-1, 1), Position(1, 1), Position(1, -1), Position(-1, -1) };
	Position point_to_add;
	bool is_blocked[4] { false, false, false, false};
	bool all_blocked = false;
	int i = -1;
	
	while (!all_blocked)
	{
		i ++;
		if (is_blocked[i % 4]) continue;

		point_to_add = this->pos + OFFSETS[i % 4] * ((i / 4) + 1);
		
		if (!in_bounds(point_to_add) || occupied_positions[point_to_add.x][point_to_add.y].color != EMPTY)
			is_blocked[i % 4] = true;
		
		if (in_bounds(point_to_add) && 
				occupied_positions[point_to_add.x][point_to_add.y].color != this->color)
			possible_moves.push_back(point_to_add);
		
		all_blocked = is_blocked[0] && is_blocked[1] && is_blocked[2] && is_blocked[3];
	}

	return possible_moves;
}



