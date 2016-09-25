#ifndef FRACTAL_H
#define FRACTAL_H

#include "graphics.h"
#define M_PI_2 1.57079632679489661923 

struct Point{
	double x, y;
};

class Square{
private:
	double _length, _angle;
	Point _points[4];
public:
	Square(double x, double y, double length, double angle = 0.0);
	Point getPoint(int i);
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

Point Square::getPoint(int i){
	if (i > -1 && i < 4)
		return _points[i];
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

void Square::draw_squares_recursive(int depth, double gamma, int color){
	draw(color, false);
	if (--depth >= 0){
		Square tmp(_points[3].x, _points[3].y, _length * cos(gamma), _angle + gamma);
		tmp.draw_squares_recursive(depth, gamma, color);
		Square(tmp._points[1].x, tmp._points[1].y, _length * sin(gamma), tmp._angle - M_PI_2).draw_squares_recursive(depth, gamma, color);

		/*
		/* ОДИНАКОВЫЕ КВАДРАТЫ
		/* Ужасно жаль удалять фантастические расчеты. (Побрекито)
		double length = sqrt(pow(_points[2].x - tmp._points[1].x, 2) + pow(tmp._points[1].y - _points[2].y, 2));
		double angle = -1 * (M_PI_2 + gamma / 2.0 - tmp._angle);
		Square(tmp._points[1].x, tmp._points[1].y, length, angle).draw_squares_recursive(depth, gamma, color);
		*/

	}
}

#endif