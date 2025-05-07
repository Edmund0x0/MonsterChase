#include "Vector2.h"
#include <cmath>

// Default constructor
Vector2::Vector2() : m_x(0.0f), m_y(0.0f) {}

// Constructor with x and y values
Vector2::Vector2(float i_x, float i_y) : m_x(i_x), m_y(i_y) {}

// Copy constructor
Vector2::Vector2(const Vector2& other) : m_x(other.m_x), m_y(other.m_y) {}

// Assignment operator
Vector2& Vector2::operator=(const Vector2& other)
{
	if (this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}
	return *this;
}

// Element accessors
float Vector2::x() const { return m_x; }
float Vector2::y() const { return m_y; }

// Set individual elements
void Vector2::x(float i_x) { m_x = i_x; }
void Vector2::y(float i_y) { m_y = i_y; }

// compound assignment operators
Vector2& Vector2::operator+=(const Vector2& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    m_x *= scalar;
    m_y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    if (scalar != 0.0f) {
        m_x /= scalar;
        m_y /= scalar;
    }
    return *this;
}

Vector2& Vector2::operator+=(float scalar)
{
    m_x += scalar;
    m_y += scalar;
    return *this;
}

// Unary operators
Vector2 Vector2::operator-() const {
    return Vector2(-m_x, -m_y);
}

// Vector operations
void Vector2::Normalize() {
    float length = Length();
    if (length != 0.0f) {
        m_x /= length;
        m_y /= length;
    }
}

Vector2 Vector2::Normalized() const {
    Vector2 normalizedVec(*this);
    normalizedVec.Normalize();
    return normalizedVec;
}

float Vector2::Length() const {
    return sqrt(m_x * m_x + m_y * m_y);
}

float Vector2::LengthSq() const {
    return m_x * m_x + m_y * m_y;
}

// Implementation of the Dot product method
float Vector2::Dot(const Vector2& other) const
{
    return m_x * other.m_x + m_y * other.m_y;
}

// Constants
const Vector2 Vector2::Zero(0.0f, 0.0f);

// Binary operators
Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
    return Vector2(lhs.x() + rhs.x(), lhs.y() + rhs.y());
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
    return Vector2(lhs.x() - rhs.x(), lhs.y() - rhs.y());
}

Vector2 operator*(const Vector2& vec, float scalar) {
    return Vector2(vec.x() * scalar, vec.y() * scalar);
}

Vector2 operator*(float scalar, const Vector2& vec) {
    return vec * scalar;
}

Vector2 operator/(const Vector2& vec, float scalar) {
    if (scalar != 0.0f) {
        return Vector2(vec.x() / scalar, vec.y() / scalar);
    }
    return vec;
}

Vector2 operator*(const Vector2& lhs, const Vector2& rhs) {
    return { lhs.x() * rhs.x(), lhs.y() * rhs.y()};
}

// Comparison operators
bool operator==(const Vector2& lhs, const Vector2& rhs) {
    return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}

bool operator!=(const Vector2& lhs, const Vector2& rhs) {
    return !(lhs == rhs);
}

// Dot product
float dot(const Vector2& lhs, const Vector2& rhs) {
    return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}