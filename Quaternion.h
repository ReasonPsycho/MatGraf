//
// Created by redkc on 23/11/2023.
//

#ifndef MATGRAF__QUATERNION_H
#define MATGRAF__QUATERNION_H


#include "Vector3.h"
#include <string>

class Quaternion {
public:
    float a;
    Vector3 v;
    Quaternion(float a, Vector3 v) : a(a), v(v) {}

    Quaternion operator+(const Quaternion& q) const;
    Quaternion operator-(const Quaternion& q) const;
    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator/(const Quaternion& q) const;
    static Vector3 rotationX(const Vector3& vector,float angle);
    static Vector3 rotationY(const Vector3& vector,float angle);
    static Vector3 rotationZ(const Vector3& vector,float angle);
    Quaternion conjugate();
    bool operator==(const Quaternion& q) const;
    std::string toString() const;
};


#endif //MATGRAF__QUATERNION_H