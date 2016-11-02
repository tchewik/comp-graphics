#ifndef _LINE_H
#define _LINE_H

#include <Windows.h>

class Line {
protected:
	HWND hwnd_;
	HDC hdc_;
public:
	Line();
	~Line();
	void draw(int x0, int y0, int x1, int y1, int color);
};

#endif // _LINE_H