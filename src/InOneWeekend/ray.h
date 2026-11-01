#ifndef RAY_H
#define RAY_H
#include "Vec3.h"

/*
 * p(t) = A+tb
 * -- p -> (position somewhere along the ray) 3D position along a line in 3d
 * -- A -> ray origin
 * -- t -> scalar controlling how far the ray travel
 * -- b -> the ray direction
 */
class ray {
private:
  point3 origin_;
  vec3 direction_;

public:
  ray() {}
  ray(const point3 &origin, const vec3 &direction)
      : origin_(origin), direction_(direction) {}

  const point3 &origin() { return origin_; }
  const vec3 &direction() { return direction_; }

  point3 at(double t) const { return origin_ + t * direction_; }
};

#endif
