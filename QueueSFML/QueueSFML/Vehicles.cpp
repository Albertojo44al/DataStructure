#include "vehicle.h"

vehicle::vehicle(int _axes, sf::Sprite _car) {
	axes = _axes;
	car = _car;
	next = 0;
	prev = 0;
}

vehicle::vehicle() {
	next = 0;
	prev = 0;
	axes = 0;
}

int vehicle::getAxes() {
	return this->axes;
}


