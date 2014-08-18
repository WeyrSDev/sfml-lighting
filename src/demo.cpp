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
	map       = new Map;


	state.brush.type       = stStatic;
	state.brush.color      = sf::Color::Red;
	state.brush.intensity  = LIGHT_MAX_LIGHTLEVEL;
	state.brush.sourceTime = 2.0f;

	state.ambientColor     = sf::Color::White;
	state.ambientIntensity = 5;

	controls.init(&state);
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


	state.ambientIntensity = (char)controls.ambIntensityAdj->GetValue();
	state.ambientColor.r   = (char)controls.ambColR->GetValue();
	state.ambientColor.g   = (char)controls.ambColG->GetValue();
	state.ambientColor.b   = (char)controls.ambColB->GetValue();

	state.brush.intensity  = (char)controls.brIntensityAdj->GetValue();
	state.brush.color.r    = (char)controls.brColR->GetValue();
	state.brush.color.g    = (char)controls.brColG->GetValue();
	state.brush.color.b    = (char)controls.brColB->GetValue();
	state.brush.sourceTime = controls.brTime->GetValue();

	switch(controls.brStyle->GetSelectedItem()) {
		case 0: state.brush.type = stStatic;  break;
		case 1: state.brush.type = stFading;  break;
		case 2: state.brush.type = stPulsing; break;
	}


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
	map->update(&state.tmpSource);
	controls.render();
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
	controls.desktop.HandleEvent(event);

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
	if (! sf::IntRect(0, 0, 800, 608).contains(sf::Mouse::getPosition(*app))) return;

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
