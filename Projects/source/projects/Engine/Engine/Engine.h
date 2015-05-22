#ifndef ENGINE_H
#define ENGINE_

#include "KECS.h"

namespace KECS{
	class SystemBase;
	class Entity;

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
		SystemBase **systems;

		int entityCount = 0;
		Entity **entitys;
	};
}
#endif

