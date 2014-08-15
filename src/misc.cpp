/***********************************************************************
     * File       : misc.cpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * mixColors

***********************************************************************/
sf::Color mixColors(sf::Color c1, sf::Color c2) {
	sf::Color result;

	result.a = 255;
	result.r = (c1.r > c2.r) ? c1.r : c2.r;
	result.g = (c1.g > c2.g) ? c1.g : c2.g;
	result.b = (c1.b > c2.b) ? c1.b : c2.b;

	return result;
}



/***********************************************************************
     * canMixColors

***********************************************************************/
bool canMixColors(sf::Color base, sf::Color light) {
	if (light.r > base.r) return true;
	if (light.g > base.g) return true;
	if (light.b > base.b) return true;

	return false;
}



/***********************************************************************
     * sqr

***********************************************************************/
float sqr(float x) {
	return x * x;
}

