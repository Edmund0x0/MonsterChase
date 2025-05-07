#include "AABB.h"
#include <cmath>

// Constructor
AABB::AABB(const Vector2& _center, const Vector2& _extents)
	: center(_center), extents(_extents) {}

// Method to check collision between two moving AABBs in 2D space using Swept Separating Axis Check
bool AABB::IsColliding(const AABB& other, const Vector2& velocity, float& outTime, float& _dt, Vector2& obj1Pos, Vector2& obj2Pos) const
{

    // Calculate the relative velocity between two AABBs
    Vector2 relativeVelocity = velocity;

    // Compute the projection of each AABB onto each axis
    Vector2 axis;
    float tEnter = 0.0f, tExit = _dt;

    // Calculate the time intervals along each axis
    for (int i = 0; i < 2; ++i)
    {
        // Project AABBs onto each axis
        axis = Vector2((i == 0) ? 1.0f : 0.0f, (i == 1) ? 1.0f : 0.0f); // x-axis or y-axis

        float Bextents = extents.Dot(axis) + other.extents.Dot(axis);
        float Bleft = (center + obj1Pos).Dot(axis) - Bextents;
        float Bright = (center + obj1Pos).Dot(axis) + Bextents;
        float dClose = Bleft - (other.center + obj2Pos).Dot(axis);
        float dOpen = Bright - (other.center + obj2Pos).Dot(axis);
        float tClose = 0;
        float tOpen = 0;

        if (relativeVelocity.Dot(axis) == 0.0f)
        {
            // Objects are not moving along this axis, check for overlap
            if (fabs((center + obj1Pos).Dot(axis) - (other.center + obj2Pos).Dot(axis)) > Bextents)
            {
                // No overlap between AABBs along this axis, return false
                return false;
            }
            // Objects are either overlapping or not moving along this axis, continue to the next axis
            // Calculate tClose and tOpen based on relative velocity
            tClose = 0;
            tOpen = _dt;
        }

        else
        {
            // Calculate tClose and tOpen based on relative velocity
            tClose = dClose / relativeVelocity.Dot(axis);
            tOpen = dOpen / relativeVelocity.Dot(axis);
        }
        

        // Swap tClose and tOpen if necessary
        if (tClose > tOpen)
        {
            std::swap(tClose, tOpen);
        }
            

        // Update the time of entry and exit along the axis
        tEnter = std::max(tClose, tEnter);
        tExit = std::min(tOpen, tExit);

        // If there is no overlap between the intervals, no collision
        if (tEnter > tExit)
        {
            return false;
        }
    }

    outTime = tEnter;
    return true;
}