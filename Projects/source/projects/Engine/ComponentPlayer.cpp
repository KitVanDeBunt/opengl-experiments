
#include "SFML\System.hpp"
#include "Engine\Utils\EngineTime.h"
#include "Engine\Vector2.h"
#include <iostream>

#include "ComponentPlayer.h"
#include "Engine/ComponentTransform.h"
#include "Engine/ComponentSprite.h"

#define PI 3.14159265

ComponentPlayer::ComponentPlayer() :ComponentBase(ID_COMPONENT_PLAYER){
}

ComponentPlayer::~ComponentPlayer(){
}

void ComponentPlayer::Init(){

	// add components to player
	_parentEntity->AddComponent(new ComponentSprite());
	ComponentTransform *playerTransform = new ComponentTransform();
	_parentEntity->AddComponent(playerTransform);

	// set initial player transform 
	playerTransform->scale(sf::Vector3f(25.0f, 25.0f, 25.0f));
}

void ComponentPlayer::Update(){

	ComponentTransform *playerTransform = (ComponentTransform*)_parentEntity->GetComponent(ID_COMPONENT_TRANSFORM);
	if (playerTransform != NULL){

		// new player position
		sf::Vector3f playerPos = playerTransform->position();
		playerPos.x += (_mleft + _mright) * speed * EngineTime::getDeltaTime();
		playerPos.y += (_mup + _mdown) * speed * EngineTime::getDeltaTime();

		// new player rotation
		Vector2 playerVel((_left + _right), (_up + _down));
		float angle = atan2(playerVel.y, playerVel.x) * 180 / PI;
		playerTransform->rotation(sf::Vector3f(0.0f, 0.0f, (angle - 90.0f)));

		// check if player pos needs update
		if (playerTransform->position() != playerPos){
			playerTransform->position(playerPos);  //update player pos
		}
	}
}