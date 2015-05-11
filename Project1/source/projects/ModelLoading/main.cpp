
#include <SFML/Window.hpp>
#include <iostream>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>

#include "vector2D.h"
#include "game.h"

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

void mainLoop();
void init();

void loop();
void initGame();

int main(int, const char**)
{
	init();
	initGame();
	mainLoop();
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

	window = new sf::Window(sf::VideoMode(400, 400), "ModelLoading", sf::Style::Close, settings);
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

	//
	glewExperimental = GL_TRUE;
	// >>>>>>>>>>>GLenum err = glewInit();
	glewInit();
	std::cout << err << std::endl;
	if (GLEW_OK != err)
	{
		// Problem: glewInit failed, something is seriously wrong. 
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	if (GLEW_VERSION_1_3){
		printf("Yay! OpenGL 1.3 is supported!\n");
	}
}

void mainLoop(){
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
		window->setActive();
		loop();

		window->display();

	}
}

void close(){

}