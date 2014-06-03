/**
*	@file System.hpp
*	@brief 
*/
#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include <vector>

/**
*	@class System
*/
class System
{
	private:
		std::vector<Planet> planets;
		
	public:
		System(std::vector<Planet> _listOfPlanet);
		void init(void);
		void reshape(int _width, int _height);
		void display(void);
};

#endif
