#include "vector2D.h"
#include <stdio.h>
//Vector2D pos1;
Vector2D pos1(0.0f,3.0f);
Vector2D pos2(0.0f,0.0f);
int test(){
	pos1.Print();
	
	pos2.Print();
	printf("Dist %f \n",pos2.Dist(pos1));
	//printf("hello %f %f \n",pos1.x,pos1.y);
	return 0;
}