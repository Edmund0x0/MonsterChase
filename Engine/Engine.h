#pragma once

#include "Input.h"
#include "Physics.h"
#include "AI.h"
#include "Renderer.h"
#include "GameObject.h"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class Engine
{
public:

	Engine();
	~Engine();
	static void Run(std::vector<std::shared_ptr<GameObject>> io_Objects);
	static bool Initialize();

	static std::shared_ptr<GameObject> CreateActor(const char* i_pScriptFilename);

};
