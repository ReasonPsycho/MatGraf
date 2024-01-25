//
// Created by redkc on 09/11/2023.
//

#ifndef MATGRAF__MATRIX4X4_H
#define MATGRAF__MATRIX4X4_H

#include <string>

class Vector3;

class Matrix4x4 {
public:
    float m_elements[16]{};
    
    Matrix4x4() = default;
    // Default constructor
    Matrix4x4(const float *pF);
    Matrix4x4(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33);
    Matrix4x4(Matrix4x4 &mat);  // Constructor with array of elements

    // Matrix operations
    Matrix4x4 operator+(const Matrix4x4 &mat);
    Matrix4x4 operator-(const Matrix4x4 &mat);
    Matrix4x4 operator*(const float f);
    Matrix4x4 operator*(const Matrix4x4  &mat);
    bool operator==(const Matrix4x4  &mat);
    bool operator!=(const Matrix4x4  &mat);

    static Matrix4x4 identy();

    void InverseMatrix();
    void TransposeMatrix();
    void SetTranslation(const Vector3 &translation);
    void SetScale(const Vector3 &scaleFactor);
    void SetUniformScale(const float scaleFactor);
    void SetRotationAxis(const double angle, const Vector3 axis);
    void SetRotationZ(const double angle);
    void SetRotationY(const double angle);
    void SetRotationX(const double angle);
    std::string toString();

};

#include "Vector3.h"


#endif //MATGRAF__MATRIX4X4_H
