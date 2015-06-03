#include <iostream>
#include <stdio.h>

#include "KECS.h"

using namespace std;

namespace KECS{

	Entity::Entity(){
		components = NULL;
	}

	Entity::~Entity(){
	}

	void Entity::AddComponent(ComponentBase *newComponent){
		newComponent->AddToParent(this);
		//cout << "[Entity] components: " << components << endl;
		if (components == NULL){
			// cout << "[Entity] First component added" << endl;
			components = new ComponentBase*[1];
			components[0] = newComponent;
			componentCount = 1;
		}else{
			// cout << "[Entity] Add component" << endl;
			ComponentBase **temp = components;
			components = new ComponentBase*[componentCount + 1];
			for (int i = 0; i < componentCount; ++i){
				components[i] = temp[i];
			}
			components[componentCount] = newComponent;
			componentCount++;

			// delete temp
			delete temp;
		}
		newComponent->Init();
		// cout << "[Entity] component count:" << componentCount << endl;
	}

	ComponentBase* Entity::GetComponent(std::string classID){
		if (components != NULL){
			for (i = 0; i < componentCount; ++i){
				if (components[i]->getComponentID() == classID){
					return components[i];
				}
			}
		}
		return NULL;
	}

	void Entity::Update(){
		for (int i = 0; i < componentCount; ++i){
			components[i]->Update();
		}
	}
}