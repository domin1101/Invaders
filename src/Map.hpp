#pragma once

#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <vector>
#include <memory>
#include "AbstractTile.hpp"
#include "Player.hpp"

class Map 
{
private:
	std::vector<std::vector<std::unique_ptr<AbstractTile>>> tiles;
	int width;
	int height;
	sf::Vector2f tileSize;
public:
	Map(int width_, int height_);
	int draw(sf::RenderWindow& window, int offsetY);
	bool isTileWalkable(sf::Vector2i pos) const;
	const sf::Vector2f& getTileSize() const;
	int getHeight();
	int getWidth();
};

#endif