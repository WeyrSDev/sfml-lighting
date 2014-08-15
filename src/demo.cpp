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

	map = new Map;
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

	processEvents();

	app->clear();
	render();
	app->display();
}



/***********************************************************************
     * Demo
     * render

***********************************************************************/
void Demo::render() {
	map->update();
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
	}
}
