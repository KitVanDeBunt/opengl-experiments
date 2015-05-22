#ifndef Component_Enemy_H
#define Component_Enemy_H

#include <iostream>

#include "Engine/ComponentBase.h"
#include "Engine/ComponentTransform.h"

using namespace KECS;
static const std::string ID_COMPONENT_ENEMY = "component_enemy";

class ComponentEnemy :
	public ComponentBase
{
public:
	ComponentEnemy(ComponentTransform *target);
	~ComponentEnemy();
	
private:
	virtual void Update();
	virtual void Init();
	ComponentTransform  *_target;
	ComponentTransform *selfTrans;
	sf::Vector3f playerPos;
	sf::Vector3f selfPos;
};

#endif
