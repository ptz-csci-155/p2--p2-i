#include "World.hpp" 
#include "../cameras/Perspective.hpp"
#include <vector>

ViewPlane vplane;
RGBColor bg_color;
std::vector<Geometry*> geometry;
std::vector<Light*> lights;
std::unique_ptr<Camera> camera_ptr;
std::unique_ptr<Sampler> sampler_ptr;

World::World(){
    vplane = ViewPlane();
    bg_color = RGBColor();
    std::vector<Geometry*> geometry = {};
    std::vector<Light*> lights = {};
    camera_ptr = NULL;
    sampler_ptr = NULL;
} // initialize members.

// Destructor.
World::~World(){

}  // free memory.

// Add to the scene.
void add_object(Geometry* geom_ptr){
    geometry.push_back(geom_ptr);
}
void add_light(Light* light_ptr){
    lights.push_back(light_ptr);
}
void set_camera(Camera* c_ptr){
    camera_ptr = std::unique_ptr(c_ptr);
}
// void set_ambient_light(Light* light_ptr);
// void set_tracer(Tracer* tracer_ptr);
// void set_acceleration(Acceleration* acceleration_ptr);


// Returns appropriate shading information corresponding to intersection of
// the ray with the scene geometry.
ShadeInfo hit_objects(const Ray& ray){
    ShadeInfo sinfo = new ShadeInfo(*this);
    float t = kHugeValue;
    for (const auto& shape: geometry){
        ShadeInfo temp_sinfo = new ShadeInfo(*this);
        float tempt = 0.0f;

        if(shape.hit(ray, tempt&, temp_sinfo&) && tempt < t ){
            t = tempt;
            sinfo = temp_sinfo;
        }
    }
    return sinfo;
}