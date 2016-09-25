#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "fractal.h"
#define M_PI 3.14159265358979323846

double toRad(double grad){
	return grad * M_PI / 180;
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square(520, 700, 120, 0).draw_squares_recursive(10, toRad(45), LIGHTGREEN);

	_getch();
	closegraph();
}
