
#ifndef ENTITY_H
#define ENTITY_H

#include "vector2D.h"
class Entity
{
  //private stuff

public:
	Vector2D pos;
	Entity(Vector2D);
	void SayHello();
};




#endif