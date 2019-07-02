cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        convexHullTimer.h
        grahamScan.h
        main.cpp
        Point.h randomPointsGenerator.h parallelGraham.h giftWrapping.h auxFunctions.h)

TARGET_LINK_LIBRARIES( src
        pthread
        )