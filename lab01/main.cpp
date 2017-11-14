#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include<iostream>

using namespace std;

void update();


int windowWidth;
int windowHeight;

float x = -25.0f;
float y = 25.0f;

//THIS IS A TEST



void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	//glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	glRectf(x, y, x + 50, y - 50);

	glFlush();
}

void timerFunction(int value)
{
	update();
	//33 is the value the method will wait until executing
	glutTimerFunc(33, timerFunction, 1);
	glutPostRedisplay();
}

void update() {
	static float xstep = 1.0f;
	static float ystep = 1.0f;
	if (x > windowWidth - 50 || x < -windowWidth)
		xstep = -xstep;

	if (y > windowHeight || y < -windowHeight + 50)
		ystep = -ystep;

	x += xstep;
	y += ystep;
	cout << "x:" << x << " y:" << y << endl;
}

void changeSize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspectRatio = (float)w / (float)h;
	if (w <= h)
	{
		windowWidth = 100;
		windowHeight = 100 / aspectRatio;
		glOrtho(-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
	}
	else
	{
		windowWidth = 100 * aspectRatio;
		windowHeight = 100;
		glOrtho(-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
	}
}

void setupRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	//gluOrtho2D(-100.0, 100.0, -100, 100.0);


}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Hello OpenGL");
	glutDisplayFunc(renderScene);
	glutTimerFunc(33, timerFunction, 1);


	glutReshapeFunc(changeSize);



	setupRC();

	glutMainLoop();
	

	return 0;
}