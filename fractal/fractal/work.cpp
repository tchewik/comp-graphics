#include "graphics.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct Point{
	int x,
		y;
};

class Square{
private:
	Point _points[4];
	int _length;
	double _angle;
public:
	Square(double x, double y, int length, double angle = 0.0){
		_length = length;
		_angle = angle;
		_points[0].x = x;
		_points[0].y = y;
		_points[1].x = _points[0].x + _length * cos(_angle);
		_points[1].y = _points[0].y - _length * sin(_angle);
		_points[2].x = _points[1].x - _length * sin(_angle);
		_points[2].y = _points[1].y - _length * cos(_angle);
		_points[3].x = _points[2].x - _length * cos(_angle);
		_points[3].y = _points[2].y + _length * sin(_angle);
	}
	void draw(){
		// accent the first point
		setcolor(RED);
		circle(_points[0].x, _points[0].y, 5);

		// draw the square
		setcolor(WHITE);
		line(_points[0].x, _points[0].y, _points[1].x, _points[1].y);
		line(_points[1].x, _points[1].y, _points[2].x, _points[2].y);
		line(_points[2].x, _points[2].y, _points[3].x, _points[3].y);
		line(_points[3].x, _points[3].y, _points[0].x, _points[0].y);
	}
};

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr(500, 500, 100);
	sqr.draw();

	_getch();
	closegraph();
}