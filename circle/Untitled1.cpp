#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int sqr(int base){
	return base * base;
}

void MyCircle (int x, int y, int r, int color) 
{int i=0, j=r; 

putpixel(x+i, y-j, color); 
double eg; 
double ed; 
double ev; 
double e; 


while ( j>=i) 
{ 
eg=(i+1)*(i+1)+j*j-r*r; 
ed=(i+1)*(i+1)+(j-1)*(j-1)-r*r; 
ev=i*i+(j-1)*(j-1)-r*r; 
e=i*i+j*j-r*r; 

if(e<0) 
if(ed<eg) {i+=1; putpixel (x+i, y-j, color); 
putpixel (x+i, y+j, color); 
putpixel (y-j, x+i, color); 
putpixel (x-i,y+j, color); 
putpixel (x-i,y-j, color); 
putpixel (y+j,x-i, color); 
putpixel (y+j, x+i, color); 
putpixel (y-j, x-i, color); 
} 

else {i+=1; j-=1; putpixel (x+i, y-j, color); 
putpixel (x+i, y+j, color); 
putpixel (y-j, x+i, color); 
putpixel (x-i,y+j, color); 
putpixel (x-i,y-j, color); 
putpixel (y+j,x-i, color); 
putpixel (y+j, x+i, color); 
putpixel (y-j, x-i, color); 
} 

else if (ed<ev) { i+=1; putpixel (x+i, y-j, color); 
putpixel (x+i, y+j, color); 
putpixel (y-j, x+i, color); 
putpixel (x-i,y+j, color); 
putpixel (x-i,y-j, color); 
putpixel (y+j,x-i, color); 
putpixel (y+j, x+i, color); 
putpixel (y-j, x-i, color); 
} 
else { j-=1; putpixel (x+i, y-j, color); 
putpixel (x+i, y+j, color); 
putpixel (y-j, x+i, color); 
putpixel (x-i,y+j, color); 
putpixel (x-i,y-j, color); 
putpixel (y+j,x-i, color); 
putpixel (y+j, x+i, color); 
putpixel (y-j, x-i, color); 
} 
} 
}

void MyCircle1(int _x, int _y, int radius, int color){
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

void myCircle2(int _x, int _y, int radius, int color){
	int i = 0, j = radius;
	
	while(j >= i){
		int e = sqr(i) + sqr(j) - sqr(radius);
		int ed = sqr(i + 1) + sqr(j) - sqr(radius);
		int eg = sqr(i + 1) + sqr(j - 1) - sqr(radius);
		int ev = sqr(i) + sqr(j - 1) - sqr(radius);
		putpixel(_x+i, _y-j, color);
		if (e > 0){
			if (ed > 0){
				_x++;
				i++;
			} else {
				_x++;
				_y--;
				i++;
				j--;
			}
		} else {
			_y--;
			j--;
		}
	}
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	MyCircle1(129, 150, 26, 13);
	
	getch();
	closegraph();
	return 0;
}

