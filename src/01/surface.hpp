#pragma once

#include "math.hpp"

class Material;

class HitRecord
{
public:
    bool haveHit;       // do we have a hit? Otherwise the following fields are irrelevant.
    float a;            // hit position = ray.origin + a * ray.direction
    vec3 position;      // hit position = ray.origin + a * ray.direction
    vec3 normal;        // normal at hit position; always points towards the ray, also for back sides
    const Material* material; // the material of the surface

    HitRecord() : haveHit(false)
    {
    }

    HitRecord(float a, const vec3& p, const vec3& n, const Material* m) :
        haveHit(true), a(a), position(p), normal(n), material(m)
    {
    }
};

class Surface
{
public:
    virtual HitRecord hit(const Ray& /* ray */, float /* amin */, float /* amax */) const
    {
        return HitRecord();
    }
};
