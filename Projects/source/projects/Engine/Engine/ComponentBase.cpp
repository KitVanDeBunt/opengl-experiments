#include <iostream>

#include "KECS.h"
namespace KECS{
	ComponentBase::ComponentBase(std::string id){
		setComponentID(id);
	}

	ComponentBase::~ComponentBase(){
		//_parentEntity = NULL;
	}

	void ComponentBase::AddToParent(Entity *parentEntity){
		_parentEntity = parentEntity;
	}

	void ComponentBase::Init(){

	}

	void ComponentBase::Update(){

	}
}
