//
// Created by notpyxl on 6/30/19.
//

#ifndef SRC_RANDOMPOINTSGENERATOR_H
#define SRC_RANDOMPOINTSGENERATOR_H

#include "grahamScan.h"

void initRandom(){
    srand(time(nullptr));
}

double randdouble()
{
    return rand()/(double(RAND_MAX)+1);
}

double randdouble(double min, double max)
{
    if (min>max)
        return randdouble()*(min-max)+max;
    else
        return randdouble()*(max-min)+min;
}

pointsVector generateCoordinates(double minLat, double maxLat, double minLon, double maxLon, int n){
    initRandom();
    pointsVector coordinates;
    for(int i=0;i<n;++i){
        coordinate coord(randdouble(minLat,maxLat),randdouble(minLon,maxLon));
        coordinates.push_back(coord);
    }
    return coordinates;
}

#endif //SRC_RANDOMPOINTSGENERATOR_H