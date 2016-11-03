#include "model.h"
#include "linedrawer.h"
#include <conio.h>
//#include "modifyFormatObj.h"


int main(int argc, char **argv){
	
	LineDrawer drawer;
	
	//(Model("cube.obj", &drawer)).draw();
	
	//modifyFormatObj("bashka.obj", "formattedbashka.obj");
	(Model("formattedbashka.obj", &drawer, 700, 700)).draw();
		
	_getch();

	return 0;
}
