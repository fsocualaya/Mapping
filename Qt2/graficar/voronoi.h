#ifndef VORONOI_H
#define VORONOI_H
#include <vector>
#include <algorithm>
#include "../../qt/graph.h"
#include "../../convex_hull/src/jarvis.h"
#include "../../convex_hull/src/grahamScan.h"
#define upperLim 10
#define lowerLim 0
#define rightLim 10
#define leftLim 0

//#include "../convex_hull/src/graham.h"
//based on http://www.personal.kent.edu/~rmuhamma/Compgeometry/MyCG/Voronoi/DivConqVor/divConqVor.htm
//read chapter 14 qt book
//recorded runtime: nlog(n)<-- Asymptotic, Amortized

//input: 2 convex hulls

pair<coordinate, coordinate> bisect(pair<coordinate, coordinate> myPair)
{
    auto x = (myPair.first.x + myPair.second.x) / 2;
    auto y = (myPair.first.y + myPair.second.y) / 2;
    coordinate init(x, y);
    float pendiente = (myPair.first.y - myPair.second.y) / (myPair.first.x - myPair.second.x);
    float b = init.y - pendiente * init.x;
    float bottomx = (lowerLim - b) / pendiente;
    coordinate end(bottomx, lowerLim);
    return (make_pair(init, end));
}
struct sortbyX
{

    inline bool operator()(const coordinate coordinate1, const coordinate coordinate2)
    {
        return (coordinate1.x < coordinate2.x);
    }
};
pair<coordinate, coordinate> lowerCommonSupportLine(std::vector<coordinate> hull1, std::vector<coordinate> hull2)
{
    //step 1:find the vertex in hull1 with the highest x(Rightmost)
    //there is an O(log n) algorithm for finding the common support by Overmars and Leevwen. But since this sub-problem is not a bottleneck of the total time complexity, following O(n) algorithm is quite enough.
    //mal; chequear que tengo que hacer palos indices
    long index1, index2;
    index1 = 0;
    index2 = 0;
    double max, min;
    max = 0;
    min = MAXFLOAT;
    for (int i = 0; i < hull1.size(); ++i)
    {
        if (hull1[i].x > max)
        {
            max = hull1[i].x;
            index1 = i;
        }
    }
    for (int j = 0; j < hull2.size(); ++j)
    {
        if (hull2[j].x < min)
        {
            min = hull2[j].x;
            index2 = j;
        }
    }
    coordinate rmost = hull1[index1];
    //find leftmost in hull2
    coordinate lmost = hull2[index2];
    while (rmost.y < hull1[index1 - 1].y)
    {
        index1--;

        rmost = hull1[index1];
        if (index1 == 0)
        {
            index1 = hull1.size();
        }
    }
    while (lmost.y < hull2[index2 + 1].y)
    {
        index2++;
        lmost = hull2[index2];
        if (index2 == hull2.size() - 1)
        {
            index2 = -1;
        }
    }
    return (make_pair(rmost, lmost));
}

std::vector<std::vector<coordinate>> mergeVoronoi(std::vector<std::vector<coordinate>> vor1, std::vector<std::vector<coordinate>> vor2)
{
    ;
}

std::vector<std::vector<coordinate>> voronoi(std::vector<coordinate> veccoordinates, const graph &g)
{
    int size = veccoordinates.size();
    vector<vector<coordinate>> vor1, vor2, vorMerge;
    vector<coordinate> split1, split2;
    //TODO SORT veccoordinates so that leftmost coordinate is veccoordinates[0]; must homogenize thing VITAL
    std::sort(veccoordinates.begin(), veccoordinates.end(), sortbyX());
    for (int i = 0; i < size / 2; i++)
    {
        split1.push_back(veccoordinates[i]);
    }
    for (int j = size / 2; j < size; j++)
    {
        split2.push_back(veccoordinates[j]);
    }
    vor1 = voronoi(split1, g);
    vor2 = voronoi(split2, g);
    vorMerge = mergeVoronoi(vor1, vor2);
    return vorMerge;
}

#endif // VORONOI_H
