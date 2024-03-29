#pragma once
#include <string>

/**
   This file declares the class RGBColor which represents an RGB color.

   Each of the r, g, b components is clamped within [0,1], i.e. if a component
   becomes less than 0 or greater than 1, e.g. due to an operation, it is made
   equal to 0 or 1 respectively.

  Courtesy Kevin Suffern.
*/

class RGBColor {
public:
  float	r, g, b;  // red, green, and blue components in [0,1].

public:
  // Constructors.
  RGBColor(void);  // set color to (0, 0, 0).
  RGBColor(float c);  // set color to (c, c, c).
  RGBColor(float _r, float _g, float _b);  // set color to (_r, _g, _b).

  // Destructor.
  ~RGBColor(void);

  // Copy constructor and assignment operator.
  RGBColor(const RGBColor& c);
  RGBColor& operator= (const RGBColor& rhs);

  // Operations.
  RGBColor operator+(const RGBColor& c) const;  // addition.
  RGBColor& operator+=(const RGBColor& c);  // compound addition.
  RGBColor operator*(const float a) const;  // multiplication by a float.
  RGBColor& operator*=(const float a);  // compound multiplication by a float.
  RGBColor operator/(const float a) const;  // division by a float.
  RGBColor& operator/=(const float a);  // compound division by a float.

  RGBColor operator*(const RGBColor& c) const;  // component-wise multiplication.
  bool operator==(const RGBColor& c) const;  // equality.
  RGBColor powc(float p) const;  // raise components to a power.
  float average(void) const;  // the average of the components.
  std::string toString() const;
private:
  void setR(float _r);
  void setB(float _b);
  void setG(float _g);
};

// Multiplication by a float.
RGBColor operator* (const float a, const RGBColor& c);
