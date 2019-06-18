#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

class vehicle {
public:
	int axes;
	sf::Sprite car;
	vehicle();
	vehicle(int, sf::Sprite);
	vehicle* next;
	vehicle* prev;

	int getAxes();
};
