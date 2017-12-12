#pragma once
#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include<iostream>
#include <string>
#include "Model.h"

#define theWorld World::GetInstance()

class World
{
public:
	static World& GetInstance();

	void setCmdlineParams(int*argc, char **argv);
	void initialize(int width, int height, std::string name);
	void start();

	void render();
	void keyPress(unsigned char ch);

	void loadModel(std::string modelName);	//loads the model

private:
	static World* s_World;

	int   *argc;
	char **argv;

	Model theModel;	//model from the model class
};