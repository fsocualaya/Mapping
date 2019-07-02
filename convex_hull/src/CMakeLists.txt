cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        convexHullTimer.h
        grahamScan.h
        jarvis.h
        main.cpp
        Point.h Chan.h randomPointsGenerator.h)
