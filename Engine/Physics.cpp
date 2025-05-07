#include "Physics.h"

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::Run()
{

}

void Physics::ChangePosition(int& positionX, int& positionY, long& time)
{

}

void Physics::Update(std::shared_ptr<GameObject> io_Object, float& i_dt, const std::vector<std::shared_ptr<GameObject>>& objects)
{

	// Check for collisions with other objects
	for (const auto& other : objects)
	{
		if (io_Object != other)
		{
			ResolveCollisions(io_Object, other, i_dt);
		}
	}

	// Update velocity and position based on current acceleration
	UpdateVelocityAndPosition(io_Object, i_dt);

}

void Physics::UpdateVelocityAndPosition(std::shared_ptr<GameObject> io_Object, float& i_dt)
{

	float AccelerationX = (io_Object->moveHor ? io_Object->force / (io_Object->mass * i_dt) : -io_Object->velocityX * 0.5);
	float AccelerationY = (io_Object->moveVer ? io_Object->force / (io_Object->mass * i_dt) : -io_Object->velocityY * 0.5);

	if (io_Object->ball)
	{
		if (io_Object->positionX > 500 || io_Object->positionX < -500)
		{
			io_Object->positionX = 0;
			io_Object->positionY = 0;
			io_Object->velocityX = 50;
			io_Object->velocityY = -50;
		}

		io_Object->positionX += (io_Object->velocityX *  i_dt);
		io_Object->positionY += (io_Object->velocityY * i_dt);
	}
	else
	{
		io_Object->positionX += (io_Object->velocityX += AccelerationX * i_dt / 2.0f) * i_dt;
		io_Object->positionY += (io_Object->velocityY += AccelerationY * i_dt / 2.0f) * i_dt;
	}

	io_Object->velocity = Vector2(io_Object->velocityX, io_Object->velocityY);

	io_Object->m_Position.x(io_Object->positionX);
	io_Object->m_Position.y(io_Object->positionY);

	io_Object->moveHor = false;
	io_Object->moveVer = false;
}

void Physics::ResolveCollisions(std::shared_ptr<GameObject> obj1, std::shared_ptr<GameObject> obj2, float deltaTime)
{
	// Check for collision between obj1 and obj2
	// If collision occurs, resolve it using CollisionResponse class
	if (obj1->m_AABB && obj2->m_AABB)
	{
		float collisionTime = 0.0f;

		Vector2 velocity(obj1->velocityX, obj1->velocityY);
		if (obj1->m_AABB->IsColliding(*(obj2->m_AABB), velocity, collisionTime, deltaTime, obj1->m_Position, obj2->m_Position))
		{
			// Advance objects to collision time
			CollisionResponse::AdvanceObjects(*obj1, *obj2, collisionTime);
			// Resolve collision
			CollisionResponse::ResolveCollision(*obj1, *obj2);
		}
	}
}

void Physics::ChangeForce(double& force, double& mass, double& accel)
{
	force = (mass * accel);
}

void Physics::ChangeVelocity(double& velocity, int& positionX, int& positionY, long& time)
{
	int newPosX = positionX;
	int newPosY = positionY;
	long newTime;
	ChangePosition(newPosX, newPosY, newTime);
	velocity = pow(pow(newPosX - positionX, 2) + pow(newPosY - positionY, 2), 0.5) / (newTime - time);
}

void Physics::ChangeAccel(double& accel, int& positionX, int& positionY, double& velocity, long& time)
{
	double newVel = velocity;
	long newTime;
	ChangeVelocity(newVel, positionX, positionY, newTime);
	accel = ((newVel - velocity) / (newTime - time));
}

void Physics::ChangeDrag(double& drag)
{

}
