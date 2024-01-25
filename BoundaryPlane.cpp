//
// Created by redkc on 24/01/2024.
//

#include "BoundaryPlane.h"

BoundaryPlane::BoundaryPlane(Vector3 p1, Vector3 p2, Vector3 p3, Vector3 edge1, Vector3 edge2)
        : Plane(p1, p2, p3), edge1(edge1), edge2(edge2) {
    v1 = p2 - p1;
    v2 = p3 - p1;
    n = v1.cross(v2);

    if (edge1.x > edge2.x){
        float tmp = edge1.x;
        edge1.x = edge2.x;
        edge2.x = tmp;
    }

    if (edge1.y > edge2.y){
        float tmp = edge1.y;
        edge1.y = edge2.y;
        edge2.y = tmp;
    }

    if (edge1.z > edge2.z){
        float tmp = edge1.z;
        edge1.z = edge2.z;
        edge2.z = tmp;
    }

}

bool BoundaryPlane::isPointWithinBoundary(Vector3 point) const {

    // Check if point is within boundary 
    return (point.x >= edge1.x && point.y >= edge1.y && point.z >= edge1.z ) && (point.x <= edge2.x && point.y <= edge2.y && point.z <= edge2.z );
}