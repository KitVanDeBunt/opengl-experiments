#ifndef SYSTEM_DISPLAY_H
#define SYSTEM_DISPLAY_H

#include <SFML\Window.hpp>
#include "SFML\System.hpp"
#include <SFML\OpenGL.hpp>

#include "SystemBase.h"
#include "ComponentSprite.h"
#include "ComponentTransform.h"

namespace KECS{

	class SystemDisplay : public SystemBase
	{
	public:
		SystemDisplay(GLdouble width, GLdouble height, sf::String newWindowTitle);
		~SystemDisplay();

		virtual void Update()override;
		virtual void Init()override;

		bool pollEvent(sf::Event&);

	private:
		void DrawSprite(ComponentSprite*, ComponentTransform*);
		void UpdateSpriteList();

		sf::Window *window;

		sf::String windowTitle;

		GLuint vertexbuffer;
		GLdouble width, height;

		GLdouble fW, fH;

		//loop variables
		//ComponentBase *sprite;
		//ComponentBase *transform;

		ComponentSprite **sprites;
		ComponentTransform **transforms;
		//Entity **entitysTemp;
	};
}
#endif

