#pragma once
#include "GameObject.h"
#include "AABB.h"
#include "Vector2.h"
#include <iostream>

class CollisionResponse
{
public:
	// advance the objects to the time of the collision
	static void AdvanceObjects(GameObject& obj1, GameObject& obj2, float collisionTime);

	// resolve the collision
	static void ResolveCollision(GameObject& obj1, GameObject& obj2);

};

