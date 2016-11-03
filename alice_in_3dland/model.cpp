#include "model.h"
#include "linedrawer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

Model::Model(char *path, LineDrawer *drawer, int width, int height){
	
	//	-- *path --
	
	std::ifstream in;
	in.open(path, std::ifstream::in);
	if (in.fail()) return;

	std::string line;
	while (!in.eof()){
		
		std::getline(in, line);
		std::istringstream iss(line.c_str());
		char trashC;
		int trashI;
		if (!line.compare(0, 2, "v ")){
			iss >> trashC;
			std::vector<float> point(3);
			for (int i = 0; i < 3; i++) iss >> point[i];
			
			this->points_.push_back(point);
		}
		else if (!line.compare(0, 2, "f ")){
			iss >> trashC;
			int index;
			std::vector<int> flat;
			while (iss >> index >> trashC >> trashC >> trashI) flat.push_back(--index);
			
			this->flats_.push_back(flat);
		}
		
	}
	
	// std::clog << "# v#" << this->points_.size() << "; f#" << this->flats_.size() << std::endl;
	
	// -- *drawer --
	
	this->drawer = drawer;
	
	
	// -- width, height --
	
	this->width = width;
	this->height = height;
}

Model::~Model(){}	

void Model::showPoints(){
	
	for (int i = 0; i < this->points_.size(); i++){
		for (int j = 0; j < this->points_[i].size(); j++)
			std::cout << this->points_[i][j] << '\t';
		std::cout << std::endl;
	}
	
}

void Model::showFlats(){
	for(int i = 0; i < this->flats_.size(); i++) {
		std::cout << "...68..." << std::endl;
		for (int j = 0; j < this->flats_[i].size(); j++)
			std::cout << this->flats_[i][j] << '\t';
		std::cout << std::endl;
	}
}

void Model::draw(){
	
	for (int i = 0; i < this->flats_.size(); i++) {
		
        std::vector<int> flat = this->flats_[i];
        for (int j = 0; j < 3; j++) {

        	std::vector<float> v0 = points_[flat[j]];
            std::vector<float> v1 = points_[flat[(j + 1) % 3]];
            int x0 = (v0[0] + 1.) * (this->width / 2.); 
            int y0 = (v0[1] + 1.) * (this->height / 2.);
            int x1 = (v1[0] + 1.) * (this->width / 2.);
            int y1 = (v1[1] + 1.) * (this->width / 2.);

            drawer->draw(x0, y0, x1, y1, 15);
            
        }
        
    }
    
}
