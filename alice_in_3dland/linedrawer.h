#ifndef _LINE_DRAWER_H
#define _LINE_DRAWER_H

class LineDrawer {
public:
	LineDrawer();
	~LineDrawer();
	void draw(int x0, int y0, int x1, int y1, int color);
	void clearScreen();
};

#endif // _LINE_DRAWER_H
