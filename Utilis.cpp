//
// Created by redkc on 19/10/2023.
//

#include "Utilis.h"

double radianToDegree(double radians) {
    double degrees = radians * (180.0 / M_PI);
    return degrees;
}

// Funkcja do przeliczania stopni na radiany
double degreeToRadian(double degrees) {
    double radians = degrees * (M_PI / 180.0);
    return radians;
}