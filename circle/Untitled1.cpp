#include "graphics.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");
	MyCircle1(129, 150, 260, 13);
	
	getch();
	closegraph();
	return 0;
}

