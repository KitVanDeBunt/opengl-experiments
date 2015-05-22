#include <stdio.h>
#include "Vector2.h"
#include <math.h>

float Magnitude(Vector2 a){
	Vector2 b(0, 0);
	float length = a.Dist(b);
	return length;
}

Vector2::Vector2(float ix, float iy){
	x = ix;
	y = iy;
}

float Vector2::Dist(Vector2 v2){
	float dx = x - v2.x;
	float dy = y - v2.y;
	float squareDxDy = (dx*dx) + (dy*dy);
	float dist = sqrt(squareDxDy);
	return dist;
}

void Vector2::Add(Vector2 add){
	x += add.x;
	y += add.y;
}

void Vector2::Subtract(Vector2 sub){
	x -= sub.x;
	y -= sub.y;
}

void Vector2::Normalize(){
	Vector2 cur(x, y);
	x = (x / Magnitude(cur));
	y = (y / Magnitude(cur));
}

void Vector2::Print(){
	printf("( %f , %f )\n", x, y);
}
Vector2 Delta(Vector2 a, Vector2 b){
	Vector2 c(a.x - b.x, a.y - b.y);
	return c;
}

Vector2 Normalized(Vector2 vec){
	float a = vec.x / Magnitude(vec);
	float b = vec.y / Magnitude(vec);
	Vector2 normalized(a, b);
	return normalized;
}

