#include "graphics.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

struct Point{
	double x, y;
};

class Square{
private:
	Point _points[4];
	double _length,
		_angle;
public:
	Square(double x, double y, double length, double angle = 0.0);
	void draw(int color = WHITE);
	void draw_circle(int times, int counter = 1, bool main = true);
};

Square::Square(double x, double y, double length, double angle){
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

void Square::draw(int color){
	setcolor(color);
	line(_points[0].x, _points[0].y, _points[1].x, _points[1].y);
	line(_points[1].x, _points[1].y, _points[2].x, _points[2].y);
	line(_points[2].x, _points[2].y, _points[3].x, _points[3].y);
	line(_points[3].x, _points[3].y, _points[0].x, _points[0].y);
}

void Square::draw_circle(int times, int counter, bool main){
	if (main){
		_angle = _angle / counter;
		draw_circle(times - counter + 1, 1, false);
		if (times >= ++counter){
			double angle = _angle < 0 ? _angle : _angle *= -1;
			Square tmp(_points[1].x, _points[1].y, _length, _angle * counter);
			tmp.draw_circle(times, counter);
		}
	}
	else {
		_angle = _angle / counter;
		draw();
		if (times >= ++counter){
			double angle = _angle > 0 ? _angle : _angle *= -1;
			Square tmp(_points[3].x, _points[3].y, _length, _angle * counter);
			tmp.draw_circle(times, counter, false);
		}
	}
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr(400, 300, 40, -0.15);

	// draw a chain of squares
	sqr.draw_circle(8);
	//sqr.draw_chain(6);

	_getch();
	closegraph();
}