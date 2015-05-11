#include <SFML/Window.hpp>
#include <iostream>
#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <glm/glm.hpp>

sf::Window *window;
//sf::Window *window2;

void gameLoop();

int main(int, const char**)
{
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
		std::cout<<"Yay! OpenGL 1.1 is supported!" <<std::endl;
	}
	if (GLEW_VERSION_1_2){
		std::cout<<"Yay! OpenGL 1.2 is supported!" <<std::endl;
	}
	if (GLEW_VERSION_3_0){
		std::cout<<"Yay! OpenGL 3.0 is supported!" <<std::endl;
	}
	
	gameLoop();
    std::cout << "End" << std::endl;
    return 0;
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
				std::cout << "plane key pressed" << windowEvent.key.code << std::endl;
				/*if (windowEvent.key.code == ){

				}*/
				break;
			default:
				break;
			} 
		}
	}
}
/*
#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

using namespace std;

int main(int argc, char* argv[]) {
*/
  /* Code adapted from the SFML 2 "Window" example */
/*
  cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

  sf::Window App(sf::VideoMode(800, 600), "myproject");

  while (App.isOpen()) {
    sf::Event Event;
    while (App.pollEvent(Event)) {
      if (Event.type == sf::Event::Closed)
    App.close();
    }
    App.display();
  }
}

*/