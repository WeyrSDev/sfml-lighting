/***********************************************************************
     * File       : misc_base.hpp
     * Created    : Aug 02, 2013
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_BASE
#define __MISC_BASE


sf::Color mixColors(sf::Color c1, sf::Color c2);
bool canMixColors(sf::Color base, sf::Color light);
float sqr(float x);

void clearSources();

#endif
