#include "../KECS.h"

namespace KECS{
	class EngineTime;

	float EngineTime::deltaTime_;
	sf::Clock EngineTime::clock;

	float EngineTime::getDeltaTime(){
		return ((float)deltaTime_ / 1000000.0f);
	}

	void EngineTime::CalculateDeltaTime(){
		EngineTime::deltaTime_ = EngineTime::clock.getElapsedTime().asMicroseconds();
		clock.restart();
	}
}