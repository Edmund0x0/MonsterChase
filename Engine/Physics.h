#pragma once
#include "Timing.h"
#include "GameObject.h"
#include "AABB.h"
#include <memory>
#include <cmath>
#include <vector>
#include "CollisionResponse.h"


class Physics
{
public:
	Physics();
	~Physics();

	static void Run();

	// important
	static void Update(std::shared_ptr<GameObject> io_Object, float& i_dt, const std::vector<std::shared_ptr<GameObject>>& objects);

	void ChangePosition(int& positionX, int& positionY, long& time);
	void ChangeForce(double& force, double& mass, double& accel);
	void ChangeVelocity(double& velocity, int& positionX, int& positionY, long& time);
	void ChangeDrag(double& drag);
	void ChangeAccel(double& accel, int& positionX, int& positionY, double& velocity, long& time);

	// important
	static void UpdateVelocityAndPosition(std::shared_ptr<GameObject> io_Object, float& i_dt);
	static void ResolveCollisions(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2, float deltaTime);
};