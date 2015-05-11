#include <stdio.h>
#include "vector2D.h"
//#include <math.h>
#include "entity.h"

Entity::Entity(Vector2D ipos){
	pos = ipos;
}

void Entity::SayHello(){
	printf("Vector2D( %f , %f )\n",pos.x,pos.y);
}

