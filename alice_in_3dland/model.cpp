#include "model.h"
#include "linedrawer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

#define RHO 400
#define THETA 1
#define PHI 1

double viewMatrix[4][4] = {
    {-sin(THETA),cos(THETA),0,0},
    {-sin(PHI)*cos(THETA),-sin(PHI)*sin(THETA),sin(PHI),0},
    {-sin(PHI)*cos(THETA),-sin(PHI)*sin(THETA),-cos(PHI),RHO},
    {0,0,0,1}
};

Model::Model(char *path, LineDrawer *drawer, int width, int height){
	
	std::ifstream in;
	in.open(path, std::ifstream::in);
	if (in.fail()){
		std::clog << "�� ����������";
		return;
	}

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
			
			this->_worldPoints.push_back(point);
		}
		else if (!line.compare(0, 2, "f ")){
			iss >> trashC;
			int index;
			std::vector<int> flat;
			while (iss >> index >> trashC >> trashC >> trashI) flat.push_back(--index);
			
			this->_flats.push_back(flat);
		}
		
	}
	
	// std::clog << "# v#" << this->_worldPoints.size() << "; f#" << this->_flats.size() << std::endl;
	
	setDispPoints();
	
	/*
	std::clog << "# v#" << this->_viewPoints.size() << "; f#" << this->_flats.size() << std::endl;
	std::clog << "# v#" << this->_persPoints.size() << "; f#" << this->_flats.size() << std::endl;
	std::clog << "# v#" << this->_dispPoints.size() << "; f#" << this->_flats.size() << std::endl;
	*/
	
	this->showPoints();
	
	// -- *drawer --
	
	this->drawer = drawer;
	
	
	// -- width, height --
	
	this->width = width;
	this->height = height;
}

Model::~Model(){}	

void Model::setViewPoints(){

	for (int i = 0; i < _worldPoints.size(); i++) {
		
		std::vector<float> point3D(3);
		
		point3D[0] = viewMatrix[0][0] * _worldPoints[0][i] * viewMatrix[0][1] * 
							_worldPoints[1][i] * viewMatrix[0][2] * _worldPoints[2][i] + viewMatrix[0][3]; 

		point3D[1] = viewMatrix[1][0] * _worldPoints[0][i] * viewMatrix[1][1] * 
							_worldPoints[1][i] * viewMatrix[1][2] * _worldPoints[2][i] + viewMatrix[1][3];

		point3D[2] = viewMatrix[2][0] * _worldPoints[0][i] * viewMatrix[2][1] * 
					_worldPoints[1][i] * viewMatrix[2][2] * _worldPoints[2][i] + viewMatrix[2][3];

		
		std::vector<float> point2D(2);
		
		point2D[0] = (RHO/(2*point3D[2]))*point3D[0];
		point2D[1] = (RHO/(2*point3D[2]))*point3D[1];
		
		_viewPoints.push_back(point3D);
		_persPoints.push_back(point2D);
		
	}
}

void Model::setDispPoints(){
	//_dispPoints = _worldPoints;
	
	int ij[2][2] = {
			{ 100, 100 },
			{ 400, 400 }
		};
	int xy[2][2] = {
			{ -100, -100 },
			{ 100, 100	}
		};
		
	setViewPoints();
	
	for (int i = 0; i < _persPoints.size(); i++) {
		std::vector<float> point(2);
		
		point[0] = ij[1][0] + (_persPoints[i][0] - xy[1][0]) * (ij[0][0] - ij[1][0]) / (xy[0][0] - xy[1][0]);
		point[1] = ij[0][1] + (_persPoints[i][1] - xy[0][1]) * (ij[1][1] - ij[0][1]) / (xy[1][1] - xy[0][1]);
		
		_dispPoints.push_back(point);
	}

}


void Model::showPoints(){
	
	std::cout << "--WORLD POINTS--" << std::endl;
	
	for (int i = 0; i < this->_worldPoints.size(); i++){
		for (int j = 0; j < this->_worldPoints[i].size(); j++)
			std::cout << this->_worldPoints[i][j] << '\t';
		std::cout << std::endl;
	}
	
	std::cout << "--VIEW POINTS--" << std::endl;
	
	for (int i = 0; i < this->_viewPoints.size(); i++){
		for (int j = 0; j < this->_viewPoints[i].size(); j++)
			std::cout << this->_viewPoints[i][j] << '\t';
		std::cout << std::endl;
	}
	
	std::cout << "--PERS POINTS--" << std::endl;
	
	for (int i = 0; i < this->_persPoints.size(); i++){
		for (int j = 0; j < this->_persPoints[i].size(); j++)
			std::cout << this->_persPoints[i][j] << '\t';
		std::cout << std::endl;
	}
	
}


void Model::showFlats(){
	for(int i = 0; i < this->_flats.size(); i++) {
		for (int j = 0; j < this->_flats[i].size(); j++)
			std::cout << this->_flats[i][j] << '\t';
		std::cout << std::endl;
	}
}

void Model::draw(){
	
	for (int i = 0; i < this->_flats.size(); i++) {
		
        std::vector<int> flat = this->_flats[i];
        for (int j = 0; j < 3; j++) {

        	std::vector<float> v0 = _dispPoints[flat[j]];
            std::vector<float> v1 = _dispPoints[flat[(j + 1) % 3]];
            int x0 = (v0[0] + 1.) * (this->width / 2.); 
            int y0 = (v0[1] + 1.) * (this->height / 2.);
            int x1 = (v1[0] + 1.) * (this->width / 2.);
            int y1 = (v1[1] + 1.) * (this->height / 2.);

            drawer->draw(x0, y0, x1, y1, 15);
            
        }
        
    }
    
}
