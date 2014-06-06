/**
*	@file Planet.hpp
*	@brief This file keeps the current properties for the planets
*/

#ifndef _PLANET_HPP_
#define _PLANET_HPP_

#include <string>

#include <GL/gl.h>
#include <Util.hpp>

/**
*	@class Planet
* @brief This class keep all the details of create a planet.
*/
class Planet
{
	private:
		int spaceBetweenVertices;
		int totalAmountOfVertices;
		Vertice * setOfAllVertices;
		GLuint texture[1];
		double positionAngle;

		std::string name;
		
	public:
		Planet(std::string _name);
		virtual ~Planet();
		void loadTexture(const char * _fileName);
		void displayPlanet(double _sizei);	//Note: displaySphere
		void createSphere(double _subdivion, double _tHorizontal, double _tVertical, double _tZaxis);
		void updateAngle(int _angle = 1);
		int getAngle(void);
};

#endif
