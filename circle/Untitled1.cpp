#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

inline int sqr(int base){ return base * base; }

void myCircle (int x, int y, int r, int color) {
	int i = 0, 
	j = r; 

	double eg; 
	double ed; 
	double ev; 
	double e; 
	
	while (j >= i) { 
		eg = sqr(i + 1) + sqr(j) - sqr(r);
		eg = sqr(i + 1) + sqr(j) - sqr(r); 
		ed = sqr(i + 1) + sqr(j-1) - sqr(r); 
		ev = sqr(i) + sqr(j - 1) - sqr(r); 
		e = sqr(i) + sqr(j) - sqr(r); 

		putpixel(x + i, y + j, color); 
		putpixel(x + i, y - j, color);
		putpixel(x - i, y + j, color);  
		putpixel(x - i, y - j, color); 
		putpixel(x + j, y + i, color);
		putpixel(x - j, y + i, color);
		putpixel(x + j, y - i, color);
		putpixel(x - j, y - i, color);

		
		if(e<0) {
			if (ed < eg) i += 1;
			else {
				i += 1; 
				j -= 1; 
			} 
		}
		else 
			if (ed < ev) i += 1; 
			else {
				j-=1; 
			} 
	} 
}

void myCircle1(int _x, int _y, int radius, int color){
	int x = 0, y = radius, gap = 0, delta = (2 - 2 * radius);
            while (y >= 0)
            {
                putpixel(_x + x, _y + y,color);
                putpixel(_x + x, _y - y,color);
                putpixel(_x - x, _y - y, color);
                putpixel(_x - x, _y + y, color);
                gap = 2 * (delta + y) - 1;
                if (delta < 0 && gap <= 0)
                {
                    x++;
                    delta += 2 * x + 1;
                    continue;
                }
                if (delta > 0 && gap > 0)
                {
                    y--;
                    delta -= 2 * y + 1;
                    continue;
            	}
                x++;
                delta += 2 * (x - y);
                y--;
            }
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	myCircle(224, 150, 26, 13);
	myCircle1(129, 150, 30, 11);
	
	getch();
	closegraph();
	return 0;
}

