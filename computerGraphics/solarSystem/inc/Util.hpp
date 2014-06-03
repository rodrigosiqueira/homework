/**
*	@file Util.hpp
*	@brief This file keeps the vertex properties.
*/

#ifndef _UTIL_HPP_
#define _UTIL_HPP_

/**
*	@class Vertice
*	@brief This class keeps the vertice properties.
*/
class Vertice
{
	public:
		int xCurrent;	/**< X position of our vertex.*/
		int yCurrent;	/**< Y position of our vertex.*/
		int zCurrent;	/**< Z position of our vertex.*/
		double uTextureCoordinate;
		double vTextureCoordinate;
};

#endif
