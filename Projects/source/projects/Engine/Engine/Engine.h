#ifndef ENGINE_H
#define ENGINE_H

#include "SystemBase.h"
#include "Entity.h"

class Engine
{
public:
	Engine();
	~Engine();
	void Init();
	bool Update();
	void AddSystem(SystemBase *system);
	void AddEntity(Entity *entity);
private:
	int systemCount = 0;
	int entityCount = 0;
	SystemBase **systems;
	Entity **entitys;
};

#endif

