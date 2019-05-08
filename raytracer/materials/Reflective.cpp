#include "Reflective.hpp"
#include "../world/World.hpp"

// Default constructors.
Reflective::Reflective()
    : Material(),
      reflective_brdf(new PerfectSpecular),
      ambient_brdf(new Lambertian),
      diffuse_brdf(new Lambertian)
{}

// Copy constructor
Reflective::Reflective(const Reflective& rm)
    : Material(rm) {
    if (rm.reflective_brdf) {
        reflective_brdf = rm.reflective_brdf->clone();
    }
    else {
        reflective_brdf = nullptr;
    }

    if (rm.ambient_brdf) {
        ambient_brdf = rm.ambient_brdf->clone();
    }
    else {
        ambient_brdf = nullptr;
    }

    if (rm.diffuse_brdf) {
        diffuse_brdf = rm.diffuse_brdf->clone();
    }
    else {
        diffuse_brdf = nullptr;
    }
}

// Assignment operator
Reflective& Reflective::operator= (const Reflective& rhs) {
    if (this == &rhs) {
        return (*this);
    }

    Material::operator=(rhs);

    if (reflective_brdf) {
        delete reflective_brdf;
        reflective_brdf = nullptr;
    }

    if (rhs.reflective_brdf) {
        reflective_brdf = rhs.reflective_brdf->clone();
    }

    if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = nullptr;
	}

	if (rhs.ambient_brdf)
		ambient_brdf = rhs.ambient_brdf->clone();

	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = nullptr;
	}

	if (rhs.diffuse_brdf)
		diffuse_brdf = rhs.diffuse_brdf->clone();

    return (*this);
}

// Clone
Reflective* Reflective::clone() const {
    return (new Reflective(*this));
}

// Destructor
Reflective::~Reflective() {
    if (reflective_brdf) {
        delete reflective_brdf;
        reflective_brdf = NULL;
    }

    if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = nullptr;
	}

	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = nullptr;
	}
}

// shade
RGBColor Reflective::shade(const ShadeInfo& sr) const {
    


    Vector3D wo = -sr.ray.d;
    Vector3D wi;
    RGBColor fr = reflective_brdf->sample_f(sr, wo, wi);
    
    RGBColor L  = ambient_brdf->rho(sr, wo) * sr.w->ambient_ptr->L(sr);
    int num_lights = sr.w->lights.size();

    for (int i = 0; i < num_lights; i++)
    {
        wi = sr.w->lights[i]->get_direction(sr);
        float ndotwi = sr.normal * wi;

        // if (ndotwi > 0.0) {
        //     bool in_shadow = false;

        //     if (sr.w->lights[i])
        // }
    }
    

    Ray reflected_ray(sr.hit_point, wi);
    reflected_ray.w = sr.depth + 1;

    // I removed the depth thing here bc i guess this ray should have some sort of depth
    L += fr * (sr.w->tracer_ptr->trace_ray(reflected_ray)) * (sr.normal * wi);

    return (L);
}

inline void Reflective::set_kr(const float k) {
  reflective_brdf->set_kr(k);
}

inline void Reflective::set_cr(const RGBColor& c) {
  reflective_brdf->set_cr(c);
}

inline void Reflective::set_cr(const float r, const float g, const float b) {
  reflective_brdf->set_cr(r, g, b);
}

inline void Reflective::set_cr(const float c) {
  reflective_brdf->set_cr(c);
}
