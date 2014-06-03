/**
* @file System.cpp
*/

#include <GL/gl.h>
#include <GL/glut.h>

#include <System.hpp>
#include <Planet.hpp>

#include <verctor>

System::System(vector<Planet> _listOfPlanet)
{
	this->planet = _listOfPlanet;
}

void System::init(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	glCullFace(GL_BACK);			
	glEnable(GL_CULL_FACE);

	//texture[0] = LoadTextureRAW("earth.raw"); //<<<------ Load texture
	//Create the sphere 
	std::vector<Planet *>::iterator it;
	for(it = this->planets.begin(); it != this->planets.end(); ++it)
	{
		(*it)->createSphere(70, 0, 0, 0);
	}
}

void System::reshape(int _width, int _height)
{
	glViewport(0, 0, (GLsizei)_width, (GLsizei)_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)_width / (GLfloat)_height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void System::display(void)
{
	glClearDepth(1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -10);
	std::vector<Planet *>::iterator it;
	for(it = this->planets.begin(); it != this->planets.end(); ++it)
	{
		glRotatef((*it)->getAngle(), 0, 1, 0);
		(*it)->displayPlanet(5);
		//glutSwapBuffers();
		*(it)->updateAngle();
	}
	glutSwapBuffers();
	//glRotatef(angle, 0, 1, 0);	//<<--------
	//DisplaySphere(5, texture[0]);	//<<------
	//glutSwapBuffers();	//<<----------------
	//angle++;	//<<--------------------------
}

