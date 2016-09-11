#include "graphics.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

struct Point{
	double x,
		y;
};

class Square{
private:
	Point _points[4];
	double _length,
		_angle;
public:
	Square(double x, double y, double length, double angle = 0.0){
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
	void draw(int color = WHITE){
		// uncomment to accent the first point
		//
		// setcolor(RED);
		// circle(_points[0].x, _points[0].y, 5);

		// draw the square
		setcolor(color);
		line(_points[0].x, _points[0].y, _points[1].x, _points[1].y);
		line(_points[1].x, _points[1].y, _points[2].x, _points[2].y);
		line(_points[2].x, _points[2].y, _points[3].x, _points[3].y);
		line(_points[3].x, _points[3].y, _points[0].x, _points[0].y);
	}
	void draw_circle(int times, int counter = 1, bool main = true){
		_angle /= counter;
		
		// uncomment to draw a boring white square
		//if (_angle >= 0)
		//	_angle *= -1;
		
		draw();
		draw_chain(counter);
		if (main){
			if (times >= ++counter){
				double angle = _angle < 0 ? _angle : _angle *= -1;
				Square tmp(_points[1].x, _points[1].y, _length, angle * counter);
				tmp.draw_circle(times, counter);
			}
		}
	}
	void draw_chain(int times, int counter = 1){
		_angle /= counter;
		draw();

		if (times >= ++counter){
			double angle = _angle > 0 ? _angle : _angle *= -1;
			Square tmp(_points[3].x, _points[3].y, _length, angle * counter);
			tmp.draw_chain(times, counter);
		}
	}
};

int main(){
	int gddriver = DETECT, gmode, errorcode;
	initgraph(&gddriver, &gmode, "");

	Square sqr(400, 300, 40, -0.2);

	// uncomment to draw a single square
	// sqr.draw();

	// draw a chain of squares
	sqr.draw_circle(6);
	//sqr.draw_chain(6);

	_getch();
	closegraph();
}