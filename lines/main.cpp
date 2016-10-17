#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void drawLine(int x1, int y1, int x2, int y2, int color){
	setcolor(color);
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
	}
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	drawLine(100, 100, 900, 200, 13);
	drawLine(166, 366, 400, 900, WHITE);
	drawLine(148, 180, 320, 56, CYAN);
	drawLine(138, 180, 138, 380, RED);
	
	getch();
	closegraph();
	return 0;
	
}



