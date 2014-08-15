/***********************************************************************
     * File       : demo.hpp
     * Created    : Aug 02, 2013
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEMO
#define __DEMO


#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <math.h>

#include "defines.hpp"
#include "map.hpp"


struct Demo {
	sf::Clock *clock;

	long currentClock;
	long lastClock;
	bool running;
	bool focused;

	Map *map;


	 Demo();
	~Demo();

	void update();
	void render();
	void stop() { running = false; };

	void processEvents();
	void processEvent(sf::Event event);
};


extern float                frameClock;
extern sf::RenderWindow    *app;

#endif
