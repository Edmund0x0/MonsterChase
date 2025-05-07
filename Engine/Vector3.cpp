#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{

}
// Constructor with x, y, and z components
inline Vector3::Vector3(float i_x, float i_y, float i_z) : m_x(i_x), m_y(i_y), m_z(i_z) {}

// Getters for each element
inline float Vector3::x() const { return m_x; }
inline float Vector3::y() const { return m_y; }
inline float Vector3::z() const { return m_z; }

// Setters for each element
inline void Vector3::x(float i_x) { m_x = i_x; }
inline void Vector3::y(float i_y) { m_y = i_y; }
inline void Vector3::z(float i_z) { m_z = i_z; }

// Assignment operator
inline Vector3& Vector3::operator=(const Vector3& i_rhs) {
	if (this != &i_rhs) {
		m_x = i_rhs.m_x;
		m_y = i_rhs.m_y;
		m_z = i_rhs.m_z;
	}
	return *this;
}

// Vector Addition
Vector3& Vector3::operator+=(const Vector3& i_rhs)
{
	m_x += i_rhs.m_x;
	m_y += i_rhs.m_y;
	m_z += i_rhs.m_z;
	return *this;
}

// Vector Subtraction
Vector3& Vector3::operator-=(const Vector3& i_rhs)
{
	m_x -= i_rhs.m_x;
	m_y -= i_rhs.m_y;
	m_z -= i_rhs.m_z;
	return *this;
}

// Scalar Multi
Vector3& Vector3::operator*=(float i_val)
{
	m_x *= i_val;
	m_y *= i_val;
	m_z *= i_val;
	return *this;
}

// Scalar Div
Vector3& Vector3::operator/=(float i_val)
{
	// aslong as no 0
	if (i_val != 0.0f)
	{
		m_x /= i_val;
		m_y /= i_val;
		m_z /= i_val;
	}
	return *this;
}

// Negation
Vector3 Vector3::operator-()
{
	return Vector3(-m_x, -m_y, -m_z);
}

// Normalize the vec
void Vector3::Normalize()
{
	float length = Length();
	if (length != 0.0f)
	{
		m_x /= length;
		m_y /= length;
		m_x /= length;
	}
}

// return a normalized copy of the vector
Vector3 Vector3::Normalized() const
{
	Vector3 normalizedVec(*this);
	normalizedVec.Normalize();
	return normalizedVec;
}

// Magnitude (length) of the vec
float Vector3::Length() const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

// Square of the magnitude (length) of the vector
float Vector3::LengthSq() const
{
	return m_x * m_x + m_y * m_y + m_z * m_z;
}

// Zero vector constant
const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);

// Vector addition
Vector3 operator+(const Vector3& i_lhs, const Vector3& i_rhs)
{
	return Vector3(i_lhs.x() + i_rhs.x(), i_lhs.y() + i_rhs.y(), i_lhs.z() + i_rhs.z());
}

// Vector subtraction
Vector3 operator-(const Vector3& i_lhs, const Vector3& i_rhs)
{
	return Vector3(i_lhs.x() - i_rhs.x(), i_lhs.y() - i_rhs.y(), i_lhs.z() - i_rhs.z());
}

// Scalar Multi
Vector3 operator*(const Vector3& i_lhs, float i_rhs)
{
	return Vector3(i_lhs.x() * i_rhs, i_lhs.y() * i_rhs, i_lhs.z() * i_rhs);
}

// Scalar Div
Vector3 operator/(const Vector3& i_lhs, float i_rhs)
{
	// Check if i_rhs is not zero to avoid division by zero
	if (i_rhs != 0.0f)
	{
		return Vector3(i_lhs.x() / i_rhs, i_lhs.y() / i_rhs, i_lhs.z() / i_rhs);
	}
	else
	{
		return i_lhs;
	}
}

// Equality comparison
bool operator==(const Vector3& i_lhs, const Vector3& i_rhs)
{
	return i_lhs.x() == i_rhs.x() && i_lhs.y() == i_rhs.y() && i_lhs.z() == i_rhs.z();
}

// Inequality comparison
bool operator!=(const Vector3& i_lhs, const Vector3& i_rhs)
{
	return !(i_lhs == i_rhs);
}

// Dot Product
float dot(const Vector3& i_lhs, const Vector3& i_rhs)
{
	return i_lhs.x() * i_rhs.x() + i_lhs.y() * i_rhs.y() + i_lhs.z() * i_rhs.z();
}
