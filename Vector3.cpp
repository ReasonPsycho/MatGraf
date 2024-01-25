//
// Created by redkc on 19/10/2023.
//

#include <stdexcept>
#include <cmath>
#include "Vector3.h"

void Vector3::operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
}


void Vector3::operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

void Vector3::operator*=(float f) {

    x *= f;
    y *= f;
    z *= f;
}

void Vector3::operator/=(float f) {
    if (f != 0) {
        x /= f;
        y /= f;
        z /= f;
    } else {
        throw std::runtime_error("Division by zero error in Vector3 operator /="); // throw an exception
    }
}

float Vector3::length() const {
    return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

void Vector3::normalize() {
    float n = length();
    if (n != 0) {
        operator/=(n);
    } else {
        throw std::runtime_error("Division by zero error in Vector3 normalize"); // throw an exception
    }
}

Vector3 Vector3::dot(const Vector3 &v) const {
    Vector3 dotResult;
    dotResult.x = x * v.x;
    dotResult.y = y * v.y;
    dotResult.z = x * v.z;
    return dotResult;
}

float Vector3::dotProduct(const Vector3 &v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3 &v) const {
    return Vector3( y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}

bool Vector3::operator==(const Vector3 &v) const {
    return (x == v.x && y == v.y && z == v.z);
}

std::string Vector3::toString()  const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}

Vector3 Vector3::operator+(const Vector3 &v) const {
    return {
    x + v.x,
    y + v.y,
    z + v.z};
}

Vector3 Vector3::operator-(const Vector3 &v) const {
    return {
            x - v.x,
            y - v.y,
            z - v.z};
}

Vector3 Vector3::operator*(float f) const {
    return {
            x * f,
            y * f,
            z * f};
}

Vector3 Vector3::operator/(float f) const {
    return {
            x / f,
            y / f,
            z / f};
}

