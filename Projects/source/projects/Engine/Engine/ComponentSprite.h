#ifndef Component_Base_H
#define Component_Base_H

#include <iostream>

#include "ComponentBase.h"

namespace KECS{
	class ComponentBase;

	static const std::string ID_COMPONENT_SPRITE = "component_sprite";

	class ComponentSprite :
		public ComponentBase
	{
	public:
		ComponentSprite();
		~ComponentSprite();
	};
}
#endif
