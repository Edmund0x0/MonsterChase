#pragma once

#include <windows.h>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include "AABB.h"
#include "Vector2.h"

#include "GLib.h"

class GameObject
{
public:

	bool playerOne = false;
	bool playerTwo = false;
	bool ball = false;
	bool upperWall = false;
	bool bottomWall = false;
	float height = 0;
	float width = 0;

	Vector2 normalDeezNuts;

	GLib::Sprite* pGoodGuy;
	const char* spriteFile;

	bool once = false;

	float m_ZRot;
	Vector2 m_Position;
	std::unique_ptr<AABB> m_AABB;


	float positionX = 0;
	float positionY = 0;

	unsigned int KeyPress;
	bool moveHor = false;
	bool moveVer = false;

	Vector2 velocity;
	double velocityX = 0.0;
	double velocityY = 0.0;
	double force = 0.0;
	double drag;
	double mass = 0.0;
	double accel;
};

