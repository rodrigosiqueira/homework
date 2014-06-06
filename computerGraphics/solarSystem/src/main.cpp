/**
*	@file main.cpp
*/

#include <GL/gl.h>
#include <GL/glut.h>

#include <iostream>

#include <Planet.hpp>
#include <System.hpp>

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System");

	//Create Planets
	std::cout << "CREATE PLANET" << std::endl;
	Planet earth("Earth");
	std::cout << "LOAD TEXTURE";
	earth.loadTexture("earth.raw");
	std::cout << "CREATE SOLAR SYSTEM" << std::endl;
	//Create a solar system
	System solarSystem;

	std::cout << "ADD PLANET" << std::endl;
	solarSystem.addPlanet(earth);

	//Display
	std::cout << "INIT SYTEM" << std::endl;
	solarSystem.init();
	std::cout << "MAIN LOOP" << std::endl;

	return 0;
}
