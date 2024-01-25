//
// Created by redkc on 24/01/2024.
//

#ifndef MATGRAF__BOUNDARYPLANE_H
#define MATGRAF__BOUNDARYPLANE_H


#include "Plane.h"

class BoundaryPlane : public Plane {
private:
    Vector3 edge1, edge2;
public:
    BoundaryPlane(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 edge1, Vector3 edge2);
    bool isPointWithinBoundary(Vector3 point) const;
};


#endif //MATGRAF__BOUNDARYPLANE_H
