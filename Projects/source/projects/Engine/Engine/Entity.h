#ifndef Entity_H
#define Entity_H

#include "ComponentBase.h"

class Entity
{
public:
	Entity();
	~Entity();
	void AddComponent(ComponentBase *newComponent);
private:
	//Compement conmponents;
	int componentCount = 0;
	ComponentBase **components;
};

#endif