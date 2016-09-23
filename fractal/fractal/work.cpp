#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square(520, 700, 120, 0).draw_squares_recursive(10, 0.62, YELLOW);

	_getch();
	closegraph();
}
