/***********************************************************************
     * File       : controls.cpp
     * Created    : Aug 18, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * DemoControls
     * init

***********************************************************************/
void DemoControls::init() {
	auto helloMsg = sfg::Label::Create();
	helloMsg->SetText("Welcome to\nColorful Lighting Demo\nby Achpile");
	helloMsg->SetPosition(sf::Vector2f(820, 20));

	desktop.Add(helloMsg);
}



/***********************************************************************
     * DemoControls
     * render

***********************************************************************/
void DemoControls::render() {
	app->resetGLStates();
	sfgui.Display( *app );
}



/***********************************************************************
     * DemoControls
     * update

***********************************************************************/
void DemoControls::update() {
	desktop.Update(frameClock);
}
