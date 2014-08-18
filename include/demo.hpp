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
#include <SFGUI/SFGUI.hpp>
#include <stdio.h>
#include <math.h>

#include "defines.hpp"
#include "misc.hpp"
#include "source.hpp"
#include "state.hpp"
#include "controls.hpp"
#include "map.hpp"


struct Demo {
	sf::Clock *clock;

	long currentClock;
	long lastClock;
	bool running;
	bool focused;

	DemoState     state;
	DemoControls  controls;
	Map          *map;


	 Demo();
	~Demo();

	void update();
	void render();
	void stop() { running = false; };

	void processEvents();
	void processEvent(sf::Event event);

	void addSource();
};


extern float                frameClock;
extern sf::RenderWindow    *app;
extern sfg::SFGUI           sfgui;
extern Demo                *demo;

#endif
