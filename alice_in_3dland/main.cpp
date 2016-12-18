#include "model.h"
#include "linedrawer.h"
#include <conio.h>
//#include "modifyFormatObj.h"


int main(int argc, char **argv){
	
	LineDrawer drawer;
	
	//(Model("cube.obj", &drawer, 50, 50)).draw();
	
	//modifyFormatObj("bashka.obj", "formattedbashka.obj");
	//(Model("formattedbashka.obj", &drawer, 700, 700)).draw();
	
	(Model("input.obj", &drawer, 70, 70)).draw();
		
	_getch();

	return 0;
}
