#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr(666, 666, 40, 0.666);
	sqr.draw_squares_recursive(2);

	Square sqr_0(100, 100, 20, 0.4);
	sqr_0.draw_circle(3);

	_getch();
	closegraph();
}