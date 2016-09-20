#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr_0(666, 666, 80, 0);
	//sqr_0.draw();
	Square sqr_1(sqr_0._points[3].x, sqr_0._points[3].y, 80, 0.666);
	//sqr_1.draw_squares_recursive(2, BLUE);
	
	
	sqr_0.draw_squares_recursive(3, 0.3, BLUE);

	//Square sqr_0(100, 100, 20, 0.4);
	//sqr_0.draw_circle(3);

	_getch();
	closegraph();
}
