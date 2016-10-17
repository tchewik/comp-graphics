#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void drawCircle(int x, int y, int radius, int color){
	setcolor(color);
	int e, i = 0, j = radius;
	i++;
	int x1 = x, y1 = y;
	while (i != 0 || j != radius){
		if (((i+1)*(i+1) + j*j - radius*radius) != 0) { // calculating e itself 
			i++;
			putpixel(x + i, y - i, BLUE);
		}
		else if (((i+1)*(i+1) + (j-1)*(j-1) - radius*radius) != 0)  {	
			i++; j--;
			putpixel(x + i, y - i, color);
		}
		else {
			j--;
			putpixel(x + i, y - i, GREEN);
		} 
	}
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	drawCircle(150, 160, 60, 13);
	
	getch();
	closegraph();
	return 0;
	
}

/*
int buf = x2;
	x2 = x2 > x1 ? x2 : x1;
	x1 = x2 > x1 ? x1 : buf;
	buf = y2;
	y2 = y2 > y1 ? y2 : y1;
	y1 = y2 > y1 ? y1 : buf;
	int N = x2 - x1;	// <0
	int M = y2 - y1;	// >0
	int e = 0;
	int i = x1, j = y1;
	while (i < x2+1 && j < y2+1){
		if (e>=N){
			j++;
			putpixel(i, j, color);
			e-=N;
		}
		else {
				i++;
				putpixel(i, j, color);	
				e += M;
			}
	} */



