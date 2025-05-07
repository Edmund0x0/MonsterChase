#pragma once
class Vector2
{
public:
	// Default constructor
	Vector2();

	// Constructor with x and y values
	Vector2(float i_x, float i_y);

	// Copy Constructor
	Vector2(const Vector2& other);

	// Assignment operator
	Vector2& operator=(const Vector2& other);

	// Element accessors
	float x() const;
	float y() const;

	// Set individual elements
	void x(float i_x);
	void y(float i_y);

	// Compound assignment operators
	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);
	Vector2& operator+=(float scalar);

	// Unary operators
	Vector2 operator-() const;

	// Vector operations
	void Normalize();
	Vector2 Normalized() const;
	float Length() const;
	float LengthSq() const;

	float Dot(const Vector2& other) const;

	// Constants
	static const Vector2 Zero;

private:
	float m_x, m_y;
};

// Binary operators
Vector2 operator+(const Vector2& lhs, const Vector2& rhs);
Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
Vector2 operator*(const Vector2& vec, float scalar);
Vector2 operator*(float scalar, const Vector2& vec);
Vector2 operator/(const Vector2& vec, float scalar);
Vector2 operator*(const Vector2& lhs, const Vector2& rhs);

// Comparision operators
bool operator==(const Vector2& lhs, const Vector2& rhs);
bool operator!=(const Vector2& lhs, const Vector2& rhs);

// Dot product
float dot(const Vector2& lhs, const Vector2& rhs);

