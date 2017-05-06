#pragma once

#include "Vec3.h"

class AABB {

public:

    Vec3 min, max;
    bool empty;

    AABB();
    AABB(float, float, float, float, float, float);
    AABB(Vec3 const&, Vec3 const&);
    AABB(Vec3 const&, float);

    bool isNan() const;
    bool isEmpty() const;

    void set(AABB const&);
    void set(float, float, float, float, float, float);
    void set(Vec3 const&, Vec3 const&);
    void expand(Vec3 const&);
    void move(Vec3 const&);
    void move(float, float, float);
    void centerAt(Vec3 const&);

    AABB grow(Vec3 const&) const;
    AABB expanded(Vec3 const&) const;
    AABB translated(Vec3 const&) const;
    AABB merge(AABB const&) const;
    AABB cloneMove(Vec3 const&) const;
    AABB resize(Vec3 const&) const;
    AABB shrink(Vec3 const&) const;
    AABB clip(Vec3 const&, Vec3 const&) const;
    AABB flooredCopy(float, float) const;
    AABB flooredCeiledCopy() const;

    Vec3 clipCollide(AABB const&, Vec3 const&, bool, float*) const;
    float _clipAxisCollide(AABB const&, float, int, bool) const;
    float clipXCollide(AABB const&, float, bool) const;
    float clipYCollide(AABB const&, float, bool) const;
    float clipZCollide(AABB const&, float, bool) const;

    bool intersects(AABB const&) const;
    bool intersectsInner(AABB const&) const;
    bool intersects(Vec3 const&, Vec3 const&) const;
    bool intersectSegment(Vec3 const&, Vec3 const&, Vec3&, Vec3&) const;

    Vec3 getSmallestAxisOut(AABB const&) const;
    Vec3 axisInside(AABB const&, Vec3) const;

    float distanceTo(Vec3 const&) const;
    float distanceToSqr(Vec3 const&) const;
    float distanceTo(AABB const&) const;
    float distanceToSqr(AABB const&) const;

    Vec3 getBounds() const;
    Vec3 getCenter() const;
    bool contains(Vec3 const&) const;
    float getSize() const;

    std::string toString() const;

    static AABB fromPoints(Vec3 const&, Vec3 const&);

    static AABB EMPTY;

};

