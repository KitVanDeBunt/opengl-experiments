#include <iostream>
#include <stdio.h>

//#include "Engine.h"
#include "Entity.h"
#include "ComponentBase.h"
//#include "SystemBase.h"

using namespace std;

Entity::Entity()
{
	components = NULL;
}


Entity::~Entity()
{
}

void Entity::AddComponent(ComponentBase *newComponent)
{
	cout << components << endl;
	if (components == NULL){
		cout << "[Entity] First component added" << endl;
		components = new ComponentBase*[1];
		components[0] = newComponent;
		componentCount = 1;
	}
	else
	{
		cout << "[Entity] Add component" << endl;
		ComponentBase **temp = components;
		components = new ComponentBase*[componentCount + 1];
		for (int i = 0; i<componentCount; ++i){
			components[i] = temp[i];
		}
		components[componentCount] = newComponent;
		componentCount++;

		//delete temp data
		for (int i = 0; i<componentCount - 1; ++i){
			//delete temp[i];
		}
		//delete temp
		delete temp;
	}

	cout << "[Entity] new component name:" << endl;
	cout << "[Entity] component count:" << componentCount << endl;
}
