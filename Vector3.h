//
// Created by redkc on 19/10/2023.
//

#ifndef MATGRAF_VECTOR3_H
#define MATGRAF_VECTOR3_H


#include <sstream>

class Vector3 {
public: 
    float x,y,z;
    Vector3() : x(0), y(0), z(0) {};
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3(const Vector3 &v) : x(v.x), y(v.y), z(v.z) {};

    void operator+=(const Vector3& v);
    Vector3 operator+(const Vector3& v) const;
    void operator-=(const Vector3& v);
    Vector3 operator-(const Vector3& v) const;
    void operator*=(float f);
    Vector3 operator*(float f) const;
    void operator/=(float f);
    Vector3 operator/(float f) const;
    bool operator==(const Vector3& v) const;
    [[nodiscard]] float length() const;
    void normalize();
    [[nodiscard]] Vector3 dot(const Vector3& v) const;
    [[nodiscard]] float dotProduct(const Vector3& v) const;
    [[nodiscard]] Vector3 cross(const Vector3& v) const;
    [[nodiscard]] std::string toString() const;
};



#endif //MATGRAF_VECTOR3_H
