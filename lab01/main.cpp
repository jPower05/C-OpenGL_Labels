#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include<iostream>
#include "world.h"

int main(int argc, char* argv[])
{
	theWorld.setCmdlineParams(&argc, argv);
	theWorld.initialize(800, 600, "Assignment 2");
	std::cout << "Initialising" << std::endl;
	theWorld.loadModel("Cube.obj");
	std::cout << "Starting" << std::endl;
	theWorld.start();
	return 0;
}