#ifndef Component_Player_H
#define Component_Player_H

#include <iostream>

#include "Engine/ComponentBase.h"

using namespace KECS;
static const std::string ID_COMPONENT_PLAYER = "component_player";

class ComponentPlayer :
	public ComponentBase
{
public:
	ComponentPlayer();
	~ComponentPlayer();
	void SetInput(float up, float down, float left, float right){
		if (!(up == 0 && down == 0 && left == 0 && right == 0)){
			_up = up;
			_down = down;
			_left = left;
			_right = right;
		}
		_mup = up;
		_mdown = down;
		_mleft = left;
		_mright = right;
	};
private:
	virtual void Update();
	virtual void Init();

	// movement speed
	float speed = 200;

	// rotation
	float _up = 0;
	float _down = 0;
	float _left = 0;
	float _right = 0;

	// movement
	float _mup = 0;
	float _mdown = 0;
	float _mleft = 0;
	float _mright = 0;
};

#endif
