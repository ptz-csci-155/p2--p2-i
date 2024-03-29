#pragma once

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <vector>
#include <tuple>


class Mesh {
public:
  std::vector<Point3D> vertices;
  // normal at each vertex;
  std::vector<Vector3D> normals;
  // the triangles shared by each vertex
  std::vector<std::vector<int> > 	vertex_faces;
  std::vector<std::tuple<int, int, int>>tris;
  int num_vertices;
  int num_triangles;
  float x_offset;
  float y_offset;
  float z_offset;

  Mesh(char* file_name);
  Mesh(char* file_name, float x, float y, float z);

  Mesh(const Mesh& m);

  ~Mesh();

  Mesh&
  operator= (const Mesh& rhs);

  void populate(char* file_name);
};
