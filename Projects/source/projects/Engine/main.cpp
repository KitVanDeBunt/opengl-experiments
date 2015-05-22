// Some text
//
// NOTES
// const std::type_info& ti1 = 
// std::cout << typeid(playerTransform).name() << std::endl;
//
// INSPIRATIONS / HELP
// http://www.caam.rice.edu/~timwar/CAAM420F14/Tex/CAAM420F14_L26supp.pdf
// https://google-styleguide.googlecode.com/svn/trunk/cppguide.html#Comment_Style

#include <iostream>

#include "SFML\System.hpp"
#include "Engine\KECS.h"
#include "ComponentPlayer.h"
#include "ComponentEnemy.h"

using namespace KECS;

const int KEY_T = 19;
const int KEY_W = 22;
const int KEY_S = 18;
const int KEY_A = 0;
const int KEY_D = 3;

float up = 0;
float down = 0;
float left = 0;
float right = 0;

#define PI 3.14159265

void GetInput(bool &running, SystemDisplay *display){
	// get input from sfml window
	sf::Event windowEvent = sf::Event();
	while (display->pollEvent(windowEvent)){
		switch (windowEvent.type){
		case sf::Event::EventType::Closed:
			running = false;
			break;
		case sf::Event::EventType::KeyPressed:
			switch (windowEvent.key.code){
			case KEY_W:
				up = 1;
				break;
			case KEY_S:
				down = -1;
				break;
			case KEY_D:
				right = 1;
				break;
			case KEY_A:
				left = -1;
				break;
			default:
				break;
			}
			break;
		case sf::Event::EventType::KeyReleased:
			switch (windowEvent.key.code) {
			case KEY_T:
				
				break;
			case KEY_W:
				up = 0;
				break;
			case KEY_S:
				down = 0;
				break;
			case KEY_D:
				right = 0;
				break;
			case KEY_A:
				left = 0;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

int main(int, const char**)
{
	Engine engine;

	// create systems
	SystemDisplay *display = new SystemDisplay();

	// add systems to engine
	engine.AddSystem(display);

	// create player
	Entity *player = new Entity();
	ComponentPlayer *componentPlayer = new ComponentPlayer();
	player->AddComponent(componentPlayer);
	engine.AddEntity(player);

	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 15; j++){
			// create npc1
			Entity *npc1 = new Entity();
			ComponentTransform *npcTransform = new ComponentTransform();
			npcTransform->position(sf::Vector3f((-400.0f + (40.0f*i)), (-300.0f + (40.0f*j)), 0));
			npcTransform->scale(sf::Vector3f(20.0f, 20, 20));
			npc1->AddComponent(npcTransform);
			npc1->AddComponent(new ComponentSprite());
			npc1->AddComponent(new ComponentEnemy((ComponentTransform*)player->GetComponent(ID_COMPONENT_TRANSFORM)));
			engine.AddEntity(npc1);
		}
	}


	// initialize engine
	engine.Init();

	bool running = true;

	int frame = 0;

	// game loop
	while (running){

		frame++;

		engine.Update();

		GetInput(running,display);

		componentPlayer->SetInput(up, down, left, right);
		
		std::cout << "FPS: " << (1 / EngineTime::getDeltaTime()) << " FrameTime : " << EngineTime::getDeltaTime() << std::endl;

		// TODO fps limit
		// sf::sleep(sf::seconds(0.1f));
	}
	return 0;
}