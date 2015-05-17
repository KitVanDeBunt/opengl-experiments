#include <iostream>

#include "SFML\System.hpp"
#include "Engine\Engine.h"
#include "Engine\SystemDisplay.h"
#include "Engine\ComponentTransform.h"

void PrintPlayerPos();

const int KEY_T = 19;
const int KEY_W = 22;
const int KEY_S = 18;
const int KEY_A = 0;
const int KEY_D = 3;

ComponentTransform *playerTransform;

int main(int, const char**)
{
	Engine engine;

	// create systems
	SystemDisplay *display = new SystemDisplay();

	// add systems to engine
	engine.AddSystem(display);

	// create entitys
	Entity *player = new Entity();
	playerTransform = new ComponentTransform();
	player->AddComponent(playerTransform);

	// add entitys to engine
	engine.AddEntity(player);

	//initialize engine
	engine.Init();

	bool running = true;
	//update engine
	while (running)
	{
		
		sf::sleep(sf::seconds(0.1f));
		engine.Update();

		//input
		sf::Event windowEvent = sf::Event();
		while (display->pollEvent(windowEvent))
		{
			//std::cout << "[Main] --" << windowEvent.type << " " << std::endl;

			sf::Vector3f playerPos = playerTransform->position();

			switch (windowEvent.type)
			{
			case sf::Event::EventType::MouseButtonPressed:

				break;
			case sf::Event::EventType::Closed:
				running = false;
				break;
			case sf::Event::EventType::KeyPressed:
				std::cout << "[Main]" << windowEvent.key.code << std::endl;


				switch (windowEvent.key.code)
				{
				case KEY_T:
					PrintPlayerPos();
					break;
				case KEY_W:
					playerPos.x += 1;
					break;
				case KEY_S:
					playerPos.x -= 1;
					break;
				case KEY_D:
					playerPos.y += 1;
					break;
				case KEY_A:
					playerPos.y -= 1;
					break;
				default:
					break;
				}

				if (playerTransform->position() != playerPos){
					//update player pos
					playerTransform->position(playerPos);
					//print player pos
					PrintPlayerPos();
				}
				break;
			default:
				break;
			}
		}
	}

	return 0;
}

void PrintPlayerPos(){
	sf::Vector3f playerPos = playerTransform->position();
	std::cout << "player X Pos: " << playerPos.x << std::endl;
	std::cout << "player Y Pos: " << playerPos.y << std::endl;
	std::cout << "player Z Pos: " << playerPos.z << std::endl;
}