#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "linedrawer.h"


class Model {
private:
	std::vector<std::vector<float> > _worldPoins;
	std::vector<std::vector<float> > _viewPoints;
	std::vector<std::vector<float> > _dispPoints;
	std::vector<std::vector<int> > _flats;
	LineDrawer *drawer;
	int width;
	int height;
	
public:
	Model(char *path, LineDrawer *drawer, int width = 100, int height = 100);
	~Model();
	void setDispPoints();
	//void showPoints();
	void showFlats();
	void draw();
};

#endif // _MODEL_H
