#include "Point.h"
#include <stack>
#include <vector>
#include <cstdlib>
#include <cmath>

typedef Point<double> coordinate;
typedef std::vector<coordinate> pointsVector;

coordinate p0;

void swap(coordinate &p, coordinate &q){
    coordinate tmp = p;
    p=q;
    q = tmp;
}

int getOrientation(coordinate p, coordinate q, coordinate r){
    // Given a Matrix based on points p, q and r, the Orientation is the result of its determinant D.
    // D > 0, is a left turn
    // D == 0, is straight
    // D < 0, is a right turn
    return p.x * (q.y - r.y) +
           q.x * (r.y - p.y) +
           r.x * (p.y - q.y);
}

int getBottomestPointPosition(pointsVector& Map) {
    int p = 0;
    for (int i=0;i<Map.size();++i) {
        if( (Map[i].y<Map[p].y) || (Map[i].y == Map[p].y && Map[i].x < Map[p].y))
            p = i;
    }
    return p;
}

double distanceSquare(coordinate &p1, coordinate &p2){
    return pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2);
}
int compare(const void *vp1, const void *vp2){
    auto p = (coordinate*)vp1;
    auto q = (coordinate *)vp2;

    int orientation = getOrientation(p0, *p, *q);
    if(!orientation)
        return (distanceSquare(p0, *q) >= distanceSquare(p0, *p))? -1 : 1;
    return orientation*-1;
}

void sortPoints(pointsVector &Map){
    int bottomestPosition = getBottomestPointPosition(Map);

    swap(Map[0], Map[bottomestPosition]);

    p0 = Map[0];

    qsort(&Map[1], Map.size()-1, sizeof(coordinate), compare);
}

coordinate underTop(pointsVector& pointVec){
    int n = pointVec.size();
    return pointVec[n-2];
}

bool isALeftTurn(coordinate p, coordinate q, coordinate r){
    return getOrientation(p, q, r) > 0;
}

pointsVector graham(pointsVector Map){
    sortPoints(Map);
    pointsVector grahamHull;
    grahamHull.push_back(Map[0]); grahamHull.push_back(Map[1]);
    for(int i=2;i<Map.size();++i){
        while(!isALeftTurn(underTop(grahamHull), grahamHull[grahamHull.size()-1], Map[i]))
            grahamHull.pop_back();
        grahamHull.push_back(Map[i]);
    }
    grahamHull.push_back(grahamHull[0]);
    return grahamHull;
}