

#include "SFML\System.hpp"
#include <SFML\Window.hpp>
#include <GL\glew.h>
#include <SFML\OpenGL.hpp>
#include <glm\glm.hpp>
#include <iostream>

#include "SystemDisplay.h"

#define Log std::cout

GLuint vertexbuffer;

GLdouble width, height;


struct Vec3f
{
	float x;
	float y;
	float z;

	Vec3f()
	{
	}

	Vec3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};
SystemDisplay::SystemDisplay()
{
}


SystemDisplay::~SystemDisplay()
{
}

void SystemDisplay::Init(){
	GLenum      err;



	width = 400.0;
	height = 400.0;



	Log << "[Display System]Start" << std::endl;

	if ((err = glewInit()) != GLEW_OK)
		Log << glewGetErrorString(err) << std::endl;

	Log << "[Display System]Init window" << std::endl;

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2; // Optional

	window = new sf::Window(sf::VideoMode(width, height), "OpenGL", sf::Style::Close, settings);
	//window2 = new sf::Window(sf::VideoMode(400, 400), "OpenGL 2", sf::Style::Close, settings);
	//window = windowt;

	Log << "[Display System]Test 2" << std::endl;
	if ((err = glewInit()) != GLEW_OK)
		Log << glewGetErrorString(err) << std::endl;

	Log << "[Display System]opengl test" << std::endl;
	fprintf(stdout, "[Display System]Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	if (GLEW_VERSION_1_1){
		Log << "[Display System]Yay! OpenGL 1.1 is supported!" << std::endl;
	}
	if (GLEW_VERSION_1_2){
		Log << "[Display System]Yay! OpenGL 1.2 is supported!" << std::endl;
	}
	if (GLEW_VERSION_3_0){
		Log << "[Display System]Yay! OpenGL 3.0 is supported!" << std::endl;
	}

	//glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glOrtho(-(width / 2.0), (width / 2.0), -(height / 2.0), (height / 2.0), -1.0, 1.0);

	//opengl 

	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat fovY = 60;
	GLfloat aspect = 100;
	GLfloat zNear = 0;
	GLfloat zFar = 2;
	fH = tan(fovY / 360 * pi) * zNear;
	fW = fH * aspect;
	gluPerspective(45.0f, (GLfloat)640 / (GLfloat)480, 0.1f, 10.0f);
	glMatrixMode(GL_MODELVIEW);

	// triangle init
	*/
	Vec3f Vertices[3];
	Vertices[0] = Vec3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vec3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vec3f(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	/*
	*/
}

void SystemDisplay::Update(){


	Log << "[Display System] entityCount:" << *entityCount << std::endl;


	window->setActive();

	Log << "[Display System] update" << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
	
	window->display();
}

bool SystemDisplay::pollEvent(sf::Event& sfEvent){
	return window->pollEvent(sfEvent);
}



