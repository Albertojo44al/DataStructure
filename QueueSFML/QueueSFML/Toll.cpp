
#include "Toll.h"
#include <iostream>
Toll::Toll() {
	first = 0;
	last = 0;
}

int Toll::getAxes() {
	return first->getAxes();
}

sf::Sprite Toll::getCar() {
	return first->car;
}
vehicle* Toll::getVehicle() {
	return first;
}

bool Toll::Empty() {
	if (first == 0)
		return true;
	return false;
}

int Toll::Queue(vehicle* vehicle) {
	if (Empty()) {
		first = vehicle;
		last = vehicle;
	}
	else {
		last->next = vehicle;
		vehicle->prev = last;
		last = vehicle;
	}
	return 0;
}

int Toll::Dequeue(double pay) {
	if (Empty())
		return -1;
	else if (first->next == 0) {
		delete first;
		first = 0;
		last = 0;
		return 0;
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (first->getAxes() == i && pay == (i * 10)) {
				return 0;
			}
		}
		if (first->getAxes() > 6 && pay == (60)) {
			return 0;
		}
		return -2;
	}
}

void Toll::Delete() {
	vehicle * tmp = first;
	tmp->next->prev = 0;
	first = first->next;
	delete tmp;
}

void Toll::Print() {
	vehicle* tmp = first;
	while (tmp != 0) {
		printf("number of axes: %d\n", tmp->getAxes());
		tmp = tmp->next;
	}
}
int Toll::counter() {
	vehicle * tmp = first;
	int c = 0;
	while (tmp != 0) {
		c++;
		tmp = tmp->next;
	}
	return c;
}