//
// Created by redkc on 24/01/2024.
//

#include "Camera.h"

Camera::Camera(Vector3 pos) : position(pos) {
}

std::array<std::array<Line, 60>, 60> Camera::CastRays()  {
    // Assuming field of view of the camera is 60 degrees
    // Assuming each ray represents 1 degree
    for (int x = 0; x < 60; ++x) {
        for(int y = 0; y < 60; ++y){
            Vector3 startPos = Vector3((( x-30)/zoom), (( y-15)/zoom), position.z);
            Vector3 endPos = startPos + Vector3(0,0,100);

            // Apply yaw, pitch and roll rotation to both startPos and endPos
            startPos = applyRotation(startPos, yaw, pitch, roll);
            endPos = applyRotation(endPos, yaw, pitch, roll);

            startPos += applyRotation(position, yaw, pitch, roll);
            // Create ray starting from camera position with given direction
            rays[x][y] = Line(startPos, endPos);
        }
    }
    return rays;
}

Vector3 Camera::applyRotation(Vector3 pos, float yaw, float pitch, float roll) {
    // Apply yaw rotation (rotation around Y axis)
    double newX = cos(yaw) * pos.x - sin(yaw) * pos.z;
    double newZ = sin(yaw) * pos.x + cos(yaw) * pos.z;
    pos.x = newX;
    pos.z = newZ;

    // Apply pitch rotation (rotation around X axis)
    double newY = cos(pitch) * pos.y - sin(pitch) * pos.x;
    newX = sin(pitch) * pos.y + cos(pitch) * pos.x;
    pos.x = newX;
    pos.y = newY;

    // Apply roll rotation (rotation around Z axis)
    newX = cos(roll) * pos.x - sin(roll) * pos.y;
    newY = sin(roll) * pos.x + cos(roll) * pos.y;
    pos.x = newX;
    pos.y = newY;

    return pos;
}