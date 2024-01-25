//
// Created by redkc on 24/01/2024.
//

#ifndef MATGRAF__CUBE_H
#define MATGRAF__CUBE_H

#include "BoundaryPlane.h"
#include <array>

class Cube {
private:
    std::array<BoundaryPlane, 6> faces;
public:
    Cube(std::array<BoundaryPlane, 6> planes);
    bool isPointWithinCube(Vector3 point) const;
    int Intersect(const Line &ray) const;
};


#endif //MATGRAF__CUBE_H
