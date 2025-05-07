#pragma once

#include "GameObject.h"
#include <memory>

class Input
{
public:
	unsigned int currentKey;

	Input();
	~Input();
	static void CheckForInput(std::shared_ptr<GameObject> io_Object);
};

