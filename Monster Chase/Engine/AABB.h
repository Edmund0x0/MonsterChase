#pragma once
#include "Vector2.h"
#include <memory>
#include <algorithm>

class AABB
{
public:
	//Constructor
	AABB(const Vector2& _center, const Vector2& _extents);

	// methods
	bool IsColliding(const AABB& other, const Vector2& velocity, float& outTime, float& _dt, Vector2& obj1Pos, Vector2& obj2Pos) const;

	Vector2 center;
	Vector2 extents;

	float collisionTime;

	AABB(const AABB& other) = default;
	AABB& operator=(const AABB& other) = default;
};

