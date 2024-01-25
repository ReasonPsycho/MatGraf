//
// Created by redkc on 20/12/2023.
//

#ifndef MATGRAF__PLANE_H
#define MATGRAF__PLANE_H


#include "Vector3.h"
#include "Line.h"

class Plane {
public:
    Vector3 p1;
    Vector3 p2;
    Vector3 p3;
    Vector3 v1;
    Vector3 v2;
    Vector3 n;
    
    Plane(Vector3 p1,Vector3 p2,Vector3 p3);
    Vector3 Intersect(const Line& l) const;
    Vector3 Intersect(const Plane& p) const;
    float Angle(const Line& l) const;
    float Angle(const Plane& p) const;

};


#endif //MATGRAF__PLANE_H
