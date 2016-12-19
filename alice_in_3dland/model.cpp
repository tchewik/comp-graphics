#include "model.h"
#include "linedrawer.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <windows.h>

#define RHO 400
#define THETA 1
#define PHI 1



Model::Model(char *path, LineDrawer *drawer, int width, int height){
	
	std::ifstream in;
	in.open(path, std::ifstream::in);
	if (in.fail()){
		std::clog << "Не открываеца";
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
	
	
	
	// this->showPoints();
	// this->showFlats();
	
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

		point3D[0] = viewMatrix[0][0] * _worldPoints[i][0] +
					 viewMatrix[0][1] * _worldPoints[i][1] +
					 viewMatrix[0][2] * _worldPoints[i][2] + 
					 viewMatrix[0][3]; 

		point3D[1] = viewMatrix[1][0] * _worldPoints[i][0] +
					 viewMatrix[1][1] * _worldPoints[i][1] +
					 viewMatrix[1][2] * _worldPoints[i][2] + 
					 viewMatrix[1][3];

		point3D[2] = viewMatrix[2][0] * _worldPoints[i][0] +
					 viewMatrix[2][1] * _worldPoints[i][1] +
					 viewMatrix[2][2] * _worldPoints[i][2] + 
					 viewMatrix[2][3];
		
		
		std::vector<float> point2D(2);
		
		point2D[0] = (RHO/(2*point3D[2]))*point3D[0];
		point2D[1] = (RHO/(2*point3D[2]))*point3D[1];
		
		_viewPoints.push_back(point3D);
		_persPoints.push_back(point2D);
	}
}

void Model::setDispPoints(){
	this->_viewPoints.clear();
	this->_persPoints.clear();
	this->_dispPoints.clear();
	
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
	
	/*
	std::cout << "--WORLD POINTS--" << std::endl;
	
	for (int i = 0; i < this->_worldPoints.size(); i++){
		for (int j = 0; j < this->_worldPoints[i].size(); j++)
			std::cout << this->_worldPoints[i][j] << '\t';
		std::cout << std::endl;
	}
	*/
	
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
	
	std::cout << "--DISP POINTS--" << std::endl;
	
	for (int i = 0; i < this->_dispPoints.size(); i++){
		for (int j = 0; j < this->_dispPoints[i].size(); j++)
			std::cout << this->_dispPoints[i][j] << '\t';
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


float Model::getH(int i){
	
	float h;
	std::vector<int> flat = this->_flats[i];
	
	std::vector<float> a = this->_viewPoints[flat[0]];
	std::vector<float> b = this->_viewPoints[flat[1]];
	std::vector<float> c = this->_viewPoints[flat[2]];
	
	h = a[0] * (b[1] * c[2] - c[1] * a[2]) - 
      b[0] * (a[1] * c[2] - c[1] * b[2]) +
      c[0] * (a[1] * b[2] - b[1] * a[2]);

	return h;
}


void Model::draw(){
	
	for (int i = 0; i < this->_flats.size(); i++) {
		
		float h = this->getH(i);
		
		if (h > 0){
			std::vector<int> flat = this->_flats[i];
    
	        for (int j = 0; j < 3; j++) {
	
	        	std::vector<float> v0 = _dispPoints[flat[j]];
	            std::vector<float> v1 = _dispPoints[flat[(j + 1) % 3]];
	
	            drawer->draw(v0[0], v0[1], v1[0], v1[1], 15);
        	}
		}
    }
}

void Model::setViewMatrix(int rho, int theta, int phi){
	std::clog << "viewMatrix mit phi = " << phi << std::endl;
	viewMatrix[0][0] = -sin(theta);
	viewMatrix[0][1] = cos(theta);
	viewMatrix[0][2] = 0;
	viewMatrix[0][3] = 0;
	viewMatrix[1][0] = -sin(phi)*cos(theta);
	viewMatrix[1][1] = -sin(phi)*sin(theta);
	viewMatrix[1][2] = sin(phi);
	viewMatrix[1][3] = 0;
	viewMatrix[2][0] = -sin(phi)*cos(theta);
	viewMatrix[2][1] = -sin(phi)*sin(theta);
	viewMatrix[2][2] = -cos(phi);
	viewMatrix[2][3] = rho;
	viewMatrix[3][0] = 0;
	viewMatrix[3][1] = 0;
	viewMatrix[3][2] = 0;
	viewMatrix[3][3] = 1;
}


void Model::cartoonDraw(){
	
	for (int i = 0; i < 10; i++){
		this->setViewMatrix(RHO, THETA, PHI);
		this->draw();
		Sleep(1000);
	}
	
	this->setViewMatrix(RHO, THETA, PHI);
	this->showPoints();
	this->setDispPoints();
	this->showPoints();
	this->draw();
}
