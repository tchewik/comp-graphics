#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"
#include "math.h"

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	//Square sqr(100, 100, 20, 0.4);
	//sqr.draw_circle(3);

	Square sqr_0(800, 700, 120, 0.45);
	Square sqr_1(sqr_0.get(3).x, sqr_0.get(3).y, 66, 0.666);

	sqr_0.draw_squares_recursive(12, 0.7, CYAN);

	_getch();
	closegraph();
}
