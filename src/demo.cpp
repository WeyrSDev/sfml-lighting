/***********************************************************************
     * File       : demo.cpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * Demo
     * constructor

***********************************************************************/
Demo::Demo() {
	clock = new sf::Clock;
	app   = new sf::RenderWindow(sf::VideoMode(1000, 608, 32), "SFML Lighting demo by Achpile", sf::Style::Close);

	running   = true;
	lastClock = clock->getElapsedTime().asMilliseconds();
	controls.init();

	map = new Map;


	state.brush.type       = stStatic;
	state.brush.color      = sf::Color::Red;
	state.brush.intensity  = LIGHT_MAX_LIGHTLEVEL;
	state.brush.sourceTime = 2.0f;

	state.ambientColor     = sf::Color::White;
	state.ambientIntensity = 5;
}



/***********************************************************************
     * Demo
     * destructor

***********************************************************************/
Demo::~Demo() {
	delete map;
	delete clock;
	delete app;
}



/***********************************************************************
     * Demo
     * update

***********************************************************************/
void Demo::update() {
	currentClock = clock->getElapsedTime().asMilliseconds();
	frameClock = (currentClock - lastClock) / 1000.0;
	lastClock = currentClock;

	state.brush.position = sf::Vector2i(sf::Mouse::getPosition(*app) / TILE_SIZE);
	state.tmpSource = StaticLightSource(state.brush.position, state.brush.color, state.brush.intensity);

	map->ambientColor     = state.ambientColor;
	map->ambientIntensity = state.ambientIntensity;

	processEvents();
	controls.update();


	app->clear();
	render();
	app->display();
}



/***********************************************************************
     * Demo
     * render

***********************************************************************/
void Demo::render() {
	controls.render();
	map->update(&state.tmpSource);
}



/***********************************************************************
     * Demo
     * processEvents

***********************************************************************/
void Demo::processEvents() {
	sf::Event event;
	while (app->pollEvent(event)) processEvent(event);

	if (!app->isOpen()) running = false;
}



/***********************************************************************
     * Demo
     * processEvent

***********************************************************************/
void Demo::processEvent(sf::Event event) {
	switch(event.type) {
		case sf::Event::Closed:
			stop();
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left) addSource();
			if (event.mouseButton.button == sf::Mouse::Right) map->clear();
			break;
	}
}



/***********************************************************************
     * Demo
     * addSource

***********************************************************************/
void Demo::addSource() {
	switch (state.brush.type) {
		case stStatic:
			map->sources.push_back((StaticLightSource *)(new StaticLightSource(state.brush.position, state.brush.color, state.brush.intensity)));
			break;

		case stFading:
			map->sources.push_back((StaticLightSource *)(new FadingLightSource(state.brush.position, state.brush.color, state.brush.intensity, state.brush.sourceTime)));
			break;

		case stPulsing:
			map->sources.push_back((StaticLightSource *)(new PulsingLightSource(state.brush.position, state.brush.color, state.brush.intensity, state.brush.sourceTime)));
			break;
	}
}
