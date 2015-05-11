#include <stdio.h>
#include "vector2D.h"
#include <math.h>

float Magnitude(Vector2D a){
	Vector2D b(0,0);
	float length = a.Dist(b);
	return length;
}

Vector2D::Vector2D(float ix,float iy){
	x = ix;
	y = iy;
}

Vector2D::Vector2D(){
	x = 0;
	y = 0;
}

float Vector2D::Dist(Vector2D v2){
	float dx = x -v2.x;
	float dy = y -v2.y;
	float squareDxDy = (dx*dx)+(dy*dy);
	float dist = sqrt(squareDxDy);
	return dist;
}

void Vector2D::Add(Vector2D add){
	x+=add.x;
	y+=add.y;
}

void Vector2D::Subtract(Vector2D sub){
	x-=sub.x;
	y-=sub.y;
}

void Vector2D::Normalize(){
	Vector2D cur(x,y);
	x =(x /Magnitude(cur));
	y =(y /Magnitude(cur));
}

void Vector2D::Print(){
	printf("( %f , %f )\n",x,y);
}
Vector2D Delta(Vector2D a,Vector2D b){
	Vector2D c(a.x-b.x,a.y-b.y);
	return c;
}

Vector2D Normalized(Vector2D vec){
	float a =vec.x /Magnitude(vec);
	float b =vec.y /Magnitude(vec);
	Vector2D normalized(a,b);
	return normalized;
}

