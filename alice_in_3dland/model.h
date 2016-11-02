#ifndef _MODEL_H
#define _MODEL_H

#include <vector>

class Model {
private:
	std::vector<std::vector<float> > points_;
	std::vector<std::vector<int> > flats_;
public:
	Model(char *path = "resources/cube.obj");
	~Model();
	void showPoints();
	void showFlats();
};

#endif // _MODEL_H
