/***********************************************************************
     * File       : source.hpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SOURCE
#define __SOURCE


enum SourceType {
	stStatic,
	stFading,
	stPulsing
};



struct StaticLightSource {
	sf::Vector2i position;
	sf::Color    color;
	char         intensity;
	char         actualIntensity;


	StaticLightSource(sf::Vector2i _position, sf::Color _color, char _intensity);

	virtual bool update()       {return !over();         };
	virtual char getIntensity() {return actualIntensity; };
	virtual bool over()         {return false;           };
};



struct FadingLightSource : StaticLightSource {
	float lifetime;
	float life;


	FadingLightSource(sf::Vector2i _position, sf::Color _color, char _intensity, float _lifetime);

	bool update();
	bool over() {return (life > lifetime); };
};



struct PulsingLightSource : StaticLightSource {
	float period;
	float life;


	PulsingLightSource(sf::Vector2i _position, sf::Color _color, char _intensity, float _period);

	bool update();
	bool over() {return false; };
};

#endif
