/**
*	@file System.hpp
*	@brief 
*/
#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include <vector>

#include <Planet.hpp>

/**
*	@class System
*/
class System
{
	private:	
		static std::vector<Planet> planets;
		void displayAllPlanets();
		
	public:
		System();

		void addPlanet(Planet _planet);
		void init(void);
		//void reshape(int _width, int _height);
		//void display(void);
		static void updateAllPlanets(void);
};

//extern std::vector<Planet> System::planets;

#endif
