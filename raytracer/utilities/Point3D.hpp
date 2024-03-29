#pragma once

/**
   This file declares the class Point3D which represents a 3D point.

   Courtesy Kevin Suffern.
*/

#include "Vector3D.hpp"

class Point3D {
public:
  float x, y, z;  // the co-ordinates.

public:
  // Constructors.
  Point3D();   // set point to (0, 0, 0).
  Point3D(const float c);  // set point to (c, c, c).
  Point3D(const float x, const float y, const float z);	// set point to (x,y,z).

  // Destructor.
  ~Point3D();

  // Copy constructor and assignment operator.
  Point3D(const Point3D& p);
  Point3D& operator= (const Point3D& p);

  // Arithmetic.
  Point3D operator- (void) const;  // unary minus.
  Vector3D operator- (const Point3D& p) const;  // vector joining two points
  Point3D operator+ (const Vector3D& v) const;  // addition of a vector
  Point3D operator- (const Vector3D& v) const;  // subtraction of a vector
  Point3D operator* (const float s) const;  // scale the point by a factor, s.

  // Distance between points.
  float d_squared(const Point3D& p) const;  // square of distance
  float distance(const Point3D& p) const;  // distance
};

// Scale pt by a factor, s.
Point3D operator* (const float a, const Point3D& pt);
