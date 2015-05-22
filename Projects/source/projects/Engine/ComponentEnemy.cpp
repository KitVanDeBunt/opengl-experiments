
#include "SFML\System.hpp"
#include "Engine\Utils\EngineTime.h"
#include "Engine\Vector2.h"
#include <iostream>

#include "ComponentEnemy.h"
#include "Engine/ComponentTransform.h"
#include "Engine/ComponentSprite.h"

#define PI 3.14159265

ComponentEnemy::ComponentEnemy(ComponentTransform *target) :ComponentBase(ID_COMPONENT_ENEMY){
	_target = target;
}

ComponentEnemy::~ComponentEnemy(){
}

void ComponentEnemy::Init(){

	selfTrans = (ComponentTransform*)_parentEntity->GetComponent(ID_COMPONENT_TRANSFORM);
	playerPos = _target->position();
	selfPos = selfTrans->position();
}

void ComponentEnemy::Update(){

	// new player pos
	playerPos = _target->position();

	// new npc rotation
	selfPos = selfTrans->position();
	float angle = atan2(playerPos.y - selfPos.y, playerPos.x - selfPos.x) * 180 / PI;
	selfTrans->rotation(sf::Vector3f(0.0f, 0.0f, (angle - 90.0f)));
}