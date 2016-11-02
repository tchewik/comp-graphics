#include "model.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Model::Model(char *path){
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

	//std::cout << "# v#" << points_.size() << "; f#" << flats_.size() << std::endl;
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