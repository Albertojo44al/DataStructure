#include "Simulation.h"
#include <iostream>
#define FPS 60

Simulation::Simulation(int width, int height, std::string title) {

	window = new RenderWindow(VideoMode(width, height), title);
	window->setFramerateLimit(FPS);
	movements = new Event;
	initializeTextures();
	initializeVehicles();
	Stats();
	loop();
}

void Simulation::loop() {
	while (window->isOpen()) {
		while (window->pollEvent(*movements)) {
			if (movements->type == Event::Closed) {
				window->close();
				exit(1);
			}
		}

		automaticProcess();
		Draw();
	}
}

void Simulation::Draw() {
	window->clear();
	window->draw(*streetS);
	window->draw(queue1.getCar());
	window->draw(*TollS[0]);
	window->draw(*openTollS[0]);
	window->draw(queue2.getCar());
	window->draw(*TollS[1]);
	window->draw(*openTollS[1]);
	window->draw(queue3.getCar());
	window->draw(*TollS[2]);
	window->draw(*openTollS[2]);

	window->draw(*wallS);
	for (int i = 0; i < 5; i++) {
		window->draw(stats[i]);
	}
	window->display();
}

void Simulation::initializeTextures() {
	streetT = new Texture;
	streetT->loadFromFile("Imagenes/Street.png");
	streetS = new Sprite(*streetT);
	streetS->setScale(1400.f / streetT->getSize().x, (float)window->getSize().y / streetT->getSize().y);

	TollT = new Texture;
	TollT->loadFromFile("Imagenes/Toll.png");

	for (int i = 0; i < 3; i++) {
		TollS[i] = new Sprite(*TollT);
		TollS[i]->setScale(240.f / TollT->getSize().x, 190.f / TollT->getSize().y);
	}
	TollS[0]->setPosition(452.f, 187.f);
	TollS[1]->setPosition(242.f, 351.f);
	TollS[2]->setPosition(20.f, 517.f);

	openTollT = new Texture;
	openTollT->loadFromFile("Imagenes/openToll.png");

	for (int i = 0; i < 3; i++) {
		openTollS[i] = new Sprite(*openTollT);
		openTollS[i]->setScale(240.f / openTollT->getSize().x, 190.f / openTollT->getSize().y);
		openTollS[i]->setColor(Color(255, 255, 255, 0));
	}
	openTollS[0]->setPosition(452.f, 187.f);
	openTollS[1]->setPosition(242.f, 351.f);
	openTollS[2]->setPosition(20.f, 517.f);

	twoAxes = new Texture;
	twoAxes->loadFromFile("Imagenes/2axes.png");
	threeAxes = new Texture;
	threeAxes->loadFromFile("Imagenes/3axes.png");
	fourAxes = new Texture;
	fourAxes->loadFromFile("Imagenes/4axes.png");
	fiveAxes = new Texture;
	fiveAxes->loadFromFile("Imagenes/5axes.png");

	vehiclesS[0] = new Sprite(*twoAxes);
	vehiclesS[1] = new Sprite(*threeAxes);
	vehiclesS[2] = new Sprite(*fourAxes);
	vehiclesS[3] = new Sprite(*fiveAxes);

	for (int i = 0; i < 4; i++) {
		vehiclesS[i]->setScale(240.f / twoAxes->getSize().x, 200.f / twoAxes->getSize().y);
	}
	wallT = new Texture;
	wallT->loadFromFile("Imagenes/wall.png");
	wallS = new Sprite(*wallT);
	wallS->setScale(500.f / wallT->getSize().x, (float)window->getSize().x / wallT->getSize().y);
	wallS->setPosition(1200, 0);
}


void Simulation::automaticProcess() {
	if (queue1.getVehicle()->car.getPosition().x != (TollS[0]->getPosition().x + 40) || queue1.Dequeue(20 + rand() % (151 - 20)) == 0) {
		queue1.getVehicle()->car.setPosition(queue1.getVehicle()->car.getPosition().x - 2.f, 140.f);
		if (queue1.getVehicle()->car.getPosition().x < TollS[0]->getPosition().x) {
			TollS[0]->setColor(Color(255, 255, 255, 0));
			openTollS[0]->setColor(Color(255, 255, 255, 255));
			stats[0].setString("Queue 1 \nThe payment was \ncomplete");
			if (queue1.getVehicle()->car.getPosition().x == (TollS[0]->getPosition().x - 10)) {
				money += queue1.getAxes() * 10;
				stats[4].setString("Total : " + std::to_string(money) + "Lps");
			}
		}
		if (queue1.getVehicle()->car.getPosition().x == 0) {
			queue1.Delete();
			random1 = rand() % 4;
			queue1.Queue(new vehicle(random1 + 2, *vehiclesS[random1]));
			queue1.getVehicle()->car.setPosition(1400.f, 140.f);
			openTollS[0]->setColor(Color(255, 255, 255, 0));
			TollS[0]->setColor(Color(255, 255, 255, 255));
			stats[0].setString("Queue 1 \nNumber of axes: " + std::to_string(queue1.getAxes()) + "\nAmount to pay: " + std::to_string(queue1.getAxes() * 10));
		}
	}

	if (queue2.getVehicle()->car.getPosition().x != (TollS[1]->getPosition().x + 40) || queue2.Dequeue(20 + rand() % (151 - 20)) == 0) {
		queue2.getVehicle()->car.setPosition(queue2.getVehicle()->car.getPosition().x - 2.f, 305.f);
		if (queue2.getVehicle()->car.getPosition().x < TollS[1]->getPosition().x) {
			TollS[1]->setColor(Color(255, 255, 255, 0));
			openTollS[1]->setColor(Color(255, 255, 255, 255));
			stats[1].setString("Queue 2 \nThe payment was \ncomplete");
			if (queue2.getVehicle()->car.getPosition().x == TollS[1]->getPosition().x - 10) {
				money += queue2.getAxes() * 10;
				stats[4].setString("Total : " + std::to_string(money) + "Lps");
			}
		}
		if (queue2.getVehicle()->car.getPosition().x == 0) {
			queue2.Delete();
			random2 = rand() % 4;
			queue2.Queue(new vehicle(random2 + 2, *vehiclesS[random2]));
			queue2.getVehicle()->car.setPosition(1400.f, 305.f);
			openTollS[1]->setColor(Color(255, 255, 255, 0));
			TollS[1]->setColor(Color(255, 255, 255, 255));
			stats[1].setString("Queue 2 \nNumber of axes: " + std::to_string(queue2.getAxes()) + "\nAmount to pay: " + std::to_string(queue2.getAxes() * 10));
		}
	}

	if (queue3.getVehicle()->car.getPosition().x != (TollS[2]->getPosition().x + 50) || queue3.Dequeue(20 + rand() % (151 - 20)) == 0) {
		queue3.getVehicle()->car.setPosition(queue3.getVehicle()->car.getPosition().x - 2.f, 450.f);
		if (queue3.getVehicle()->car.getPosition().x < TollS[2]->getPosition().x) {
			TollS[2]->setColor(Color(255, 255, 255, 0));
			openTollS[2]->setColor(Color(255, 255, 255, 255));
			stats[2].setString("Queue 3 \nThe payment was \ncomplete");
			if (queue3.getVehicle()->car.getPosition().x == TollS[2]->getPosition().x - 10) {
				money += queue3.getAxes() * 10;
				stats[4].setString("Total : " + std::to_string(money) + "Lps");
			}
		}
		if (queue3.getVehicle()->car.getPosition().x == 0) {
			queue3.Delete();
			random3 = rand() % 4;
			queue3.Queue(new vehicle(random3 + 2, *vehiclesS[random3]));
			queue3.getVehicle()->car.setPosition(1400.f, 450.f);
			openTollS[2]->setColor(Color(255, 255, 255, 0));
			TollS[2]->setColor(Color(255, 255, 255, 255));
			stats[2].setString("Queue 3 \nNumber of axes: " + std::to_string(queue3.getAxes()) + "\nAmount to pay: " + std::to_string(queue3.getAxes() * 10));
		}
	}

}

void Simulation::initializeVehicles() {
	//random number from 2 to 5
	random1 = rand() % 4;
	random2 = rand() % 4;
	random3 = rand() % 4;
	//enter two random vehicles to the queue1
	queue1.Queue(new vehicle(random1 + 2, *vehiclesS[random1]));
	queue1.Queue(new vehicle(random2 + 2, *vehiclesS[random2]));
	//enter two random vehicles to the queue2
	queue2.Queue(new vehicle(random2 + 2, *vehiclesS[random2]));
	queue2.Queue(new vehicle(random3 + 2, *vehiclesS[random3]));
	//enter two radom vehicles to the queue3
	queue3.Queue(new vehicle(random1 + 2, *vehiclesS[random1]));
	queue3.Queue(new vehicle(random2 + 2, *vehiclesS[random2]));

	queue1.getVehicle()->car.setPosition(1400.f, 140.f);
	queue2.getVehicle()->car.setPosition(1400.f, 305.f);
	queue3.getVehicle()->car.setPosition(1400.f, 450.f);

}

void Simulation::Stats() {
	font.loadFromFile("Imagenes/Minecraft.ttf");
	for (int i = 0; i < 3; i++) {
		stats[i].setFont(font);
		stats[i].setFillColor(Color::White);
		stats[i].setPosition(1420.f, window->getSize().y / 4 * (i + 1));
		stats[i].setCharacterSize(22);
	}
	stats[0].setString("Queue 1\n axes: " + std::to_string(queue1.getAxes()) + "\nAmount to pay: " + std::to_string(queue1.getAxes() * 10));
	stats[1].setString("Queue 2\n axes: " + std::to_string(queue2.getAxes()) + "\nAmount to pay: " + std::to_string(queue2.getAxes() * 10));
	stats[2].setString("Queue 3\n axes: " + std::to_string(queue3.getAxes()) + "\nAmount to pay: " + std::to_string(queue3.getAxes() * 10));

	stats[3].setFont(font);
	stats[3].setFillColor(Color::White);
	stats[3].setPosition(1500.f, 40.f);
	stats[3].setCharacterSize(40);
	stats[3].setString("Toll");

	stats[4].setFont(font);
	stats[4].setFillColor(Color::White);
	stats[4].setPosition(1420.f, 650.f);
	stats[4].setCharacterSize(35);
	stats[4].setString("Total: " + std::to_string(money) + "Lps");

}