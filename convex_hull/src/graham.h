#include <vector> 
#include <queue>
#include "Point.h"
#include <cmath>

typedef std::vector<Point> pointsVector;

Point p0;

/* Utility functions to sort the array of Points */

void swap(Point &p1, Point &p2){
    Point tmp = p1;
    p1 = p2;
    p2 = tmp;
}

double distanceSquare(Point &p1, Point &p2){
    return pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2);
}

int orientation(Point p, Point c, Point n){
    int val = (c.y - p.y) * (n.x - c.x) - (c.x - p.x) * (n.y - c.y);
    if(val == 0)
        return 0;
    return (val>0)?1:2;
}

int compare(const void *vp1, const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;
    
    int o = orientation(p0, *p1, *p2);
    if(o == 0)
        return (distanceSquare(p0, *p2) >= distanceSquare(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1;      
}

/* Sort based on its polar coordinates*/ 
void sortPoints(Point points[], int n){
    int ymin= points[0].y, min = 0;
    
    for (int i = 1; i < n; i++){
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    } 

    swap(points[0], points[min]);

    qsort(&points[1], n-1, sizeof(Point), compare);
}

pointsVector graham(pointsVector map){
    pointsVector grahamHull; 

    return grahamHull;
}
