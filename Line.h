//
// Created by redkc on 20/12/2023.
//

#ifndef MATGRAF__LINE_H
#define MATGRAF__LINE_H

#include <cmath>

#include "Vector3.h"
#include "Sphere.h"

class Line {
public:
    Vector3 p1;
    Vector3 p2;
    Vector3 v;

    Line();
    Line(Vector3 p1, Vector3 p2);
    Vector3 Intersect(const Line& l) const;
    int Intersect(const Sphere& ,Vector3 *points);
    float Angle(const Line& l) const;
    
};


#endif //MATGRAF__LINE_H
