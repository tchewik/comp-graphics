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
	void draw(int color = WHITE, bool highlight_first_point = false);
	void draw_squares_recursive(int depth, int color = TX_PINK);
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

void Square::draw(int color, bool highlight_first_point){
	setcolor(color);
	if (highlight_first_point)
		circle(_points[0].x, _points[0].y, 5);
	line(_points[0].x, _points[0].y, _points[1].x, _points[1].y);
	line(_points[1].x, _points[1].y, _points[2].x, _points[2].y);
	line(_points[2].x, _points[2].y, _points[3].x, _points[3].y);
	line(_points[3].x, _points[3].y, _points[0].x, _points[0].y);
}

void Square::draw_squares_recursive(int depth, int color){
	draw(color);
	if (--depth >= 0){
		Square tmp(_points[3].x, _points[3].y, _length, _angle * 2);
		tmp.draw_squares_recursive(depth);

		double length = sqrt(pow(_points[2].x - tmp._points[1].x, 2) + pow(tmp._points[1].y - _points[2].y, 2));
		double angle = 3.15159 / 2 - (3.14159 - tmp._angle - _angle) / 2;
		Square tmp_0(_points[2].x, _points[2].y, length, angle);
		tmp_0.draw_squares_recursive(depth);
	}
}

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr(666, 666, 40, 0.666);
	sqr.draw_squares_recursive(2);

	_getch();
	closegraph();
}