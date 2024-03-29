#include "Simple.hpp"
#include "../utilities/Constants.hpp"
#include "../utilities/Point3D.hpp"
#include "../world/ViewPlane.hpp"
#include <iostream>

Simple::Simple(){
    camera_ptr = nullptr;
    viewplane_ptr = nullptr;
}  // initializes members to NULL.

Simple::Simple(Camera* c_ptr, ViewPlane* v_ptr){
    camera_ptr = c_ptr;
    viewplane_ptr = v_ptr;
}  // set members.

// Copy constuctor and assignment operator.
Simple::Simple(const Simple& camera){
    camera_ptr = camera.camera_ptr;
    viewplane_ptr = camera.viewplane_ptr;
}

Simple& Simple::operator= (const Simple& other){
    this->camera_ptr = other.camera_ptr;
    this->viewplane_ptr = other.viewplane_ptr;
    return *this;
}

// Virtual copy constructor.
Simple* Simple::clone() const{
    return new Simple(*this);
}

// Desctructor.
Simple::~Simple(){}

// Shoot a ray of weight 1 through the center of the pixel.
std::vector<Ray> Simple::get_rays(int px, int py) {
    Point3D point = screenCoordsToPoint(px + .5, py + .5);
    Ray new_ray = Ray(point, camera_ptr->get_direction(point));
    std::vector<Ray> rays = {new_ray};
    return rays;
}
