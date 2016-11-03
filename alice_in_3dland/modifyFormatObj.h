#ifndef _MOD_FORMAT_OBJ
#define _MOD_FORMAT_OBJ

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void modifyFormatObj(char* filename, char* fileout){
	std::ifstream filein;
	filein.open(filename);
	if (filein.fail()) return;
	
	std::ofstream out;
	out.open(fileout);
	
	std::string line;
	while (!filein.eof()){
		
		std::getline(filein, line);
		std::istringstream iss(line.c_str());
		
		char trashC;
		int trashI, index;
		
		if (!line.compare(0, 2, "f ")){
			out << "f ";
			iss >> trashC;
			while (iss >> index >> trashC >> trashI >> trashC >> trashI) out << index << trashC << trashC << trashI << ' ';
			out << std::endl;
		} else {
			out << line << std::endl;
		}
	}
	
	filein.close();
	out.close();
}

#endif
