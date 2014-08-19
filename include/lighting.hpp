/***********************************************************************
     * File       : lighting.hpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __LIGHTING
#define __LIGHTING


MapTile  **lightTiles[LIGHT_MAX_LIGHTLEVEL];
int        lightCounts[LIGHT_MAX_LIGHTLEVEL];
sf::Vertex lightMask[4];


void light();
void resetLight();
void buildLight();
void renderLight();
void setIntensity(MapTile *tile, char intensity, sf::Color color);
void addIntensity(sf::Vector2i index, char intensity, sf::Color color);
void initIntensity(MapTile *tile);
void checkNeighbours(MapTile *tile);
sf::Uint8    getColor(char intensity);
sf::Vector2f getTilePos(int x, int y);
sf::Color    getTileLight(int x, int y);

#endif
