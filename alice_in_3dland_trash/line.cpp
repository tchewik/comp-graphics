#include "line.h"
#include <memory>	// std::swap()
#include <conio.h>

Line::Line(){
	/*int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");*/

	char title[1024];
	GetConsoleTitle(title, 1024);
	hwnd_ = FindWindow(NULL, title);

	RECT rc;
	GetClientRect(hwnd_, &rc);
	int iWidth = rc.right;
	int iHeight = rc.bottom;
	hdc_ = GetDC(hwnd_);
}

Line::~Line(){
	ReleaseDC(hwnd_, hdc_);
	_getch();
}

void Line::draw(int x0, int y0, int x1, int y1, int color){

	for (int i = 14; i <= 39; i++)
		SetPixel(hdc_, i, 20, 17);
	//setcolor(color);

	if (x0 > x1) std::swap(x0, x1);
	int buf = x1;
	x1 = x1 > x0 ? x1 : x0;
	x0 = x1 > x0 ? x0 : buf;
	buf = y1;
	y1 = y1 > y0 ? y1 : y0;
	y0 = y1 > y0 ? y0 : buf;
	int N = x1 - x0;	// <0
	int M = y1 - y0;	// >0
	int e = 0;
	int i = x0, j = y0;
	while (i < x1+1 && j < y1+1){
		if (e>=N){
			j++;
			//putpixel(i, j, color);
			SetPixel(hdc_, i, j, color);
			e-=N;
		}
		else {
				i++;
				//putpixel(i, j, color);	
				SetPixel(hdc_, i, j, color);
				e += M;
			}
	}
}