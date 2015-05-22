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
		SystemDisplay();
		~SystemDisplay();

		virtual void Update()override;
		virtual void Init()override;

		bool pollEvent(sf::Event&);

	private:
		void DrawSprite(ComponentSprite*, ComponentTransform*);

		sf::Window *window;

		const int SCREEN_WIDTH = 1280;
		const int SCREEN_HEIGHT = 720;
		GLdouble fW, fH;

		//loop variables
		ComponentSprite *sprite;
		ComponentTransform *transform;


		Entity **entitysTemp;
	};
}
#endif

