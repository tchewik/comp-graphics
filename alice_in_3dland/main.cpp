#include "model.h"
#include "linedrawer.h"
#include <conio.h>

int main(int argc, char **argv){
	
	LineDrawer drawer;	
	(Model("cube.obj", &drawer)).draw();
	
	_getch();

	return 0;
}
