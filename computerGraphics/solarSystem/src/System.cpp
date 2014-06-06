/**
* @file System.cpp
*/

#include <GL/gl.h>
#include <GL/glut.h>

#include <System.hpp>
#include <Planet.hpp>

#include <vector>
#include <iostream>

std::vector<Planet> System::planets;

System::System()
{
	std::cout << "SYSTEM" << std::endl;
}

void reshape(int _width, int _height)
{
	std::cout << "RESHAPE" << std::endl;
	glViewport(0, 0, (GLsizei)_width, (GLsizei)_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)_width / (GLfloat)_height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	std::cout << "FINISH RESHAPE" << std::endl;
}

void display(void)
{
	std::cout << "DISPLAY" << std::endl;
	glClearDepth(1);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -10);
	
	std::cout << "STATIC UPDATE PLANETS" << std::endl;
	System::updateAllPlanets();
	std::cout << "SWAP BUFFER" << std::endl;
	//glutSwapBuffers();
}

void System::updateAllPlanets(void)
{
	std::cout << "INSIDE OF UPDATEALLPLANETS" << std::endl;
	std::vector<Planet>::iterator it;
	for(it = System::planets.begin(); it != System::planets.end(); ++it)
	{
		glRotatef((*it).getAngle(), 0, 1, 0);
		(*it).displayPlanet(5);
		glutSwapBuffers();
		(*it).updateAngle();
	}
}

void System::init(void)
{
	std::cout << "INIT()" << std::endl;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
	glCullFace(GL_BACK);			
	glEnable(GL_CULL_FACE);

	//Create the sphere 
	std::vector<Planet>::iterator it;
	for(it = System::planets.begin(); it != System::planets.end(); ++it)
	{
		(*it).createSphere(70, 0, 0, 0);
	}

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	std::cout << "END INIT()" << std::endl;
	glutMainLoop();
}

void System::addPlanet(Planet _planet)
{
	std::cout << "ADD PLANET: " << std::endl;
	System::planets.push_back(_planet);
	std::cout << "Planet added: " << System::planets.size() << std::endl;
}
