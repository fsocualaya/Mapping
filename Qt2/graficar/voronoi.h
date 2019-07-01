#ifndef VORONOI_H
#define VORONOI_H
#include <vector>
#include <algorithm>
//#include "../../qt/graph.h"
#include "../../convex_hull/src/jarvis.h"
#include "../../convex_hull/src/grahamScan.h"
#define upperLim 10
#define lowerLim 0
#define rightLim 10
#define leftLim 0
typedef pair<coordinate, coordinate> line;

//#include "../convex_hull/src/graham.h"
//based on http://www.personal.kent.edu/~rmuhamma/Compgeometry/MyCG/Voronoi/DivConqVor/divConqVor.htm
//read chapter 14 qt book
//recorded runtime: nlog(n)<-- Asymptotic, Amortized

//input: 2 convex hulls
struct sortbyX
{

    inline bool operator()(const coordinate coordinate1, const coordinate coordinate2)
    {
        return (coordinate1.x < coordinate2.x);
    }
};

inline bool onSegment(coordinate p, coordinate q, coordinate r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
    {
        return true;
    }
    else
    {
        return false;
    }
}
inline bool doesIntersect(line a, line b, coordinate c)
{
    if (onSegment(a.first, a.second, c) && onSegment(b.first, b.second, c))
    {
        return true;
    }
    else
    {
        return false;
    }
}
coordinate intersect(line a, line b)
{
    coordinate A = a.first;
    coordinate B = a.second;
    coordinate C = b.first;
    coordinate D = b.second;

    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1 * (A.x) + b1 * (A.y);
    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2 * (C.x) + b2 * (C.y);

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0)
    {
        coordinate toret(MAXFLOAT, MAXFLOAT);
        return toret;
    }
    else
    {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        coordinate returned(x, y);
        if (doesIntersect(a, b, returned))
        {
            coordinate toret(MAXFLOAT, MAXFLOAT);
            return toret;
        }

        return returned;
    }
}

pair<coordinate, coordinate> bisect(pair<coordinate, coordinate> myPair)
{
    auto x = (myPair.first.x + myPair.second.x) / 2;
    auto y = (myPair.first.y + myPair.second.y) / 2;
    coordinate init(x, y);
    float pendiente = (myPair.first.y - myPair.second.y) / (myPair.first.x - myPair.second.x);
    float b = init.y - pendiente * init.x;
    if (pendiente == 0)
        exit(EXIT_FAILURE);

    float bottomx = (lowerLim - b) / pendiente;
    coordinate end(bottomx, lowerLim);
    return (make_pair(init, end));
}

line lowerCommonSupportLine(std::vector<coordinate> hull1, std::vector<coordinate> hull2)
{
    //step 1:find the vertex in hull1 with the highest x(Rightmost)
    //there is an O(log n) algorithm for finding the common support by Overmars and Leevwen. But since this sub-problem is not a bottleneck of the total time complexity, following O(n) algorithm is quite enough.
    //mal; chequear que tengo que hacer palos indices
    long lcsIndex1, lcsIndex2;
    lcsIndex1 = 0;
    lcsIndex2 = 0;
    double max, min;
    max = 0;
    min = MAXFLOAT;
    for (int i = 0; i < hull1.size(); ++i)
    {
        if (hull1[i].x > max)
        {
            max = hull1[i].x;
            lcsIndex1 = i;
        }
    }
    for (int j = 0; j < hull2.size(); ++j)
    {
        if (hull2[j].x < min)
        {
            min = hull2[j].x;
            lcsIndex2 = j;
        }
    }
    coordinate rmost = hull1[lcsIndex1];
    //find leftmost in hull2
    coordinate lmost = hull2[lcsIndex2];
    while (rmost.y < hull1[lcsIndex1 - 1].y)
    {
        lcsIndex1--;

        rmost = hull1[lcsIndex1];
        if (lcsIndex1 == 0)
        {
            lcsIndex1 = hull1.size();
        }
    }
    while (lmost.y < hull2[lcsIndex2 + 1].y)
    {
        lcsIndex2++;
        lmost = hull2[lcsIndex2];
        if (lcsIndex2 == hull2.size() - 1)
        {
            lcsIndex2 = -1;
        }
    }
    return (make_pair(rmost, lmost));
}

std::vector<line> mergeVoronoi(std::vector<line> vor1, std::vector<coordinate> generadores1, std::vector<line> vor2, std::vector<coordinate> generadores2)
{
    //step 1: Construct convex hulls of a and b
    std::vector<coordinate> generadoresNew;
    generadoresNew.reserve(generadores1.size() + generadores2.size());
    generadoresNew.insert(generadoresNew.end(), generadores1.begin(), generadores1.end());
    generadoresNew.insert(generadoresNew.end(), generadores2.begin(), generadores2.end());
    auto hull1 = graham(generadores1);
    auto hull2 = graham(generadores2);
    line LCS = lowerCommonSupportLine(hull1, hull2);
    coordinate pl = LCS.first;
    coordinate pr = LCS.second;
    line bisec = bisect(LCS);
    //w0 is the downwards INTERSECTION WITH INFINITY
    coordinate wo = bisec.second;
    auto toEraseL = vor1.begin();
    auto toEraseR = vor2.begin();
    for (auto it = vor1.begin(); it != vor1.end(); it++)
    {
    }

    int counter = 0;
}

std::vector<line> voronoi(std::vector<coordinate> veccoordinates)
{
    int size = veccoordinates.size();
    vector<line> vor1, vor2, vorMerge;
    vector<coordinate> generadores1, generadores2;
    //TODO SORT veccoordinates so that leftmost coordinate is veccoordinates[0]; must homogenize thing VITAL

    std::sort(veccoordinates.begin(), veccoordinates.end(), sortbyX());
    for (int i = 0; i < size / 2; i++)
    {
        generadores1.push_back(veccoordinates[i]);
    }
    for (int j = size / 2; j < size; j++)
    {
        generadores2.push_back(veccoordinates[j]);
    }
    vor1 = voronoi(generadores1);
    vor2 = voronoi(generadores2);
    vorMerge = mergeVoronoi(vor1, generadores1, vor2, generadores2);
    return vorMerge;
}

#endif // VORONOI_H
