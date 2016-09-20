#ifndef FRACTAL_H
#define FRACTAL_H

#include "graphics.h"

#define PI2 1.5708

struct Point{
	double x, y;
};

class Square{
private:
	double _length,
		_angle;
public:
	Point _points[4];
	Square(double x, double y, double length, double angle = 0.0);
	void draw(int color = WHITE, bool highlight_first_point = false);
	void draw_circle(int times, int counter = 1);
	void draw_squares_recursive(int depth, double gamma, int color = TX_PINK);
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

void Square::draw_circle(int times, int counter){
	_angle = _angle / counter;
	draw();
	if (times >= ++counter){
		double angle = _angle < 0 ? _angle : _angle *= -1;
		Square tmp(_points[1].x, _points[1].y, _length, _angle * counter);
		tmp.draw_circle(times, counter);
	}
}

void Square::draw_squares_recursive(int depth, double gamma, int color){
	draw(color);
	if (--depth >= 0){
		Square tmp(_points[3].x, _points[3].y, _length, _angle + gamma);
		tmp.draw_squares_recursive(depth, gamma, color);

		double length = sqrt(pow(_points[2].x - tmp._points[1].x, 2) + pow(tmp._points[1].y - _points[2].y, 2));
		double angle = 3.15159 / 2 - (3.14159 - tmp._angle - _angle-gamma) / 2; //????
		Square tmp_0(_points[1].x, _points[1].y, length, angle - PI2); //?????
		tmp_0.draw_squares_recursive(depth, gamma, color + 120);
	}
}

#endif
