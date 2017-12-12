#pragma once
#include <istream>
#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include<iostream>


struct Vector3
{
	float X;
	float Y;
	float Z;

	static Vector3 UnitX;
	static Vector3 UnitY;
	static Vector3 UnitZ;

	Vector3(float x, float y, float z);
	Vector3(float value);
	Vector3();
	Vector3(std::istream& is);

	void translate();
	void rotate(float angle);

	void render();
};