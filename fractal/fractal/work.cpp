#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"
#include "math.h"

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr_0(666, 666, 166, 0);
	//sqr_0.draw();
	Square sqr_1(sqr_0._points[3].x, sqr_0._points[3].y, 66, 0.666);
	//sqr_1.draw_squares_recursive(2, BLUE);
	
	
	sqr_0.draw_squares_recursive(7, 0.3, CYAN);

	//Square sqr_0(100, 100, 20, 0.4);
	//sqr_0.draw_circle(3);

	_getch();
	closegraph();
}
