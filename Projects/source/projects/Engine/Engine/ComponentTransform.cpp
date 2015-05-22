#include "KECS.h"
#include <iostream>

namespace KECS{
	ComponentTransform::ComponentTransform() :ComponentBase(ID_COMPONENT_TRANSFORM)
	{
	}


	ComponentTransform::~ComponentTransform()
	{
	}

	// TODO PrintPos function
	/*
	void PrintPos(ComponentTransform *trans){
	sf::Vector3f playerPos = trans->position();
	std::cout << "playerPos: (" << playerPos.x;
	std::cout << ", " << playerPos.y;
	std::cout << ", " << playerPos.z << ")" << std::endl;
	}
	*/
}
