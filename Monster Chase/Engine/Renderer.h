#pragma once

#include "GameObject.h"
#include "GLib.h"
#include <Windows.h>
#include <memory>
#include <vector>

#include <DirectXColors.h>

#if defined _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // _DEBUG

class Renderer
{
public:
	Renderer();
	~Renderer();

	static void Run(std::vector<std::shared_ptr<GameObject>> io_Objects);
	static void renderSprite(GLib::Sprite* spr, float _x, float _y);
	static void releaseSprite(GLib::Sprite* spr);
};