#include "core/queen.hpp"

#ifdef QUEEN_EZ_IMP
#include "core/bishop.hpp"
#include "core/rook.hpp"
#endif

const std::vector<Position>& Queen::get_valid_positions(FakeGrid occupied_positions)
{

	possible_moves.clear();

#ifdef QUEEN_EZ_IMP
	Rook   dummy_rook(this->pos.x, this->pos.y, this->color);
	Bishop dummy_bishop(this->pos.x, this->pos.y, this->color);
	
	std::vector<Position> possible_moves_to_add;
	
	possible_moves_to_add = dummy_rook.get_valid_positions(occupied_positions);
	for (auto point : possible_moves_to_add)
		possible_moves.push_back(point);

	possible_moves_to_add = dummy_bishop.get_valid_positions(occupied_positions);
	for (auto point : possible_moves_to_add)
		possible_moves.push_back(point);

#else
	Position OFFSETS[8] {
		Position(-1,  0),
		Position(-1,  1),
		Position( 0,  1),
		Position( 1,  1),
		Position( 1,  0),
		Position( 1, -1),
		Position( 0, -1),
		Position(-1, -1),
	};
	bool is_blocked[8] {false, false, false, false, false, false, false, false};
	bool all_blocked = false;
	Position point_to_add;
	int i = -1;

	while (!all_blocked)
	{
		i ++;
		point_to_add = this->pos + OFFSETS[i % 8] * ((i / 8) + 1);
		
		if (is_blocked[i % 8]) continue;

		if (!in_bounds(point_to_add) || 
				occupied_positions[point_to_add.x][point_to_add.y] != EMPTY)
			is_blocked[i % 8] = true;

		if (in_bounds(point_to_add) &&
				occupied_positions[point_to_add.x][point_to_add.y] != this->color)
			possible_moves.push_back(point_to_add);

		all_blocked = is_blocked[0] &&
			      is_blocked[1] &&
			      is_blocked[2] &&
			      is_blocked[3] &&
			      is_blocked[4] &&
			      is_blocked[5] &&
			      is_blocked[6] &&
			      is_blocked[7];
	}

#endif
	return possible_moves;
}


