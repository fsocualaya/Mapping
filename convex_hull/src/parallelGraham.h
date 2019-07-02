//
// Created by notpyxl on 7/1/19.
//

#ifndef SRC_PARALLELGRAHAM_H
#define SRC_PARALLELGRAHAM_H

#include <algorithm>
#include <iostream>
#include <thread>
#include "grahamScan.h"
#include "convexHullTimer.h"

pointsVector leftHull;
pointsVector rightHull;


bool isARightTurn(coordinate p, coordinate q, coordinate r){
    return getOrientation(p,q,r)<0;
}

void* leftGraham(const pointsVector &tmpMap){
    leftHull = {};

    pointsVector Map = tmpMap;

    sortPoints(Map);
    std::reverse(Map.begin()+1, Map.end());

    leftHull.push_back(Map[0]); leftHull.push_back(Map[1]);
    for(int i=2;i<=ceil(Map.size()/2.0);++i){ // < map.size() for entire hull
        while(!isARightTurn(underTop(leftHull), leftHull[leftHull.size()-1], Map[i]))
            leftHull.pop_back();
        leftHull.push_back(Map[i]);
    }
    //grahamHull.push_back(grahamHull[0]);
}

void* rightGraham(const pointsVector& tmpMap){

    rightHull = {};
    pointsVector Map = tmpMap;
    sortPoints(Map);
    rightHull.push_back(Map[0]); rightHull.push_back(Map[1]);
    for(int i=2;i<=floor(Map.size()/2.0);++i){ // <Map.size() for entire hull
        while(!isALeftTurn(underTop(rightHull), rightHull[rightHull.size()-1], Map[i]))
            rightHull.pop_back();
        rightHull.push_back(Map[i]);
    }
    //grahamHull.push_back(grahamHull[0]);
}

pointsVector parallelGraham(const pointsVector &Map){
    pointsVector grahamHull;

    std::thread t0(&leftGraham, std::ref(Map));
    std::thread t1(&rightGraham, std::ref(Map));
    t0.join();
    t1.join();

    grahamHull.push_back(leftHull[0]);

    for(int i=1;i<leftHull.size()-1;++i)
        grahamHull.push_back(leftHull[i]);

    for(int i=rightHull.size()-2;i>0;--i)
        grahamHull.push_back(rightHull[i]);

    grahamHull.push_back(grahamHull[0]);

    return grahamHull;
}

#endif //SRC_PARALLELGRAHAM_H
