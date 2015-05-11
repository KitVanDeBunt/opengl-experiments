/*

Copyright 2010 Etay Meiri

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MATH_3D_H
#define	MATH_3D_H

struct Vector3f
{
	float x;
	float y;
	float z;

	Vector3f()
	{
	}

	Vector3f(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};

#endif	/* MATH_3D_H */


#include <SFML/Window.hpp>
#include <iostream>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>

sf::Window *window;
//sf::Window *window2;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const GLdouble pi = 3.1415926535897932384626433832795;
GLdouble fW, fH;


static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f,
	1.0f, -1.0f,
	-1.0f, 1.0f,
	1.0f, 1.0f
};

GLuint vertexbuffer;
GLuint elementbuffer;

glm::vec3 position;
glm::vec3 rotation;

void gameLoop();
void init();
void draw();

int main(int, const char**)
{
	init();
	gameLoop();
    std::cout << "End" << std::endl;
    return 0;
}

void init(){
	GLenum      err;

	std::cout << "Start" << std::endl;
	std::cout << "Test 1" << std::endl;
	if ((err = glewInit()) != GLEW_OK)
		std::cout << glewGetErrorString(err) << std::endl;

	std::cout << "Init window" << std::endl;

	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2; // Optional

	window = new sf::Window(sf::VideoMode(400, 400), "OpenGL", sf::Style::Close, settings);
	//window2 = new sf::Window(sf::VideoMode(400, 400), "OpenGL 2", sf::Style::Close, settings);
	//window = windowt;

	std::cout << "Test 2" << std::endl;
	if ((err = glewInit()) != GLEW_OK)
		std::cout << glewGetErrorString(err) << std::endl;

	std::cout << "opengl test" << std::endl;
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	if (GLEW_VERSION_1_1){
		std::cout << "Yay! OpenGL 1.1 is supported!" << std::endl;
	}
	if (GLEW_VERSION_1_2){
		std::cout << "Yay! OpenGL 1.2 is supported!" << std::endl;
	}
	if (GLEW_VERSION_3_0){
		std::cout << "Yay! OpenGL 3.0 is supported!" << std::endl;
	}

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
	*/

	//buffers
	/*
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	*/
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

void gameLoop(){
	sf::sleep(sf::seconds(0.1f));
	bool running = true;
	while (running)
	{
		sf::Event windowEvent;
		while (window->pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::EventType::Closed:
				
				break;
			case sf::Event::EventType::KeyPressed:
				std::cout << "key pressed" << windowEvent.key.code << std::endl;
				/*if (windowEvent.key.code == ){

				}*/
				break;
			default:
				break;
			} 
		}
		
		draw();
		//window->

	}
}

void draw(){
	window->setActive();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*
	glEnable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// positiond light
	GLfloat lightZero[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat lightColor0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightPos0[] = { 0.0f, 3.0f, -5.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightZero);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	*/

	//glPushMatrix();
	//r += 0.2f;

	//glTranslatef(x, y, z);
	//glRotatef(r, 0, 1, 0);
	//glScalef(0.4f, 0.4f, 0.4f);

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

	// Draw the triangle !
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices); // Starting from vertex 0; 3 vertices total -> 1 triangle
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexbuffer); // Starting from vertex 0; 3 vertices total -> 1 triangle
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glDrawElements(
		GL_TRIANGLES,  // mode 
		// 6,                  // count 
		1, //count
		GL_UNSIGNED_SHORT,  // type 
		(void*)0            // element array buffer offset 
		);
		*/
	glDisableVertexAttribArray(0);
	//glPopMatrix();

	window->display();
}