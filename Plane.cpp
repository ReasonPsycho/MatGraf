//
// Created by redkc on 20/12/2023.
//

#include "Plane.h"

Plane::Plane(Vector3 p1, Vector3 p2, Vector3 p3) : p1(p1),p2(p2),p3(p3) {
     v1 = p2 - p1;
     v2 = p3 - p1;
     n = v1.cross(v2);
}

Vector3 Plane::Intersect(const Line &l) const {
    float t = (n.dotProduct(p1 - l.p1))/(n.dotProduct(l.v));
    return l.p1+l.v*t;
}

float Plane::Angle(const Line &l) const {
    return acos( n.dotProduct(l.v)/(n.length() * l.v.length()))*57.2957795f;
}

Vector3 Plane::Intersect(const Plane &p) const {
    Vector3 direction = n.cross(p.n);
    if (direction == Vector3(0,0,0)){
        return Vector3(NAN,NAN,NAN);
    }

    return p.n.cross( p.p1) -n.cross(p1) ;
}

float Plane::Angle(const Plane &p) const {
    return acos(n.dotProduct(p.n)/(n.length()*p.n.length()))*57.2957795f;
}
