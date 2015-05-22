#ifndef COMPONENT_BASE_H
#define COMPONENT_BASE_H

#include <iostream>
#include "Entity.h"

namespace KECS{
	class Entity;
	class ComponentBase{
	friend Entity;
	public:
		ComponentBase(std::string id);
		~ComponentBase();
		std::string getComponentID() const{
			return componentID;
		}
	protected:
		virtual void setComponentID(std::string id){
			componentID = id;
		}

		std::string componentID;
		Entity *_parentEntity;
	private:
		void AddToParent(Entity *parentEntity);
		virtual void Update();
		virtual void Init();
	};
}
#endif

