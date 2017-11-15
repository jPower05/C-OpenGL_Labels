#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include "freeglut.h"
#include<iostream>


//LAB 3 TRIANGLES ..


void points();
void circlePoints();
void lineLoop();
void circleLines();
void linesWidth();
void lineStipple();
void drawHouse();


using namespace std;

GLfloat sizes[2];
GLfloat step;
GLfloat curSize;


//THIS IS A TEST

void points() {

	glBegin(GL_POINTS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 40.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 50.0f);
	glEnd();

}

void lineLoop()
{
	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(50.0f, 100.0f, 0.0f);
	glEnd();
}

void drawHouse() {
	glBegin(GL_LINE_STRIP);

	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(0.0f, -20.0f, 0.0f);
	glVertex3f(50.0f, -20.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(25.0f, 75.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glEnd();




	//glVertex3f(50.0f, 50.0f, 0.0f);
	//glVertex3f(50.0f, 100.0f, 0.0f);
	glEnd();
}

void circlePoints()
{
	float x, y, angle;
	for (angle = 0.0f; angle <= (2.0f * M_PI); angle += 0.01f)
	{
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		glPointSize(curSize);
		glBegin(GL_POINTS);
		glVertex3f(x, y, 0.0f);
		glEnd();
		curSize += step;
	}
}


void circleLines()
{
	glBegin(GL_LINE_LOOP);
	float x, y, angle;
	for (angle = 0.0f; angle <= (2.0f * M_PI); angle += 0.01f)
	{
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		glVertex3f(x, y, 0.0f);
	}
	glEnd();
}

void lineStipple()
{
	float y;
	int factor = 3;
	short pattern = 0x5555;

	glClear(GL_COLOR_BUFFER_BIT);

	for (y = -90.0f; y < 90.0f; y += 20.0f)
	{
		glLineStipple(factor, pattern);

		glBegin(GL_LINES);
		glVertex2f(-80.0f, y);
		glVertex2f(80.0f, y);
		glEnd();
	}
}


void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//points();
	//circlePoints();
	//lineLoop();
	//circleLines();
	//linesWidth();
	lineStipple();
	//drawHouse();

	glFlush();
}

void linesWidth()
{
	float y;

	glClear(GL_COLOR_BUFFER_BIT);

	for (y = -90.0f; y < 90.0f; y += 20.0f)
	{
		glLineWidth(curSize);

		glBegin(GL_LINES);
		glVertex2f(-80.0f, y);
		glVertex2f(80.0f, y);
		glEnd();

		curSize += 1.0f;
	}
}


void setupRC()
{
	//glGetFloatv(GL_POINT_SIZE_RANGE, sizes);
	//glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	//curSize = sizes[0];

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glEnable(GL_LINE_STIPPLE);

	glColor3f(1.0f, 1.0f, 0.0f);

	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("lab04");
	glutInitWindowSize(800, 600);
	glutDisplayFunc(renderScene);
	setupRC();
	glutMainLoop();

	return 0;
}