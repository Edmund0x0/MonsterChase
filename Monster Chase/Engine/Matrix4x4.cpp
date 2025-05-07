#include "Matrix4x4.h"
#include <cmath>

// Constructor
Matrix4x4::Matrix4x4()
{
	// Initialize the matrix as an identity matrix
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

Matrix4x4::~Matrix4x4()
{

}

// Constructor with diagonal value
Matrix4x4::Matrix4x4(float diagonal)
{
	// Initalize the matrix with the given diagonal value
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = (i == j) ? diagonal : 0.0f;
		}
	}
}

// Copy Constructor
Matrix4x4::Matrix4x4(const Matrix4x4& other)
{
	// Copy the elements from the other matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; ++j)
		{
			m[i][j] = other.m[i][j];
		}
	}
}

// Assingment operator
Matrix4x4& Matrix4x4::operator=(const Matrix4x4& other)
{
	// Check for self-assignment
	if (this != &other)
	{
		// copy the elements from the other matrix
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				m[i][j] = other.m[i][j];
			}
		}
	}
	return *this;
}

// Multiplication by scalar
Matrix4x4 Matrix4x4::operator*(float scalar) const
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = m[i][j] * scalar;
		}
	}
	return result;
}

// Matrix addition
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& other) const
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = m[i][j] + other.m[i][j];
		}
	}
	return result;
}

// Matrix subtraction
Matrix4x4 Matrix4x4::operator-(const Matrix4x4& other) const
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = m[i][j] - other.m[i][j];
		}
	}
	return result;
}

// Matrix Multiplication
Matrix4x4 Matrix4x4::operator*(const Matrix4x4& other) const
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = 0.0f;
			for (int k = 0; k < 4; ++k)
			{
				result.m[i][j] += m[i][k] * other.m[k][j];
			}
		}
	}
	return result;
}

// Transpose the matrix
Matrix4x4 Matrix4x4::Transpose() const
{
	Matrix4x4 result;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result.m[i][j] = m[j][i];
		}
	}
	return result;
}

// Calculate the determinant of the matrix
float Matrix4x4::Determinant() const
{
	float det = 0.0f;
	// Calculate the determinant using the cofactor expansion along the first row
	for (int i = 0; i < 4; ++i)
	{
		det += m[0][i] * ((i % 2 == 0) ? 1.0f : -1.0f) * SubMatrix(0, i).Determinant();
	}
	return det;
}

// Get the submatrix obtained by removing row i and col j
Matrix4x4 Matrix4x4::SubMatrix(int i, int j) const
{
	Matrix4x4 sub;
	int row = 0, col = 0;
	for (int r = 0; r < 4; ++r)
	{
		if (r == i) continue; // skip row i
		for (int c = 0; c < 4; ++c)
		{
			if (c == j) continue; // skip col j
			sub.m[row][col] = m[r][c];
			++col;
		}
		++row;
		col = 0;
	}
	return sub;
}

Matrix4x4 Matrix4x4::Inverse() const
{
	Matrix4x4 result;

	// Calculate the determinant
	float det = Determinant();
	if (det == 0.0f)
	{
		// Matrix is not invertible
		return result;
	}

	// Adjugate Matrix
	Matrix4x4 adjugate;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// Calculate the cofactor
			float cofactor = ((i + j) % 2 == 0 ? 1.0f : -1.0f) * SubMatrix(i, j).Determinant();
			adjugate.m[j][i] = cofactor;
		}
	}

	// Calculate the inverse as adjugate / determinant
	result = adjugate * (1.0f / det);

	return result;
}

Matrix4x4 Matrix4x4::Rotation(float angle, const Vector4& axis) {
	Matrix4x4 result;
	// Convert the angle to radians
	float radians = angle * (3.14159265358979323846f / 180.0f);
	float c = cos(radians);
	float s = sin(radians);
	float t = 1.0f - c;
	float x = axis.x();
	float y = axis.y();
	float z = axis.z();

	// First row
	result.m[0][0] = t * x * x + c;
	result.m[0][1] = t * x * y - s * z;
	result.m[0][2] = t * x * z + s * y;
	result.m[0][3] = 0.0f;

	// Second row
	result.m[1][0] = t * x * y + s * z;
	result.m[1][1] = t * y * y + c;
	result.m[1][2] = t * y * z - s * x;
	result.m[1][3] = 0.0f;

	// Third row
	result.m[2][0] = t * x * z - s * y;
	result.m[2][1] = t * y * z + s * x;
	result.m[2][2] = t * z * z + c;
	result.m[2][3] = 0.0f;

	// Fourth row
	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

// Create Translation Matrix
Matrix4x4 Matrix4x4::Translation(float x, float y, float z)
{
	Matrix4x4 result;
	result.m[0][3] = x;
	result.m[1][3] = y;
	result.m[2][3] = z;
	return result;
}

// Create scale Matrix
Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
{
	Matrix4x4 result;
	result.m[0][0] = x;
	result.m[1][1] = y;
	result.m[2][2] = z;
	return result;
}