//
// Created by notpyxl on 7/1/19.
//

#ifndef SRC_PARALLELGRAHAM_H
#define SRC_PARALLELGRAHAM_H

#include <algorithm>
#include <iostream>
#include <pthread.h>
#include "grahamScan.h"


bool isARightTurn(coordinate p, coordinate q, coordinate r){
    return getOrientation(p,q,r)<0;
}

pointsVector leftGraham(pointsVector &Map){
    sortPoints(Map);
    std::reverse(Map.begin()+1, Map.end());
    pointsVector grahamHull;
    grahamHull.push_back(Map[0]); grahamHull.push_back(Map[1]);
    for(int i=2;i<=ceil(Map.size()/2.0);++i){ // < map.size() for entire hull
        while(!isARightTurn(underTop(grahamHull), grahamHull[grahamHull.size()-1], Map[i]))
            grahamHull.pop_back();
        grahamHull.push_back(Map[i]);
    }
    //grahamHull.push_back(grahamHull[0]);
    return grahamHull;
}

pointsVector rightGraham(pointsVector Map){
    sortPoints(Map);
    pointsVector grahamHull;
    grahamHull.push_back(Map[0]); grahamHull.push_back(Map[1]);
    for(int i=2;i<=floor(Map.size()/2.0);++i){ // <Map.size() for entire hull
        while(!isALeftTurn(underTop(grahamHull), grahamHull[grahamHull.size()-1], Map[i]))
            grahamHull.pop_back();
        grahamHull.push_back(Map[i]);
    }
    //grahamHull.push_back(grahamHull[0]);
    return grahamHull;
}

pointsVector parallelGraham(pointsVector &Map){
    pointsVector grahamHull;
    pointsVector leftHull = leftGraham(Map), rightHull = rightGraham(Map);

    grahamHull.push_back(leftHull[0]);

    for(int i=1;i<leftHull.size()-1;++i)
        grahamHull.push_back(leftHull[i]);

    for(int i=rightHull.size()-2;i>0;--i)
        grahamHull.push_back(rightHull[i]);

    grahamHull.push_back(grahamHull[0]);

    return grahamHull;
}

#endif //SRC_PARALLELGRAHAM_H
