#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include <iostream>
#include "SFML\System\Vector3.hpp"

#include "ComponentBase.h"

namespace KECS{
	class ComponentBase;
	static const std::string ID_COMPONENT_TRANSFORM = "somponent_transform";

	class ComponentTransform : public ComponentBase
	{
	public:
		ComponentTransform();
		~ComponentTransform();

		//position
		sf::Vector3f position() const{
			return position_;
		}
		void position(sf::Vector3f newPosition){
			position_ = newPosition;
		}
		//rotation
		sf::Vector3f rotation() const{
			return rotation_;
		}
		void rotation(sf::Vector3f newRotation){
			rotation_ = newRotation;
		}
		//scale
		sf::Vector3f scale() const{
			return scale_;
		}
		void scale(sf::Vector3f newScale){
			scale_ = newScale;
		}
	private:
		sf::Vector3f position_;
		sf::Vector3f rotation_;
		sf::Vector3f scale_ = sf::Vector3f(1.0f, 1.0f, 1.0f);
	};
}
#endif
