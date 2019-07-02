//
// Created by notpyxl on 7/2/19.
//

#ifndef SRC_GIFTWRAPPING_H
#define SRC_GIFTWRAPPING_H

#include "auxFunctions.h"

pointsVector giftWrapping(pointsVector Map){
    pointsVector hull;

    int bottomestPosition = getBottomestPointPosition(Map);

    swap(Map[0], Map[bottomestPosition]);
    p0 = Map[0];
    hull.push_back(p0);
    qsort(&Map[1], Map.size()-1, sizeof(coordinate), compare);

    // Map[1] is part of the convex Hull

    do{
        hull.push_back(Map[1]);
        swap(Map[0],Map[1]);
        p0 = Map[0];
        qsort(&Map[1], Map.size()-1, sizeof(coordinate), compare);
    }while(!(p0 == hull[0]));

    return hull;
}

#endif //SRC_GIFTWRAPPING_H
