#ifndef VORONOI_H
#define VORONOI_H
#include <vector>
#include <algorithm>
#include "../qt/graph.h"
#include <QGeoCoordinate>
//#include "../convex_hull/src/graham.h"
//based on http://www.personal.kent.edu/~rmuhamma/Compgeometry/MyCG/Voronoi/DivConqVor/divConqVor.htm
//read chapter 14 qt book
//recorded runtime: nlog(n)<-- Asymptotic

//input: 2 convex hulls
pair<QGeoCoordinate, QGeoCoordinate> lowerCommonSupportLine(std::vector<QGeoCoordinate> hull1, std::vector<QGeoCoordinate> hull2)
{
    //step 1:find the vertex in hull1 with the highest x(Rightmost)
    QGeoCoordinate rmost = (*hull1.end());
    //find leftmost in hull2
    QGeoCoordinate lmost = (*hull2.end());
}

std::vector<std::vector<QGeoCoordinate>> mergeVoronoi(std::vector<std::vector<QGeoCoordinate>> vor1, std::vector<std::vector<QGeoCoordinate>> vor2)
{
    ;
}

std::vector<std::vector<QGeoCoordinate>> voronoi(std::vector<QGeoCoordinate> vecPoints, const graph &g)
{
    int size = vecPoints.size();
    vector<vector<QGeoCoordinate>> vor1, vor2, vorMerge;
    vector<QGeoCoordinate> split1, split2;
    //TODO SORT vecpoints so that leftmost point is vecpoints[0]; must homogenize thing VITAL
    for (int i = 0; i < size / 2; i++)
    {
        split1.push_back(vecPoints[i]);
    }
    for (int j = size / 2; j < size; j++)
    {
        split2.push_back(vecPoints[j]);
    }
    vor1 = voronoi(split1, g);
    vor2 = voronoi(split2, g);
    vorMerge = mergeVoronoi(vor1, vor2);
    return vorMerge;
}
#endif
