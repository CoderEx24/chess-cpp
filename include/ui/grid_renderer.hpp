#ifndef GRID_RENDERER_H
#define GRID_RENDERED_H

#include "core/grid.hpp"
#include <TGUI/Widgets/Canvas.hpp>
#include <SFML/Graphics.hpp>

class GridRenderer
{
	private:
		Grid grid;
		bool state_changed;

	public:
		GridRenderer(): state_changed(true) {};

		void render(tgui::Canvas::Ptr);


};

#endif

