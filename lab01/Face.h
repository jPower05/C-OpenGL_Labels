#pragma once

#include <istream>
#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include<iostream>
#include "Vector3.h"
#include "vector"


struct Face
{
	
	int vertices[3];
	int textures[3];

	Face(std::istream &is);
	void render(std::vector<Vector3> &defaultTable);
};