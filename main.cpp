#include <iostream>
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
#include "Utilis.h"
#include "Line.h"
#include "Plane.h"

int main() {
    Line FirstA = Line(Vector3(-2,5,0),Vector3(3,1,5));
    Line FirstB = Line(Vector3(-2,4,0),Vector3(1,-5,3));

    std::cout << "They intersect at point: " << FirstA.Intersect(FirstB).toString() << ".\n";
    std::cout << "And they have angle of: " << std::to_string(FirstA.Angle(FirstB)) << " radians between them.\n";

    Line ThirdA = Line(Vector3(-2,2,-1),Vector3(-5,3,-3));
    Plane ThirdB = Plane(Vector3(0,8.0f/3,0),Vector3(4,0,0),Vector3(0,5.0f/3,1));

    std::cout << "They intersect at point: " << ThirdB.Intersect(ThirdA).toString() << ".\n";
    std::cout << "And they have angle of: " << std::to_string(ThirdB.Angle(ThirdA)) << " radians between them.\n";

    Plane FiveA = Plane(Vector3(0,-8,0),Vector3(4,0,0),Vector3(0,0,8));
    Plane FiveB = Plane(Vector3(0,-14.0f/3,0),Vector3(-7.0f/2,0,0),Vector3(1,0,-18));

    std::cout << "They intersect at point: " << FiveA.Intersect(FiveB).toString() << ".\n";
    std::cout << "And they have angle of: " << std::to_string(FiveA.Angle(FiveB)) << " radians between them.\n";

    Line SevenA = Line(Vector3(5,5,4),Vector3(10,10,6));
    Line SevenB = Line(Vector3(5,5,5),Vector3(10,10,3));

    std::cout << "They intersect at point: " << SevenA.Intersect(SevenB).toString() << ".\n";
    std::cout << "And they have angle of: " << std::to_string(SevenA.Angle(SevenB)) << " radians between them.\n";

    Sphere NineA = Sphere(Vector3(0,0,0), sqrt(26));
    Line NineB = Line(Vector3(3,-1,-2),Vector3(5,3,-4));

    Vector3 returnPoints[2];
    int howMany = NineB.Intersect(NineA,returnPoints);

    if(howMany > 0){
        for (int i = 0; i < howMany; ++i) {
            std::cout << "They intersect at point: " << returnPoints[i].toString() << ".\n";
        }
    }else{
        std::cout << "They don't intersect!";
    }
    return 0;
}
