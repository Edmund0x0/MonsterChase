#ifndef POINT2D_H
#define POINT2D_H

#include <assert.h>

class Point2D
{

private:
	int _x = 0;
	int _y = 0;

public:
	
	// Constructors
	Point2D();
	Point2D(int i_x, int i_y);
	~Point2D();

	bool operator==(const Point2D &rhs) const;
	bool operator!=(const Point2D &rhs) const;
	Point2D operator+(Point2D &rhs);
	Point2D operator-(Point2D &rhs);
	Point2D operator*(const int &rhs);
	Point2D operator/(const int &rhs);
	friend Point2D operator*(const int &i_lhs, const Point2D &i_rhs);
	Point2D operator-();
	Point2D operator+=(const Point2D &rhs);
	Point2D operator-=(const Point2D &rhs);
	Point2D operator*=(const int &rhs);
	Point2D operator/=(const int &rhs);

	// Getters
	int x() const { return _x; }
	int y() const { return _y; }

	// Setters
	void x(int i_x) { _x = i_x; }
	void y(int i_y) { _y = i_y; }

	// The location and Movement options should be connected here in the
	// Point2D class, and Monster and Player should be able to use the same
	// class.

};

#endif // POINT2D_H