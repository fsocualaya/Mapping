#ifndef JARVIS_H
#define JARVIS_H
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include "Point.h"

typedef Point<double> coordinate;

using namespace std;

void removePoints(vector<coordinate> &result)
{
  auto end = result.end();
  for (auto it = result.begin(); it != end ; it++) {
    end = std::remove(it+1,end,*it);
  }

  result.erase(end,result.end());
}

int crossProduct(coordinate p, coordinate q, coordinate r)
{
  int x1 = p.x - q.x;
  int x2 = p.x - r.x;
  int y1 = p.y - q.y;
  int y2 = p.y - r.y;

  return y2 * x1 - y1 * x2;
}

int distance(coordinate p, coordinate q, coordinate r)
{
  int x1 = p.x - q.x;
  int x2 = p.x - r.x;
  int y1 = p.y - q.y;
  int y2 = p.y - r.y;

  int item1 = pow(y1, 2) + pow(x1, 2);
  int item2 = pow(y2, 2) + pow(x2, 2);

  if (item1 == item2)
    return 0;
  else if (item1 < item2)
    return -1;
  else
    return 1;
}

vector<coordinate> jarvisAlgorithm(vector<coordinate> &points)
{

  coordinate start = points[0];
  vector<coordinate> outputHull;

  for (int i = 0; i < points.size(); i++)
  {
    if (points[i].x < start.x)
      start = points[i];
  }

  coordinate current = start;
  outputHull.push_back(start);

  vector<coordinate> *collinearPoints = new vector<coordinate>;

  while (true)
  {
    coordinate nextPoint = points[0];

    for (size_t i = 0; i < points.size(); i++)
    {
      if (points[i] == current)
        continue;

      int val = crossProduct(current, nextPoint, points[i]);

      if (val < 0)
      {
        nextPoint = points[i];
        collinearPoints = new vector<coordinate>;
      }

      else if (val == 0)
      {
        if (distance(current, nextPoint, points[i]) < 0)
        {
          collinearPoints->push_back(nextPoint);
          nextPoint = points[i];
        }
        else
          collinearPoints->push_back(points[i]);
      }
    }

    vector<coordinate>::iterator it;

    for (it = collinearPoints->begin(); it != collinearPoints->end(); it++)
    {
      outputHull.push_back(*it);
    }

    if (nextPoint == start)
      break;
    outputHull.push_back(nextPoint);
    current = nextPoint;

  }
  return outputHull;
}
#endif
