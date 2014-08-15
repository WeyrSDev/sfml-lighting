/***********************************************************************
     * File       : source.cpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * StaticLightSource
     * constructor

***********************************************************************/
StaticLightSource::StaticLightSource(sf::Vector2i _position, sf::Color _color, char _intensity) {
	position  = _position;
	color     = _color;
	intensity = _intensity;
}



/***********************************************************************
     * FadingLightSource
     * constructor

***********************************************************************/
FadingLightSource::FadingLightSource(sf::Vector2i _position, sf::Color _color, char _intensity, float _lifetime) : StaticLightSource(_position, _color, _intensity) {
	lifetime = _lifetime;
}



/***********************************************************************
     * PulsingLightSource
     * constructor

***********************************************************************/
PulsingLightSource::PulsingLightSource(sf::Vector2i _position, sf::Color _color, char _intensity, float _period) : StaticLightSource(_position, _color, _intensity) {
	period = _period;
}



/***********************************************************************
     * FadingLightSource
     * update

***********************************************************************/
bool FadingLightSource::update() {
	life           += frameClock;
	actualIntensity = (char)(intensity * (lifetime - life) / lifetime);

	return !over();
}



/***********************************************************************
     * PulsingLightSource
     * update

***********************************************************************/
bool PulsingLightSource::update() {
	life           += frameClock;
	actualIntensity = (char)(intensity * abs(cos(3.1415926 * (life / period))));

	return !over();
}
