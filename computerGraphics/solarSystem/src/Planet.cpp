/**
*	@file Planet.cpp
*	@brief Implementation of the functions related with planet.
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include <Planet.hpp>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

Planet::Planet(std::string _name)
{
	std::cout << "PLANET " << std::endl;
	this->name = _name;
	this->positionAngle = 0;
	this->spaceBetweenVertices = 10;
	this->totalAmountOfVertices = (90 / this->spaceBetweenVertices) * 
					(360 / this->spaceBetweenVertices) * 4;
	this->setOfAllVertices = new Vertice[this->totalAmountOfVertices];
}

Planet::~Planet()
{
	delete[] this->setOfAllVertices;
}

void Planet::loadTexture(const char * _fileName)
{
	GLuint texture;
	int width = 0, height = 0;
	unsigned char * data = 0;

	FILE * file = 0;

	file = fopen(_fileName, "rb");
	if(file == NULL)
	{
		return;
	}
	
	std::cout << "LOAD TEXTURE" << std::endl;

	width = 1024;
	height = 512;
	data = (unsigned char *) malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);

	this->texture[0] = texture;
}

void Planet::displayPlanet(double _size)
{
	std::cout << "INSIDE OF DISPLAY PLANET" << std::endl;
	//Control which vertex we are currently working with
	int b;
	glScalef(0.0125 * _size, 0.0125 * _size, 0.0125 * _size);
	glRotatef(90, 1, 0, 0);	//Rotating it.
	glBindTexture(GL_TEXTURE_2D, this->texture[0]); //Bind the texture we inputted above
	glBegin(GL_TRIANGLE_STRIP); //Triangle strips as they are the faster shape for it

	std::cout << "BEFORE THE LOOP FOR ALL VERTICES" << std::endl;
	//Looping through each vertex. This is just one half
	for (b = 0; b <= this->totalAmountOfVertices; b++)
	{
		//Assign the texture coordinates of the current vertex
		glTexCoord2f(this->setOfAllVertices[b].u, this->setOfAllVertices[b].v);
		glVertex3f(this->setOfAllVertices[b].x, this->setOfAllVertices[b].y, 
			-(this->setOfAllVertices[b].z));
	}

	//This is the second half of the sphere.
	for (b = 0; b <= this->totalAmountOfVertices; b++)
	{
		glTexCoord2f(this->setOfAllVertices[b].u, -(this->setOfAllVertices[b].v));
		glVertex3f(this->setOfAllVertices[b].x, this->setOfAllVertices[b].y, 
			this->setOfAllVertices[b].z);
	}

	glEnd();
}

void Planet::createSphere(double _subdivion, double _tHorizontal, double _tVertical, double _tZaxis)
{
	int n = 0;
	double a;
	double b;
	std::cout << "CRETATE SPHERE" << std::endl;
	//Assign our b loop to go through 90 degrees in intervals of our variable space	
	for(b = 0; b <= 90 - this->spaceBetweenVertices; b += this->spaceBetweenVertices)
	{
		//Assign our a loop to go through 360 degrees in intervals of our variable space
		for(a = 0; a <= 360 - this->spaceBetweenVertices; a += this->spaceBetweenVertices)
		{
			//Calculating X, Y and Z calculation
			this->setOfAllVertices[n].x = _subdivion * sin((a) / 180 * M_PI) 
						* sin((b) / 180 * M_PI) - _tHorizontal;

			this->setOfAllVertices[n].y = _subdivion * cos((a) / 180 * M_PI) 
						* sin((b) / 180 * M_PI) + _tVertical;
			this->setOfAllVertices[n].z = _subdivion * cos((b) / 180 * M_PI) 
						- _tZaxis;
			//Calculating the texture coordinates.
			this->setOfAllVertices[n].v = (2 * b) / 360;
			this->setOfAllVertices[n].u = (a) / 360;
			//Working with the next vertex
			n++;

			//Now add a space variable for the first parameter
			this->setOfAllVertices[n].x = _subdivion * sin((a) / 180 * M_PI) 
						* sin((b + this->spaceBetweenVertices) / 180 * M_PI) - _tHorizontal;
			this->setOfAllVertices[n].y = _subdivion * cos((a) / 180 * M_PI) 
						* sin((b + this->spaceBetweenVertices) / 180 * M_PI) + _tVertical;
			this->setOfAllVertices[n].z = _subdivion * cos((b + this->spaceBetweenVertices) 
						/ 180 * M_PI) - _tZaxis;
			//Calculating the texture coordinates.
			this->setOfAllVertices[n].v = (2 * (b + this->spaceBetweenVertices)) / 360;
			this->setOfAllVertices[n].u = (a) / 360;
			n++;

			this->setOfAllVertices[n].x = _subdivion * sin((a + this->spaceBetweenVertices) 
					/ 180 * M_PI) * sin((b) / 180 * M_PI) - _tHorizontal;
			this->setOfAllVertices[n].y = _subdivion * cos((a + this->spaceBetweenVertices) 
					/ 180 * M_PI) * sin((b) / 180 * M_PI) + _tVertical;
			this->setOfAllVertices[n].z = _subdivion * cos((b) / 180 * M_PI) - _tZaxis;
			this->setOfAllVertices[n].v = (2 * b) / 360;
			this->setOfAllVertices[n].u = (a + this->spaceBetweenVertices) / 360;
			n++;
			//Now add a space variable for the first and second parameter
			this->setOfAllVertices[n].x = _subdivion * sin((a + this->spaceBetweenVertices) 
					/ 180 * M_PI) * sin ((b + this->spaceBetweenVertices) / 180 * M_PI) - _tHorizontal;
			this->setOfAllVertices[n].y = _subdivion * cos((a + this->spaceBetweenVertices) 
					/ 180 * M_PI) * sin ((b + this->spaceBetweenVertices) / 180 * M_PI) + _tVertical;
			this->setOfAllVertices[n].z = _subdivion * cos((b + this->spaceBetweenVertices) 
					/ 180 * M_PI) - _tZaxis;
			this->setOfAllVertices[n].v = (2 * (b + this->spaceBetweenVertices)) / 360;
			this->setOfAllVertices[n].u = (a + this->spaceBetweenVertices) / 360;
			n++;
		}
	}
}

void Planet::updateAngle(int _angle)
{
	std::cout << "UPDATE ANGLE" << std::endl;
	this->positionAngle++;
	std::cout << "ANGLE: " << this->positionAngle << std::endl;
}

int Planet::getAngle(void)
{
	std::cout << "GET ANGLE" << std::endl;
	std::cout << "GET ANGLE: " << this->positionAngle << std::endl;
	return this->positionAngle;
}
