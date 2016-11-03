#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "linedrawer.h"

class Model {
private:
	std::vector<std::vector<float> > points_;
	std::vector<std::vector<int> > flats_;
	LineDrawer *drawer;
	int width;
	int height;
public:
	Model(char *path, LineDrawer *drawer, int width = 100, int height = 100);
	~Model();
	void showPoints();
	void showFlats();
	void draw();
};

#endif // _MODEL_H
