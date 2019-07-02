cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        auxFunctions.h
        CMakeLists.txt
        convexHullTimer.h
        giftWrapping.h
        grahamScan.h
        main.cpp
        parallelGraham.h
        Point.h
        randomPointsGenerator.h
        simulation.h)

TARGET_LINK_LIBRARIES( src
        pthread
        )