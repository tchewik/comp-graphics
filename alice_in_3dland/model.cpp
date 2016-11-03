#include "model.h"
#include "linedrawer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Model::Model(char *path, LineDrawer *drawer){
	
	this->drawer = drawer;
	
	std::ifstream in;
	in.open(path, std::ifstream::in);
	if (in.fail()) return;

	std::string line;
	while (!in.eof()){
		std::getline(in, line);
		std::istringstream iss(line.c_str());
		char trashC;
		if (!line.compare(0, 2, "v ")){
			iss >> trashC;
			std::vector<float> point(3);
			for (int i = 0; i < 3; i++) iss >> point[i];
			points_.push_back(point);
		}
		else if (!line.compare(0, 2, "f ")){
			iss >> trashC;
			int index;
			std::vector<int> flat;
			while (iss >> index) flat.push_back(--index);
			flats_.push_back(flat);
		}
	}

	
	std::clog << "# v#" << points_.size() << "; f#" << flats_.size() << std::endl;
}

Model::~Model(){
	
}	

void Model::showPoints(){
	for (int i = 0; i < points_.size(); i++){
		for (int j = 0; j < points_[i].size(); j++)
			std::cout << points_[i][j] << '\t';
		std::cout << std::endl;
	}
}

void Model::showFlats(){
	for(int i = 0; i < flats_.size(); i++) {
		for (int j = 0; j < flats_[i].size(); j++)
			std::cout << flats_[i][j] << '\t';
		std::cout << std::endl;
	}
}

void Model::draw(){
	for (int i = 0; i < flats_.size(); i++) {
        std::vector<int> flat = flats_[i];
        for (int j = 0; j < 3; j++) {
        	std::cout << j;
        	std::vector<float> v0 = points_[flat[j]];
            //Vec3f v0 = model->vert(face[j]);
            std::vector<float> v1 = points_[flat[(j + 1) % 3]];
            //Vec3f v1 = model->vert(face[(j+1)%3]);
            int x0 = (v0[0]+1.);
            int y0 = (v0[1]+1.);
            int x1 = (v1[0]+1.);
            int y1 = (v1[1]+1.);

            //drawer->draw(x0, y0, x1, y1, 15);
            std::cout << x0 << '\t' << y0 << '\t' << x1 << '\t' << y1 << std::endl;
        }
    }
}
