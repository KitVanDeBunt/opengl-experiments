#ifndef UTILS_ENGINE_TIME_H
#define UTILS_ENGINE_TIME_H

#include "SFML\System\Clock.hpp"

namespace KECS{
	class EngineTime
	{
		friend class Engine;
	public:
		static float getDeltaTime();
	private:
		static void CalculateDeltaTime();
		static float deltaTime_;
		static sf::Clock clock;
	};
}
#endif