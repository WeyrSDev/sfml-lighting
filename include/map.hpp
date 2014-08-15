/***********************************************************************
     * File       : map.hpp
     * Created    : Aug 15, 2016
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MAP
#define __MAP


enum MapTileType {
	mtAir,
	mtWall,
	mtSolid
};



struct MapTile {
	MapTileType  type;
	sf::Color    light;
	sf::Vector2i index;
	char         intensity;
	char         absorb;
};



struct Map {
	sf::Texture *bgTex;
	sf::Sprite  *bgSpr;

	sf::Texture *tileTex;
	sf::Sprite  *tileSpr;

	char      ambientIntensity;
	sf::Color ambientColor;

	std::vector<StaticLightSource *> sources;
	MapTile tiles[MAP_SIZE_X][MAP_SIZE_Y];

	 Map();
	~Map();

	void update(StaticLightSource *tmpSource);
	void checkSources(StaticLightSource *tmpSource);
	void render();
	void renderTiles();
	void clear() {deleteList(sources); };

	#include "lighting.hpp"
};


#endif
