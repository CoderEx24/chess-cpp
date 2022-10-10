#include "core/pawn.hpp"

const std::vector<Position>& Pawn::get_valid_positions(FakeGrid occupied_positions) //override
{
	possible_moves.clear();

	int direction = (this->color == WHITE) ? -1 : 1;
	Position point_to_add;

	// adding first forward position
	point_to_add = this->pos + Position(direction, 0);
	if (in_bounds(point_to_add) && occupied_positions[point_to_add.x][point_to_add.y].color == EMPTY)
		possible_moves.push_back(point_to_add);

	// adding second forward position if is it the first move
	point_to_add = this->pos + Position(2 * direction, 0);
	if (in_bounds(point_to_add) && is_first_move && 
			occupied_positions[point_to_add.x][point_to_add.y].color == EMPTY)
		possible_moves.push_back(point_to_add);

	// adding first attack position, the one to the northeast of the pawn
	point_to_add = this->pos + Position(direction, 1);
	if (in_bounds(point_to_add) && occupied_positions[point_to_add.x][point_to_add.y].color != EMPTY &&
			occupied_positions[point_to_add.x][point_to_add.y].color != this->color)
		possible_moves.push_back(point_to_add);

	// adding second attack position, the one to the northwest of the pawn
	point_to_add = this->pos + Position(direction, -1);
	if (in_bounds(point_to_add) && occupied_positions[point_to_add.x][point_to_add.y].color != EMPTY &&
			occupied_positions[point_to_add.x][point_to_add.y].color != this->color)
		possible_moves.push_back(point_to_add);

	return possible_moves;
}
