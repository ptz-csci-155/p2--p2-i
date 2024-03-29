#pragma once
#include "../utilities/ShadeInfo.hpp"
#include "../utilities/RGBColor.hpp"
#include <vector>
#include<algorithm>
/**
   This file declares the Material class which is an abstract class for concrete
   materials to inherit from.

   Courtesy Kevin Suffern.
*/

class Material {
public:
  // Constructors.
  Material();  // does nothing.

  // Copy constuctor and assignment operator.
  Material(const Material& other);
  Material& operator=(const Material& other);

  // Virtual copy constructor.
  virtual Material* clone() const = 0;

  // Desctructor.
  virtual ~Material();

  // Get color.
  virtual RGBColor shade(const ShadeInfo& sinfo, std::vector<int> shadows) const = 0;
};
