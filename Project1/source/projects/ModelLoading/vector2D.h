
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
  //private stuff

public:
	float x,y;
	Vector2D(float, float);
	Vector2D();
	float Dist(Vector2D);
	void Add(Vector2D);
	void Subtract(Vector2D);
	void Normalize();
	void Print();
};

Vector2D Delta(Vector2D,Vector2D);
Vector2D Normalized(Vector2D);


#endif