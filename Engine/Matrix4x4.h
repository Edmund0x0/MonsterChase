#pragma once
#include "Vector4.h"

class Matrix4x4
{
public:
	float m[4][4];

	// Constructors
	Matrix4x4();
	Matrix4x4(float diagonal);

	// Destructor
	~Matrix4x4();

	// Copy Constructor
	Matrix4x4(const Matrix4x4& other);

	// Assignment operator
	Matrix4x4& operator=(const Matrix4x4& other);

	// Multiplication by scalar
	Matrix4x4 operator*(float scalar) const;

	// Matrix Addition
	Matrix4x4 operator+(const Matrix4x4& other) const;

	// Matrix Subtraction
	Matrix4x4 operator-(const Matrix4x4& other) const;

	// Matrix Multiplication
	Matrix4x4 operator*(const Matrix4x4& other) const;

	// Transpose The Matrix
	Matrix4x4 Transpose() const;

	// Invert the matrix
	Matrix4x4 Inverse() const;

	// Calculate the determinant of the matrix
	float Determinant() const;

	// Get the submatrix obtained by removing row i and col j
	Matrix4x4 SubMatrix(int i, int j) const;

	// Create Translation Matrix
	static Matrix4x4 Translation(float x, float y, float z);

	// Create rotation matrix
	static Matrix4x4 Rotation(float angle, const Vector4& axis);

	// Create scale matrix
	static Matrix4x4 Scale(float x, float y, float z);

};

