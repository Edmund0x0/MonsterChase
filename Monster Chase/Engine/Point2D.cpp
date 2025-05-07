#include "Point2D.h"
#include <assert.h>

Point2D::Point2D(int i_x, int i_y)
{
    _x = i_x;
    _y = i_y;

}

Point2D::Point2D()
{

}

Point2D::~Point2D()
{

}

// Equality
bool Point2D::operator==(const Point2D &rhs) const
{
	if (this->x() == rhs.x() && this->y() == rhs.y())
	{
		return true;
	}

	return false;
}

// Inequality
bool Point2D::operator!=(const Point2D &rhs) const
{
	if (this->x() != rhs.x() || this->y() != rhs.y())
	{
		return true;
	}

	return false;
}

// Adding Point2D classes together
Point2D Point2D::operator+(Point2D& rhs)
{
	return Point2D(this->x() + rhs.x(), this->y() + rhs.y());
}

// Subtracting Point2D classes together
Point2D Point2D::operator-(Point2D& rhs)
{
	return Point2D(this->x() - rhs.x(), this->y() - rhs.y());
}

// Multiplication Point2D class against int last
Point2D Point2D::operator*(const int& rhs)
{
	return Point2D(this->x() * rhs, this->y() * rhs);
}

// Division Point2D class against int
Point2D Point2D::operator/(const int& rhs)
{
	return Point2D(this->x() / rhs, this->y() / rhs);
}

// Multiplication Point2D class against int first
Point2D operator*(const int& i_lhs, const Point2D& i_rhs)
{
	return Point2D(i_lhs * i_rhs.x(), i_lhs * i_rhs.y());
}

// Negate
Point2D Point2D::operator-()
{
	return Point2D(-(this->x()), -(this->y()));
}

// Point2D += Point2D
Point2D Point2D::operator+=(const Point2D& rhs)
{
	_x += rhs.x();
	_y += rhs.y();
	return *this;
}

// Point2D -= Point2D
Point2D Point2D::operator-=(const Point2D& rhs)
{
	_x -= rhs.x();
	_y -= rhs.y();
	return *this;
}

// Point2D *= Point2D
Point2D Point2D::operator*=(const int& rhs)
{
	_x *= rhs;
	_y *= rhs;
	return *this;
}

// Point2D /= Point2D
Point2D Point2D::operator/=(const int& rhs)
{
	_x /= rhs;
	_y /= rhs;
	return *this;
}

