#ifndef _MODEL_H
#define _MODEL_H

#include <vector>
#include "linedrawer.h"


class Model {
private:
	std::vector<std::vector<float> > _worldPoints;
	std::vector<std::vector<float> > _viewPoints;
	std::vector<std::vector<float> > _persPoints;
	std::vector<std::vector<float> > _dispPoints;
	std::vector<std::vector<int> > _flats;
	float viewMatrix[4][4];
	LineDrawer *drawer;
	float getH(int i);
	
	
public:
	Model(char *path, LineDrawer *drawer);
	~Model();
	void showPoints();
	void setViewPoints();
	void setDispPoints();
	void setViewMatrix(int rho, int theta, int phi);
	void showFlats();
	void draw();
	void cartoonDraw();
};

#endif // _MODEL_H
