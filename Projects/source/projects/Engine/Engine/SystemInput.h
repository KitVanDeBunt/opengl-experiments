#ifndef SYSTEM_Input_H
#define SYSTEM_Input_H

#include "SystemBase.h"

class SystemInput: public SystemBase
{
public:
	SystemInput();
	~SystemInput();

	virtual void Update()override;
	virtual void Init()override;
};
#endif