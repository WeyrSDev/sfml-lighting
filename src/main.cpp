/***********************************************************************
     * File       : main.cpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * Global variables

***********************************************************************/
float             frameClock;
sf::RenderWindow *app;
Demo             *demo;



/***********************************************************************
     * Main function

***********************************************************************/
int main() {
	demo = new Demo;
	srand(time(NULL));

	while(demo->running) demo->update();
	delete demo;

	return EXIT_SUCCESS;
}
