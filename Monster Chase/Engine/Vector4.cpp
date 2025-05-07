#include "Vector4.h"
#include <cmath>

Vector4::Vector4() : m_x(0.0f), m_y(0.0f), m_z(0.0f), m_w(0.0f) {}

// Constructor from Vector3 and w component
inline Vector4::Vector4(const Vector3& i_other, float i_w) : m_x(i_other.x()), m_y(i_other.y()), m_z(i_other.z()), m_w(i_w) {}

// Constructor with x, y, z, and w components
inline Vector4::Vector4(float i_x, float i_y, float i_z, float i_w) : m_x(i_x), m_y(i_y), m_z(i_z), m_w(i_w) {}

// Getters for each element
inline float Vector4::x() const { return m_x; }
inline float Vector4::y() const { return m_y; }
inline float Vector4::z() const { return m_z; }
inline float Vector4::w() const { return m_w; }

// Setters for each element
inline void Vector4::x(float i_x) { m_x = i_x; }
inline void Vector4::y(float i_y) { m_y = i_y; }
inline void Vector4::z(float i_z) { m_z = i_z; }
inline void Vector4::w(float i_w) { m_w = i_w; }

// Assignment operator
inline Vector4& Vector4::operator=(const Vector4& i_rhs) {
	if (this != &i_rhs) {
		m_x = i_rhs.m_x;
		m_y = i_rhs.m_y;
		m_z = i_rhs.m_z;
		m_w = i_rhs.m_w;
	}
	return *this;
}

// Vector addition
inline Vector4 operator+(const Vector4& i_lhs, const Vector4& i_rhs) {
	return Vector4(i_lhs.x() + i_rhs.x(), i_lhs.y() + i_rhs.y(), i_lhs.z() + i_rhs.z(), i_lhs.w() + i_rhs.w());
}

// Vector subtraction
inline Vector4 operator-(const Vector4& i_lhs, const Vector4& i_rhs) {
	return Vector4(i_lhs.x() - i_rhs.x(), i_lhs.y() - i_rhs.y(), i_lhs.z() - i_rhs.z(), i_lhs.w() - i_rhs.w());
}

// Scalar multiplication
inline Vector4 operator*(const Vector4& i_lhs, float i_rhs) {
	return Vector4(i_lhs.x() * i_rhs, i_lhs.y() * i_rhs, i_lhs.z() * i_rhs, i_lhs.w() * i_rhs);
}

// Scalar division
inline Vector4 operator/(const Vector4& i_lhs, float i_rhs) {
	// Check if i_rhs is not zero
	if (i_rhs != 0.0f) {
		return Vector4(i_lhs.x() / i_rhs, i_lhs.y() / i_rhs, i_lhs.z() / i_rhs, i_lhs.w() / i_rhs);
	}
	// Return a zero vector if dividing by zero
	return Vector4::Zero;
}

// Equality comparison
inline bool operator==(const Vector4& i_lhs, const Vector4& i_rhs) {
	return i_lhs.x() == i_rhs.x() && i_lhs.y() == i_rhs.y() && i_lhs.z() == i_rhs.z() && i_lhs.w() == i_rhs.w();
}

// Inequality comparison
inline bool operator!=(const Vector4& i_lhs, const Vector4& i_rhs) {
	return !(i_lhs == i_rhs);
}

// Vector Add
Vector4& Vector4::operator+=(const Vector4& i_rhs)
{
	m_x += i_rhs.m_x;
	m_y += i_rhs.m_y;
	m_z += i_rhs.m_z;
	m_w += i_rhs.m_w;
	return *this;
}

// Vector Sub
Vector4& Vector4::operator-=(const Vector4& i_rhs)
{
	m_x -= i_rhs.m_x;
	m_y -= i_rhs.m_y;
	m_z -= i_rhs.m_z;
	m_w -= i_rhs.m_w;
	return *this;
}

// Scalar mutli
Vector4& Vector4::operator*=(float i_val)
{
	m_x *= i_val;
	m_y *= i_val;
	m_z *= i_val;
	m_w *= i_val;
	return *this;
}

// Scalar Div
Vector4& Vector4::operator/=(float i_val)
{
	// Check if i_val is not zero
	if (i_val != 0.0f)
	{
		m_x /= i_val;
		m_y /= i_val;
		m_z /= i_val;
		m_w /= i_val;
		return *this;
	}

	return *this;
}

// Negation
Vector4 Vector4::operator-()
{
	return Vector4(-m_x, -m_y, -m_z, -m_w);
}

// Dot product
inline float dot(const Vector4& i_lhs, const Vector4& i_rhs) {
	return i_lhs.x() * i_rhs.x() + i_lhs.y() * i_rhs.y() + i_lhs.z() * i_rhs.z() + i_lhs.w() * i_rhs.w();
}

// Normalize the vec
void Vector4::Normalize()
{
	float length = Length();
	if (length != 0.0f)
	{
		m_x /= length;
		m_y /= length;
		m_y /= length;
	}
}

// Normalize the vector
Vector4 Vector4::Normalized() const {
	float length = Length();
	if (length != 0.0f) {
		return *this / length;
	}
	// Return a zero vector if the length is zero
	return Vector4::Zero;
}

// Calculate the length of the vector
float Vector4::Length() const {
	return sqrt(LengthSq());
}

// Calculate the squared length of the vector (faster than Length())
float Vector4::LengthSq() const {
	return dot(*this, *this);
}