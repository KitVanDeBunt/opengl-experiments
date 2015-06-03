#ifndef Entity_H
#define Entity_H

#include <iostream>
#include "ComponentBase.h"

namespace KECS{
	class ComponentBase;
	class Entity{

	// TODO : add name
	public:
		Entity();
		~Entity();
		void AddComponent(ComponentBase *newComponent);
		ComponentBase* GetComponent(std::string);
		virtual void Update();
	private:
		int componentCount = 0;
		ComponentBase **components;
		int i;
	};
}
#endif