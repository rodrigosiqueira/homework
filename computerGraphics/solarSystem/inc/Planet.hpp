/**
*	@file Planet.hpp
*	@brief This file keeps the current properties for the planets
*/

#ifndef _PLANET_HPP_
#define _PLANET_HPP_

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
		const int totalAmountOfVertices;
		Vertice * setOfAllVertices;
		GLuint texture[1];
		double positionAngle;

		String name;
		
	public:
		Planet(String _name);
		virtual ~Planet();
		GLuint loadTexture(const char * _fileName);
		void displayPlanet(double _size, GUint _texture);	//Note: displaySphere
		void createSphere(double _subdivion, _tHorizontal, _tVertical, _tZaxis);
		void updateAngle(int _angle = 1);
		int getAngle(void);
};

#endif
