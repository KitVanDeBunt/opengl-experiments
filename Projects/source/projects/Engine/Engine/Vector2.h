
#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	float x, y;
	Vector2(float, float);
	float Dist(Vector2);
	void Add(Vector2);
	void Subtract(Vector2);
	void Normalize();
	void Print();
};

Vector2 Delta(Vector2, Vector2);
Vector2 Normalized(Vector2);
#endif