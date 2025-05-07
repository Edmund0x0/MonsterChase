#pragma once
class Vector3
{
public:
	// default constructor - good for calling new Vector3[];
	// Since we're made up of POD types, which have no default constructor this does nothing.
	// But we need it. If no constructors exist the compiler will generate one for us. One that
	// takes no parameters and just call the default constructors for it's member variables.
	// Since we're going to define a constructor we also need to define a default constructor
	// so things like Vector3 myVectorArray[] work.
	Vector3();	// we define the body here. this is the same as making it an inline.

	// standard constructor
	inline Vector3(float i_x, float i_y, float i_z);

	// assignment operator
	inline Vector3& operator=(const Vector3& i_rhs);

	// element accessors
	// - get individual element
	inline float x(void) const;
	inline float y(void) const;
	inline float z(void) const;

	// - set individual element
	inline void x(float i_x);
	inline void y(float i_y);
	inline void z(float i_z);

	Vector3& operator+=(const Vector3& i_rhs);
	Vector3& operator-=(const Vector3& i_rhs);

	Vector3& operator*=(float i_val);
	Vector3& operator/=(float i_val);

	// negate
	Vector3 operator-(void);

	void Normalize();
	Vector3 Normalized() const;

	float Length() const;
	float LengthSq() const;

	// - ( 0.0f, 0.0f, 0.0f )
	static const Vector3 Zero;
private:
	float					m_x, m_y, m_z;

};

inline Vector3 operator+(const Vector3& i_lhs, const Vector3& i_rhs);
inline Vector3 operator-(const Vector3& i_lhs, const Vector3& i_rhs);

inline Vector3 operator*(const Vector3& i_lhs, float i_rhs);
inline Vector3 operator/(const Vector3& i_lhs, float i_rhs);

inline bool operator==(const Vector3& i_lhs, const Vector3& i_rhs);
inline bool operator!=(const Vector3& i_lhs, const Vector3& i_rhs);

inline float dot(const Vector3& i_lhs, const Vector3& i_rhs);
