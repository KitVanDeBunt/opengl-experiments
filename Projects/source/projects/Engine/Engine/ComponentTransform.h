#ifndef COMPONENT_TRANSFORM_H
#define COMPONENT_TRANSFORM_H

#include "ComponentBase.h"

#include "SFML\System\Vector3.hpp"

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
	sf::Vector3f scale_;
};

#endif
