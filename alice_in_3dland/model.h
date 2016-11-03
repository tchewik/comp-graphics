#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "linedrawer.h"

class Model {
private:
	std::vector<std::vector<float> > points_;
	std::vector<std::vector<int> > flats_;
	LineDrawer *drawer;
public:
	Model(char *path, LineDrawer *drawer);
	~Model();
	void showPoints();
	void showFlats();
	void draw();
};

#endif // _MODEL_H
