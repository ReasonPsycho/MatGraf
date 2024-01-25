//
// Created by redkc on 23/11/2023.
//

#include <valarray>
#include "Quaternion.h"
#include "Utilis.h"

Quaternion Quaternion::operator+(const Quaternion &q) const {
    return {a + q.a, v + v};
}

Quaternion Quaternion::operator-(const Quaternion &q) const {
    return {a - q.a, v - v};
}

Quaternion Quaternion::operator*(const Quaternion &q) const {
    return {a * q.a - v.dotProduct(q.v), q.v*a + v*q.a + v.cross(q.v)};
}

Quaternion Quaternion::operator/(const Quaternion &q) const {
    return {(a*q.a + v.dotProduct(q.v))/((q.a * q.a) + q.v.dotProduct(q.v)),  ((v*q.a) - v.cross(q.v) - (q.v*a))*((q.a * q.a) + q.v.dotProduct(q.v))};
}

bool Quaternion::operator==(const Quaternion &q) const {
    if(a == q.a && v == q.v){
        return true;
    }
    return false;
}

std::string Quaternion::toString() const {
    std::ostringstream oss;
    oss << "(" << a << ",( " << v.toString() << ")";
    return oss.str();
}

Quaternion Quaternion::conjugate() {
    return(Quaternion( a,Vector3(-v.x,-v.y,-v.z)));
}

Vector3 Quaternion::rotationX(const Vector3 &vector, float angle) {
    float fixedAngle = angle * M_PI / 180.0f;

    Quaternion rotatioQuaternion = Quaternion(cos(fixedAngle / 2), Vector3(sin(fixedAngle / 2),0.0f,0.0f));
    Quaternion vectorQuaternion(0.0f,Vector3(-1,-1,-1));
    Quaternion conjugated = rotatioQuaternion.conjugate();

    Quaternion rotated = rotatioQuaternion * vectorQuaternion * conjugated;
    return rotated.v;
}

Vector3 Quaternion::rotationY(const Vector3 &vector, float angle) {
    float fixedAngle = angle * M_PI / 180.0f;

    Quaternion rotatioQuaternion = Quaternion(cos(fixedAngle / 2), Vector3(0.0f,sin(fixedAngle / 2),0.0f));
    Quaternion vectorQuaternion(0.0f,Vector3(-1,-1,-1));
    Quaternion conjugated = rotatioQuaternion.conjugate();

    Quaternion rotated = rotatioQuaternion * vectorQuaternion * conjugated;
    return rotated.v;
}

Vector3 Quaternion::rotationZ(const Vector3 &vector, float angle) {
    float fixedAngle = angle * M_PI / 180.0f;

    Quaternion rotatioQuaternion = Quaternion(cos(fixedAngle / 2), Vector3(0.0f,0.0f,sin(fixedAngle / 2)));
    Quaternion vectorQuaternion(0.0f,vector);
    Quaternion conjugated = rotatioQuaternion.conjugate();

    Quaternion rotated = rotatioQuaternion * vectorQuaternion * conjugated;
    return rotated.v;
}
