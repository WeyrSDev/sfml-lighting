/***********************************************************************
     * File       : lighting.cpp
     * Created    : Aug 15, 2014
     * Copyright  : (C) 2014 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "demo.hpp"



/***********************************************************************
     * Map
     * addIntensity

***********************************************************************/
void Map::addIntensity(sf::Vector2i index, char intensity, sf::Color color) {
	if (index.x < 0 || index.x >= MAP_SIZE_X || index.y < 0 || index.y >= MAP_SIZE_X)
		return;

	color = applyIntensity(color, intensity);
	tiles[index.x][index.y].light = mixColors(tiles[index.x][index.y].light, color);

	if (tiles[index.x][index.y].intensity < intensity)
		tiles[index.x][index.y].intensity = intensity;
}



/***********************************************************************
     * Map
     * initIntensity

***********************************************************************/
void Map::initIntensity(MapTile *tile) {
	int index = tile->intensity - 1;
	if (index < 0 || index >= LIGHT_MAX_LIGHTLEVEL) return;

	lightTiles[index][lightCounts[index]++] = tile;
}



/***********************************************************************
     * Map
     * setIntensity

***********************************************************************/
void Map::setIntensity(MapTile *tile, char intensity, sf::Color color) {
	if (intensity > tile->intensity || canMixColors(tile->light, color)) {
		tile->light = mixColors(tile->light, color);

		if (intensity != tile->intensity) {
			tile->intensity = intensity;

			int index = tile->intensity - 1;

			if (index < 0) return;
			if (index >= LIGHT_MAX_LIGHTLEVEL) return;

			lightTiles[index][lightCounts[index]] = tile;
			lightCounts[index]++;
		}
	}
}



/***********************************************************************
     * Map
     * checkNeighbours

***********************************************************************/
void Map::checkNeighbours(MapTile *tile) {
	int x = tile->index.x;
	int y = tile->index.y;

	char intensity = tile->intensity - tile->absorb;
	if (intensity < 0) return;
	sf::Color color = reapplyIntensity(tile->light, tile->intensity, intensity);

	if (x > 0             ) setIntensity(&tiles[x-1][y], intensity, color);
	if (x < MAP_SIZE_X - 1) setIntensity(&tiles[x+1][y], intensity, color);
	if (y > 0             ) setIntensity(&tiles[x][y-1], intensity, color);
	if (y < MAP_SIZE_Y - 1) setIntensity(&tiles[x][y+1], intensity, color);


	color.r *= 0.9f;
	color.g *= 0.9f;
	color.b *= 0.9f;

	if (x > 0              && y < MAP_SIZE_Y - 1) setIntensity(&tiles[x-1][y+1], intensity, color);
	if (x < MAP_SIZE_X - 1 && y > 0             ) setIntensity(&tiles[x+1][y-1], intensity, color);
	if (y > 0              && x > 0             ) setIntensity(&tiles[x-1][y-1], intensity, color);
	if (y < MAP_SIZE_Y - 1 && x < MAP_SIZE_X - 1) setIntensity(&tiles[x+1][y+1], intensity, color);
}



/***********************************************************************
     * Map
     * light

***********************************************************************/
void Map::light() {
	buildLight();
	renderLight();
}



/***********************************************************************
     * Map
     * resetLight

***********************************************************************/
void Map::resetLight() {
	sf::Vector2i from(0, 0);
	sf::Vector2i to(MAP_SIZE_X, MAP_SIZE_Y);
	sf::Color    color = applyIntensity(ambientColor, ambientIntensity);


	for (int i = 0; i < LIGHT_MAX_LIGHTLEVEL; lightCounts[i++] = 0);
	for (int i = from.x; i < to.x; i++)
		for (int j = from.y; j < to.y; j++)
			if (tiles[i][j].type == mtAir) {
				tiles[i][j].intensity = ambientIntensity;
				tiles[i][j].light     = color;
			} else {
				tiles[i][j].intensity = 0;
				tiles[i][j].light     = sf::Color::Black;
			}
}



/***********************************************************************
     * Map
     * buildLight

***********************************************************************/
void Map::buildLight() {
	sf::Vector2i from(0, 0);
	sf::Vector2i to(MAP_SIZE_X, MAP_SIZE_Y);

	for (int i = from.x; i < to.x; i++)
		for (int j = from.y; j < to.y; j++)
			initIntensity(&tiles[i][j]);

	for (int i = LIGHT_MAX_LIGHTLEVEL - 1; i >= 0; i--)
		for (int j = 0; j < lightCounts[i]; j++) {
			if (lightTiles[i][j]->intensity != i + 1) continue;
			checkNeighbours(lightTiles[i][j]);
		}
}



/***********************************************************************
     * Map
     * getTilePos

***********************************************************************/
sf::Vector2f Map::getTilePos(int x, int y) {
	return sf::Vector2f(TILE_SIZE / 2.0f + TILE_SIZE * x, TILE_SIZE / 2.0f + TILE_SIZE * y);
}



/***********************************************************************
     * Map
     * getTileColor

***********************************************************************/
sf::Color Map::getTileLight(int x, int y) {
	if (x < 0) x = 0;
	if (y < 0) y = 0;
	if (x >= MAP_SIZE_X) x = MAP_SIZE_X - 1;
	if (y >= MAP_SIZE_Y) y = MAP_SIZE_Y - 1;

	return tiles[x][y].light;
}



/***********************************************************************
     * Map
     * renderLight

***********************************************************************/
void Map::renderLight() {
	sf::Vector2i from(0, 0);
	sf::Vector2i to(MAP_SIZE_X, MAP_SIZE_Y);

	for (int i = from.x - 1; i < to.x; i++)
		for (int j = from.y - 1; j < to.y; j++) {
			lightMask[0].position = getTilePos(i  , j  );
			lightMask[1].position = getTilePos(i+1, j  );
			lightMask[2].position = getTilePos(i+1, j+1);
			lightMask[3].position = getTilePos(i  , j+1);

			lightMask[0].color = getTileLight(i  , j  );
			lightMask[1].color = getTileLight(i+1, j  );
			lightMask[2].color = getTileLight(i+1, j+1);
			lightMask[3].color = getTileLight(i  , j+1);

			app->draw(lightMask, 4, sf::Quads, sf::BlendMultiply);
		}
}
