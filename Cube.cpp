//
// Created by redkc on 24/01/2024.
//

#include "Cube.h"

Cube::Cube(std::array<BoundaryPlane, 6> planes) : faces(planes) {}

bool Cube::isPointWithinCube(Vector3 point) const {
    // If point is not within boundary of any of the faces, return false
    for (const auto &face : faces) {
        if (!face.isPointWithinBoundary(point)) {
            return false;
        }
    }
    // If the point is within the boundary of all faces, return true
    return true;
}

int Cube::Intersect(const Line &ray) const {
    int closest_face_index = -1;
    float closest_distance = std::numeric_limits<float>::max();

    for (int i = 0; i < faces.size(); ++i) {
        Vector3 point = faces[i].Intersect(ray);
        if (faces[i].isPointWithinBoundary(point)) {
            float distance = (ray.p1 - point).length();
            if (distance < closest_distance) {
                closest_distance = distance;
                closest_face_index = i;
            }
        }
    }

    return closest_face_index;
}