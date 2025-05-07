#include "CollisionResponse.h"

void CollisionResponse::AdvanceObjects(GameObject& obj1, GameObject& obj2, float collisionTime)
{
	obj1.positionX += obj1.velocityX * collisionTime;
	obj1.positionY += obj1.velocityY * collisionTime;

	obj2.positionX += obj2.velocityX * collisionTime;
	obj2.positionY += obj2.velocityY * collisionTime;
}

void CollisionResponse::ResolveCollision(GameObject& obj1, GameObject& obj2)
{

	Vector2 reflect = obj1.velocity - 2 * dot(obj1.velocity, obj2.normalDeezNuts) * obj2.normalDeezNuts;


	if (obj1.ball)
	{
		obj1.velocityX = reflect.x();
		obj1.velocityY = reflect.y();
		obj1.positionX += reflect.x() / 3;
		obj1.positionY += reflect.y() / 3;
		obj1.velocityX *= 1.06;
		obj1.velocityY *= 1.06;


	}
	if (obj2.upperWall && obj1.playerOne || obj2.upperWall && obj1.playerTwo)
	{
		// Set velocities to zero to stop the objects
		obj1.velocityX = reflect.x();
		obj1.velocityY = reflect.y();
		obj1.positionX += reflect.x() / 3;
		obj1.positionY += reflect.y() / 3;
	}
	if (obj2.bottomWall && obj1.playerOne || obj2.bottomWall && obj1.playerTwo)
	{
		// Set velocities to zero to stop the objects
		obj1.velocityX = reflect.x();
		obj1.velocityY = reflect.y();
		obj1.positionX += reflect.x() / 3;
		obj1.positionY += reflect.y() / 3;
	}
	
}