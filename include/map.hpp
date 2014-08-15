/***********************************************************************
     * File       : map.hpp
     * Created    : Aug 15, 2016
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MAP
#define __MAP


struct Map {
	sf::Texture *bgTex;
	sf::Sprite  *bgSpr;


	 Map();
	~Map();

	void update();
	void render();
};


#endif
