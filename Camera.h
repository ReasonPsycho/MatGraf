//
// Created by redkc on 24/01/2024.
//

#ifndef MATGRAF__CAMERA_H
#define MATGRAF__CAMERA_H


#include "Line.h"
#include "Quaternion.h"
#include <array>

class Camera {
private:
    
    std::array<std::array<Line, 60>, 60> rays {};
public:
    Vector3 position;
    float zoom = 5.0f;
    float roll = 0.0f;
    float pitch = 0.0f;
    float yaw = 0.0f;
    Camera(Vector3 pos);
    Vector3 applyRotation(Vector3 pos, float yaw, float pitch, float roll);
    std::array<std::array<Line, 60>, 60> CastRays();
};


#endif //MATGRAF__CAMERA_H
