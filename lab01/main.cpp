#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "freeglut.h"
#include<iostream>


//LAB 4 3D Objects ..

void triangle();
void trianglesStrip();
void triangleFan();
void triangleCircle();

void triangle() {
	glBegin(GL_TRIANGLES);

	glVertex2f(0.0f, 0.0f);    // V0
	glVertex2f(25.0f, 25.0f);  // V1
	glVertex2f(50.0f, 0.0f);   // V2

	glVertex2f(-50.0f, 0.0f);  // V3
	glVertex2f(-75.0f, 50.0f); // V4
	glVertex2f(-25.0f, 0.0f);  // V5

	glEnd();
}

void trianglesStrip() {
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(0.0f, 0.0f);    // V0
	glVertex2f(50.0f, 0.0f);   // V1
	glVertex2f(25.0f, 25.0f);  // V2
	glVertex2f(75.0f, 25.0f);  // V3
	glVertex2f(50.0f, 50.0f);  // V4
	glEnd();
}

void triangleFan() {
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 50.0f);
	glVertex2f(25.0f, 30.0f);
	glVertex2f(40.0f, 0.0f);
	glVertex2f(25.0f, -30.0f);
	glEnd();
}

void triangleCircle() {

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 0.0f, 0.0f);
	float x, y, angle;
	for (angle = 0.0f; angle < (2.0f*M_PI); angle += (M_PI / 8.0f))
	{
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);

		glVertex2f(x, y);
	}
	glEnd();

}

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//triangle();
	//trianglesStrip();
	//triangleFan();
	triangleCircle();

	glFlush();
}

void setupRC(void)
{
	//set triangles to be line only
	glPolygonMode(GL_FRONT, GL_LINE);

	glPolygonMode(GL_BACK, GL_LINE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Lab 05");
	glutDisplayFunc(renderScene);

	setupRC();

	glutMainLoop();

	return 0;
}