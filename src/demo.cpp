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
	app   = new sf::RenderWindow(sf::VideoMode(940, 480, 32), "SFML Lighting demo by Achpile", sf::Style::Close);

	running   = true;
	lastClock = clock->getElapsedTime().asMilliseconds();
}



/***********************************************************************
     * Demo
     * destructor

***********************************************************************/
Demo::~Demo() {
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
	app->display();
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
