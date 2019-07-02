#ifndef SRC_CONVEXHULLTIMER_H
#define SRC_CONVEXHULLTIMER_H

#include <ctime>
#include "grahamScan.h"

double getExecutionTime(pointsVector (*convexHullAlgorithm)(pointsVector), pointsVector& Map){

    std::clock_t start = std::clock();
    convexHullAlgorithm(Map);
    double duration = (std::clock()-start)/(double) CLOCKS_PER_SEC;
    return duration;
}

#endif