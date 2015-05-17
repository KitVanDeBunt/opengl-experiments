#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H

//#include "Engine.h"
#include "Entity.h"

class SystemBase
{
public:
	SystemBase();
	~SystemBase();

	virtual void Update() = 0;
	virtual void Init() = 0;

	Entity **entitys;
	int *entityCount;

//private:
	//Engine &engine_ = 0;
};
#endif

