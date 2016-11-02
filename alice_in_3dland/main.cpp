#include "model.h"
#include "linedrawer.h"

int main(int argc, char **argv){
	Model model;
	LineDrawer drawer;
	drawer.draw(100, 100, 900, 200, 13);
	
	return 0;
}
