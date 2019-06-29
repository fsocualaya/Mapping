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
    //there is an O(log n) algorithm for finding the common support by Overmars and Leevwen. But since this sub-problem is not a bottleneck of the total time complexity, following O(n) algorithm is quite enough.
    //mal; chequear que tengo que hacer palos indices
    long index1, index2;
    index1 = 0;
    index2 = 0;
    double max,min;
    max = 0;
    min = MAXFLOAT;
    for (int i = 0; i < hull1.size(); ++i)
    {
        if (hull1[i].longitude()>max)
        {
            max =hull1[i].longitude();
            index1 = i;
        }
    }
    for (int j = 0; j < hull2.size(); ++j)
    {
        if(hull2[j].longitude() < min)
        {
            min = hull2[j].longitude();
            index2 = j;
        }
    }
    QGeoCoordinate rmost = hull1[index1];
    //find leftmost in hull2
    QGeoCoordinate lmost = hull2[index2];
    while(rmost.latitude()< hull1[index1-1].latitude()){
        index1 --;

        rmost = hull1[index1];
        if (index1 == 0){
            index1 = hull1.size();
        }
    }
    while(lmost.latitude()< hull2[index2+1].latitude()){
        index2++;
        lmost = hull2[index2];
        if (index2 == hull2.size()-1){
            index2 = -1;
        }

    }
    return (make_pair(rmost,lmost));

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

#endif // VORONOI_H
