#include "linedrawer.h"
#include "graphics.h"
#include <memory>	// std::swap()
#include <cmath>
#include <conio.h>

LineDrawer::LineDrawer(){
	
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	
}

LineDrawer::~LineDrawer(){
	
	_getch();
	closegraph();
	
}

void LineDrawer::draw(int x0, int y0, int x1, int y1, int color){
	
	bool reverse = false;
	if (std::abs(x0-x1) < std::abs(y0-y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        reverse = true;
    }
	if (x0 > x1){
		std::swap(x0, x1);
		std::swap(y0, y1);
	}
	int dx = x1 - x0;
	int dy = y1 - y0;
	int e = 0;
	int de = 2 * std::abs(dy);
	int i = x0, j = y0;
	while (i <= x1){
		if (!reverse) putpixel(i, j, color);
		else putpixel(j, i, color);
		
		e += de;
		if (e > dx) {
			j += (y1 > y0 ? 1 : -1);
			e -= 2 * dx;
		}
		
		i++;
	}
	
}
