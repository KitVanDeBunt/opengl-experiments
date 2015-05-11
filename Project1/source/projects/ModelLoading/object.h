#ifndef OBJECTS_H
#define OBJECTS_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>
#include "myTypes.h"

class Object
{
	//private stuff
	std::vector< glm::vec3 > temp_vertices;
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	// This will identify our vertex buffer
	GLuint vertexbuffer;
	GLuint elementbuffer;
	int vertices;
	DrawType drawType;
public:
	float x,y,z;
	Object(std::string,float,float,float,DrawType);
	void draw();
	//float Dist(Vector2D);
	//void Add(Vector2D);
	//void Print();
};

#endif
