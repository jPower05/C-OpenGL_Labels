#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "freeglut.h"
#include<iostream>

#define GL_PI 3.1415
//LAB 4 3D Objects ..

void drawCone(float x, float y, float z, float radius);
void specialKeys(int key, int x, int y);

int step = 0;

void specialKeys(int key, int x, int y)
{
	std::cout << "special keys" << std::endl;
	int xRot = 0, yRot = 0;

	xRot = (key == GLUT_KEY_UP) ? -1 : xRot;
	xRot = (key == GLUT_KEY_DOWN) ? 1 : xRot;
	yRot = (key == GLUT_KEY_LEFT) ? -1 : yRot;
	yRot = (key == GLUT_KEY_RIGHT) ? 1 : yRot;

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	glutPostRedisplay();
}


void drawCone(float x, float y, float z, float radius)
{
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(x, y, z);
	float angle;
	for (angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI / 8.0f))
	{
		x = radius*sin(angle);
		y = radius*cos(angle);
		//change the colour of each line
		glColor3f(step % 2 == 0, step % 2, 0.0f);
		step++;

		glVertex2f(x, y);
	}
	glEnd();
}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//front face clockwise
	glFrontFace(GL_CW);
	drawCone(0, 0, 75, 50);
	//front face counterclockwise
	glFrontFace(GL_CCW);
	drawCone(0, 0, 0, 50);

	glutSwapBuffers();
}

void setupRC(void)
{
	//set triangles to be line only
	//glPolygonMode(GL_FRONT, GL_LINE);
	//glPolygonMode(GL_BACK, GL_LINE);

	//set triangles to be solid shapes
	glFrontFace(GL_CW);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);

	//stop colours from blending
	glShadeModel(GL_FLAT);

	//enable depth testing
	glEnable(GL_DEPTH_TEST);

	//enabling backface culling
	glEnable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	//RESIZE OBJECT
	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Lab 05");
	glutDisplayFunc(renderScene);
	glutSpecialFunc(specialKeys);

	//requesting a depth buffer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	setupRC();

	glutMainLoop();

	return 0;
}
