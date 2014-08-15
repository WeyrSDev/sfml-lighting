/***********************************************************************
     * File       : state.hpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEMOSTATE
#define __DEMOSTATE


struct DemoState {
	struct {
		SourceType   type;
		sf::Color    color;
		sf::Vector2i position;
		char         intensity;
		float        sourceTime;
	} brush;

	char      ambientIntensity;
	sf::Color ambientColor;

	StaticLightSource tmpSource;
};

#endif
