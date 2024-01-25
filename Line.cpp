//
// Created by redkc on 20/12/2023.
//

#include "Line.h"

Vector3 Line::Intersect(const Line &l) const {
    Vector3 p12 = p1 - l.p1;
    Vector3 c1crossc2 = v.cross(l.v);
    Vector3 c12 = v.cross(p12);
    Vector3 c21 = l.v.cross(p12);

    double c1crossc2Magnitude = c1crossc2.length();
		
    // Prevent division by donut error (because engineers are always hungry)
    if (fabs(c1crossc2Magnitude) < 1e-8){
        // Lines are parallel or collinear, no unique intersection point
        return Vector3(NAN, NAN, NAN);
    }

    double s = c21.length() / c1crossc2Magnitude;
    double t = c12.length() / c1crossc2Magnitude;

    // The relative direction of the cross products indicates whether the parameters are positive or negative.
    if (c1crossc2.dotProduct(c12) < 0) {
        t = -t;
    }
    if (c1crossc2.dotProduct(c21) < 0) {
        s = -s;
    }

    Vector3 ip1 = p1 + v*t;
    Vector3 ip2 = l.p1 + l.v*s;

    // If the intersection points from each line are not approximately equal the lines do not intersect.
    if((ip1 - ip2).length() > 1e-6 ){
        return Vector3(NAN,NAN,NAN);
    }

    // ip1  or 'ip2' is the intersection point, both are about the same.
    return ip1;
}

float Line::Angle(const Line &l) const {
    return acos( v.dotProduct(l.v)/(v.length() * l.v.length()))*57.2957795f;
}

Line::Line(Vector3 p1, Vector3 p2) : p1(p1), p2(p2){
    v = p1 - p2;
}

Line::Line() {
    p1 = Vector3();
    p2 = Vector3();
    v = p1 - p2;
}

int Line::Intersect(const Sphere &s, Vector3 *points) {
    // I was going to make a joke about spheres. But then I realized it's pointless.
    float a = v.x * v.x + v.y * v.y + v.z * v.z;
    float b = 2 * (v.x * (p1.x - s.centerPoint.x) +
                   v.y * (p1.y - s.centerPoint.y) +
                   v.z * (p1.z - s.centerPoint.z));
    float c = (p1.x - s.centerPoint.x) * (p1.x - s.centerPoint.x) +
              (p1.y - s.centerPoint.y) * (p1.y - s.centerPoint.y) +
              (p1.z - s.centerPoint.z) * (p1.z - s.centerPoint.z) - s.radius * s.radius;

    // Calculate the discriminant
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No real solutions: line does not intersect the sphere
        return 0;
    }else if (discriminant == 0){
        double t = -b / (2 * a);

        // Became a kettle, because it's always up to some steam (tangent point)
        points[0].x = p1.x + t * v.x;
        points[0].y = p1.y + t * v.y;
        points[0].z = p1.z + t * v.z;

        return 1;
    }else{
        double t1 = (-b + sqrt(discriminant)) / (2 * a);
        double t2 = (-b - sqrt(discriminant)) / (2 * a);

        // Calculate intersection points (Because points have a tendency to intersect, just for the fun of it!)
        points[0].x = p1.x + t1 * v.x;
        points[0].y = p1.y + t1 * v.y;
        points[0].z = p1.z + t1 * v.z;

        points[1].x = p1.x + t2 * v.x;
        points[1].y = p1.y + t2 * v.y;
        points[1].z = p1.z + t2 * v.z;
    
        return 2;
    }
}


