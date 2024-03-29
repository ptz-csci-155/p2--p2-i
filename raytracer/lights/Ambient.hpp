#pragma once
#include "../utilities/RGBColor.hpp"
#include "Light.hpp"

/**
   This file declares the Ambient class which represents an ambient light source.

   Courtesy Kevin Suffern.
*/

class Ambient: public Light {
public:
  // Constructors.
  Ambient();  // set color to white (1, 1, 1), ls to 0
  Ambient(float c, float ls);  // set color to (c, c, c).
  Ambient(float r, float g, float b, float ls);  // set color to (r, g, b).
  Ambient(const RGBColor& _color, float ls);  // set color to _color.

  // Copy constructor and assignment operator.
  Ambient(const Ambient& rhs);
  Ambient& operator= (const Ambient& rhs);

  // Virtual copy constructor.
  virtual Ambient* clone() const;

  // Desctructor.
  virtual ~Ambient(void);  // dummy function.

  // Normalized direction vector from light source to hit point.
  virtual Vector3D get_direction(const ShadeInfo& sinfo) const;

  // Luminance from this light source at hit point.
  virtual RGBColor L(const ShadeInfo& sinfo) const;
protected:
  float ls;
};
