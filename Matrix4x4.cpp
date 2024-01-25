//
// Created by redkc on 09/11/2023.
//
#include <cstring>
#include <valarray>
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Utilis.h"


Matrix4x4::Matrix4x4(const float *pF) {
    memcpy(m_elements,pF,16*sizeof(float ));
}

Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03,
                     float m10, float m11, float m12, float m13,
                     float m20, float m21, float m22, float m23,
                     float m30, float m31, float m32, float m33) {
    // Set the elements using the provided arguments
    m_elements[0] = m00;
    m_elements[1] = m01;
    m_elements[2] = m02;
    m_elements[3] = m03;
    m_elements[4] = m10;
    m_elements[5] = m11;
    m_elements[6] = m12;
    m_elements[7] = m13;
    m_elements[8] = m20;
    m_elements[9] = m21;
    m_elements[10] = m22;
    m_elements[11] = m23;
    m_elements[12] = m30;
    m_elements[13] = m31;
    m_elements[14] = m32;
    m_elements[15] = m33;
}

Matrix4x4::Matrix4x4(Matrix4x4 &mat) {
    memcpy(m_elements,mat.m_elements,16*sizeof(float ));
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 &mat) {
    return Matrix4x4(
            m_elements[0] + mat.m_elements[0],
            m_elements[1] + mat.m_elements[1],
            m_elements[2] + mat.m_elements[2],
            m_elements[3] + mat.m_elements[3],
            m_elements[4] + mat.m_elements[4],
            m_elements[5] + mat.m_elements[5],
            m_elements[6] + mat.m_elements[6],
            m_elements[7] + mat.m_elements[7],
            m_elements[8] + mat.m_elements[8],
            m_elements[9] + mat.m_elements[9],
            m_elements[10] + mat.m_elements[10],
            m_elements[11] + mat.m_elements[11],
            m_elements[12] + mat.m_elements[12],
            m_elements[13] + mat.m_elements[13],
            m_elements[14] + mat.m_elements[14],
            m_elements[15] + mat.m_elements[15]
    );
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 &mat) {
    return Matrix4x4(
            m_elements[0] - mat.m_elements[0],
            m_elements[1] - mat.m_elements[1],
            m_elements[2] - mat.m_elements[2],
            m_elements[3] - mat.m_elements[3],
            m_elements[4] - mat.m_elements[4],
            m_elements[5] - mat.m_elements[5],
            m_elements[6] - mat.m_elements[6],
            m_elements[7] - mat.m_elements[7],
            m_elements[8] - mat.m_elements[8],
            m_elements[9] - mat.m_elements[9],
            m_elements[10] - mat.m_elements[10],
            m_elements[11] - mat.m_elements[11],
            m_elements[12] - mat.m_elements[12],
            m_elements[13] - mat.m_elements[13],
            m_elements[14] - mat.m_elements[14],
            m_elements[15] - mat.m_elements[15]
    );    
}

Matrix4x4 Matrix4x4::operator*(const float f) {
    return Matrix4x4(
            m_elements[0] *f,
            m_elements[1] *f,
            m_elements[2] *f,
            m_elements[3] *f,
            m_elements[4] *f,
            m_elements[5] *f,
            m_elements[6] *f,
            m_elements[7] *f,
            m_elements[8] *f,
            m_elements[9] *f,
            m_elements[10] *f,
            m_elements[11] *f,
            m_elements[12] *f,
            m_elements[13] *f,
            m_elements[14] *f,
            m_elements[15] *f
    );
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 &mat) {
    float output[16];
   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float sum = 0.0;
            for (int k = 0; k < 4; k++) {
                sum += m_elements[i * 4 + k] * mat.m_elements[k * 4 + j];
            }
            output[i * 4 + j] = sum;
        }
    }
    return Matrix4x4(output);
}

Matrix4x4 Matrix4x4::identy() {
    return Matrix4x4(
            1,0,0,0,
            0,1,0,0,
            0,0,1,0,
            0,0,0,1
    );
}

void getCofactor(float A[16], float temp[16], int p, int q, int n) {
    int i = 0, j = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i * (n - 1) + j++] = A[row * n + col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

float determinant(float A[16], int n) {
    float det = 0;
    if (n == 1) {
        return A[0];
    }
    float temp[16];
    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(A, temp, 0, f, n);
        det += sign * A[f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

void adjoint(float A[16], float adj[16]) {
    if (16 == 1) {
        adj[0] = 1;
        return;
    }
    int sign = 1;
    float temp[16];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            getCofactor(A, temp, i, j, 4);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j * 4 + i] = (sign) * (determinant(temp, 4 - 1));
        }
    }
}

 void Matrix4x4::InverseMatrix(){
    float output[16];
     float det = determinant(m_elements, 4);
     if (det == 0) {
         return ;
     }
     float adj[16];
     adjoint(m_elements, adj);
     for (int i = 0; i < 16; i++) {
         m_elements[i] = adj[i] / det;
     }
}



void Matrix4x4::TransposeMatrix() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j<i){
                float swap =  m_elements[i*4 + j];
                m_elements[i*4 + j] = m_elements[j*4 + i];
                m_elements[j*4 + i] = swap;
            }
        }
    }
}

void Matrix4x4::SetTranslation(const Vector3 & translation) {
    m_elements[12]=translation.x;
    m_elements[13]=translation.y;
    m_elements[14]=translation.z;
}

void Matrix4x4::SetScale(const Vector3 & scaleFactor) {
    identy();
    m_elements[0] = scaleFactor.x;
    m_elements[5] = scaleFactor.y;
    m_elements[10] = scaleFactor.z;
}

void Matrix4x4:: SetUniformScale(const float scaleFactor) {
    identy();
    m_elements[0] = scaleFactor;
    m_elements[5] = scaleFactor;
    m_elements[10] = scaleFactor;
}

void Matrix4x4:: SetRotationAxis(const double angle, const Vector3 axis) {
     Vector3 u = axis;
     u.normalize();
    
    float sinAngle = (float) sin (M_PI*angle/180);
    float cosAngle= (float) cos (M_PI*angle/180);
    float oneMinusCosAngle=1.0f-cosAngle;
    identy();
    m_elements [0]=(u.x) * (u.x) + cosAngle* (1-(u.x)*(u.x));
    m_elements [4]=(u.x) * (u.y)*(oneMinusCosAngle) - sinAngle*u.z;
    m_elements [8]=(u.x) * (u.z)* (oneMinusCosAngle) + sinAngle*u.y;

    m_elements [1]=(u.x) * (u. y) * (oneMinusCosAngle) + sinAngle*u.z;
    m_elements [5]=(u. y) * (u.y) + cosAngle* (1-(u.y) * (u.y));
    m_elements [9]=(u. y) * (u.z)* (oneMinusCosAngle) - sinAngle*u.x;
    
    m_elements [2]=(u.x) * (u.z)* (oneMinusCosAngle) - sinAngle*u.y;
    m_elements [6]=(u. y) * (u.z)* (oneMinusCosAngle) + sinAngle*u.x;
    m_elements [10]=(u.z)* (u.z) + cosAngle* (1-(u.z)*(u.z));
}

void Matrix4x4:: SetRotationX (const double angle) {
    identy();
    m_elements[5] = (float) cos(M_PI * angle / 180);
    m_elements[6] = (float) sin(M_PI * angle / 180);
    m_elements[9] = -m_elements[6];
    m_elements[10] = m_elements[5];
}
void Matrix4x4::SetRotationY (const double angle) {
    identy();
    m_elements[0] = (float) cos(M_PI * angle / 180);
    m_elements[2] = -(float) sin(M_PI * angle / 180);
    m_elements[8] = -m_elements[2];
    m_elements[10] = m_elements[0];
}
void Matrix4x4::SetRotationZ (const double angle) {
    identy();
    m_elements [0]= (float) cos (M_PI*angle/180);
    m_elements [1]= (float) sin (M_PI*angle/180);
    m_elements [4]=-m_elements [1];
    m_elements [5]=m_elements[0];
}

bool Matrix4x4::operator==(const Matrix4x4 &mat) {

    for (int i = 0; i < 16; ++i) {
        if (abs(m_elements[i] - mat.m_elements[i]) > 0.0001){
            return false;
        }
    }
    return true;
}

bool Matrix4x4::operator!=(const Matrix4x4 &mat) {
    return !(this == &mat);
}

std::string Matrix4x4::toString() {
    std::string output = "";

    output += "----------\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            output += std::to_string(m_elements[i * 4 + j])+ " ";
        }
        output += "\n";
    }
    output += "----------\n";
    return output;
}
