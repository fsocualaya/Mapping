#ifndef SRC_GRAHAM_H
#define SRC_GRAHAM_H

#include "Point.h"
#include "auxFunctions.h"

pointsVector graham(pointsVector Map){
    sortPoints(Map);
    pointsVector grahamHull;
    grahamHull.push_back(Map[0]); grahamHull.push_back(Map[1]);
    for(int i=2;i<Map.size();++i){ // <Map.size() for entire hull
        while(!isALeftTurn(underTop(grahamHull), grahamHull[grahamHull.size()-1], Map[i]))
            grahamHull.pop_back();
        grahamHull.push_back(Map[i]);
    }
    grahamHull.push_back(grahamHull[0]);
    return grahamHull;
}

#endif
