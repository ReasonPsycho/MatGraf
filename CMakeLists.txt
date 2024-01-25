cmake_minimum_required(VERSION 3.26)
project(MatGraf_)

set(CMAKE_CXX_STANDARD 23)

find_package(unofficial-pdcurses CONFIG REQUIRED)

add_executable(MatGraf_ main.cpp
        Vector3.h
        Vector3.cpp
        Utilis.cpp
        Matrix4x4.cpp
        Matrix4x4.h
        Quaternion.cpp
        Quaternion.h
        Line.cpp
        Line.h
        Plane.cpp
        Plane.h
        Sphere.cpp
        Sphere.h
        Camera.cpp
        Camera.h
        BoundaryPlane.cpp
        BoundaryPlane.h
        Cube.cpp
        Cube.h
)

target_link_libraries(MatGraf_  PRIVATE unofficial::pdcurses::pdcurses)

