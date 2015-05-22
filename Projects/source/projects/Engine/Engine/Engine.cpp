#include <iostream>
#include <stdio.h>

#include "KECS.h"
#include "Utils\EngineTime.h"

using namespace std;

namespace KECS{
	Engine::Engine()
	{
		cout << "\n [Engine]: constructed" << endl;
		cout << "     _____                                                            " << endl;
		cout << "  __| __  |__       ______  ____   _  ______  ____  ____   _  ______  " << endl;
		cout << " |  |/ /     | ___ |   ___||    \\ | ||   ___||    ||    \\ | ||   ___| " << endl;
		cout << " |     \\     ||___||   ___||     \\| ||   |  ||    ||     \\| ||   ___| " << endl;
		cout << " |__|\\__\\  __|     |______||__/\\____||______||____||__/\\____||______| " << endl;
		cout << "    |_____|                                                           " << endl;

		systems = NULL;
		entitys = NULL;
	}


	Engine::~Engine()
	{
		cout << " [Engine]: destructed" << endl;
	}

	void Engine::AddSystem(SystemBase *newSystem)
	{
		cout << systems << endl;
		if (systems == NULL){
			cout << "[Engine] First system added" << endl;
			systems = new SystemBase*[1];
			systems[0] = newSystem;
			systemCount = 1;
		}
		else
		{
			cout << "[Engine] Add system" << endl;
			SystemBase **temp = systems;
			systems = new SystemBase*[systemCount + 1];
			for (int i = 0; i < systemCount; ++i){
				systems[i] = temp[i];
			}
			systems[systemCount] = newSystem;
			systemCount++;

			//delete temp data
			for (int i = 0; i < systemCount - 1; ++i){
				//delete temp[i];
			}
			//delete temp
			delete temp;
		}

		newSystem->entitys = &entitys;
		newSystem->entityCount = &entityCount;

		cout << "[Engine] new system name:" << endl;
		cout << "[Engine] system count:" << systemCount << endl;
	}

	void Engine::AddEntity(Entity *newEntity)
	{
		cout << entitys << endl;
		if (entitys == NULL){
			//cout << "[Engine] First entity added" << endl;
			entitys = new Entity*[1];
			entitys[0] = newEntity;
			entityCount = 1;
		}
		else
		{
			//cout << "[Engine] Add entity" << endl;
			Entity **temp = entitys;
			entitys = new Entity*[entityCount + 1];
			for (int i = 0; i < entityCount; ++i){
				entitys[i] = temp[i];
			}
			entitys[entityCount] = newEntity;
			entityCount++;

			//delete temp data
			for (int i = 0; i < entityCount - 1; ++i){
				//delete temp[i];
			}
			//delete temp
			delete temp;
		}

		//cout << "[Engine] new entity name:" << endl;
		//cout << "[Engine] entity count:" << entityCount << endl;
	}

	void Engine::Init()
	{
		cout << "[Engine] start init - system count:" << systemCount << endl;
		for (int i = 0; i < systemCount; ++i){
			cout << "[Engine] init - system n:" << i << endl;
			systems[i]->Init();
		}
	}

	bool Engine::Update()
	{
		EngineTime::CalculateDeltaTime();
		/*
		for (int i = 0; i < entityCount; i++){
		if (entitys != NULL){
		ComponentBase *test = entitys[i]->GetComponent(ID_COMPONENT_SPRITE);
		if (test != NULL){
		std::cout << "[Display System] test test test n" << i << " contains a test component" << std::endl;
		}

		ComponentSprite *sprite = (ComponentSprite*)entitys[i]->GetComponent(ID_COMPONENT_SPRITE);
		if (sprite != NULL){
		std::cout<< "[Display System] entity n" << i << " contains a sprite component" << std::endl;
		}
		ComponentTransform *transform = (ComponentTransform*)entitys[i]->GetComponent(ID_COMPONENT_TRANSFORM);
		if (transform != NULL){
		std::cout << "[Display System] entity n" << i << " contains a transform component" << std::endl;
		}
		}
		else{
		std::cout << "[Display System] entity NULL" << std::endl;
		}
		}
		*/
		//cout << "[Engine] Update - system count:" << systemCount << endl;
		for (int i = 0; i < systemCount; ++i){
			systems[i]->Update();
		}
		for (int i = 0; i < entityCount; ++i){
			entitys[i]->Update();
		}

		return true;
	}
}
	