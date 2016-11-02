#include "linedrawer.h"
#include "graphics.h"
#include <memory>	// std::swap()
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

	if (x0 > x1) std::swap(x0, x1);
	if (y0 > y1) std::swap(y0, y1);
	int N = x1 - x0;	// <0
	int M = y1 - y0;	// >0
	int e = 0;
	int i = x0, j = y0;
	while (i < x1+1 && j < y1+1){
		putpixel(i, j, color);
		if (e>=N) {
			j++;
			e-=N;
		} else {
			i++;	
			e += M;
		}
	}
	
}
