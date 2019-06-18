#pragma once
#include "SFML/Graphics.hpp"
#include "Toll.h"
using namespace sf;

class Simulation {
private:
	RenderWindow * window;
	Texture * streetT;
	Sprite * streetS;
	Texture * TollT;
	Texture * openTollT;
	Sprite * TollS[3];
	Sprite * openTollS[3];
	Texture * twoAxes;
	Texture * threeAxes;
	Texture * fourAxes;
	Texture * fiveAxes;
	Sprite * vehiclesS[4];
	Event * movements;
	Toll queue1, queue2, queue3;
	int random1, random2, random3; //Queue and Deque vehicles;
	Text stats[5];
	Font font;
	Texture * wallT;
	Sprite * wallS;
	int money = 0;
public:
	Simulation(int width, int height, std::string title);
	void loop();
	void Draw();
	void initializeTextures();
	void automaticProcess();
	void initializeVehicles();
	void Stats();
};

