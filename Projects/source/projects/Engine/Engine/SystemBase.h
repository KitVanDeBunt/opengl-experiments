

#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H

#include "Entity.h"

namespace KECS{
	class Entity;

	class SystemBase
	{
	public:
		SystemBase();
		~SystemBase();

		virtual void Update() = 0;
		virtual void Init() = 0;

		Entity ***entitys;
		int *entityCount;
	};
}
#endif

