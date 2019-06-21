#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;

class Point {
public:
  double x, y;

  Point(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  bool operator!=(Point q)
  {
    if (x == q.x && y == q.y)
      return 0;
    return 1;
  }

  bool operator==(Point q) {
      if(x == q.x && y == q.y)
         return 1;
      return 0;
   }
  //~Point();
};

int crossProduct(Point p, Point q, Point r)
{
  int x1 = p.x - q.x;
  int x2 = p.x - r.x;
  int y1 = p.y - q.y;
  int y2 = p.y - r.y;

  return y2*x1 - y1*x2;
}

int distance(Point p, Point q, Point r)
{
  int x1 = p.x - q.x;
  int x2 = p.x - r.x;
  int y1 = p.y - q.y;
  int y2 = p.y - r.y;

  int item1 = pow(y1,2) + pow(x1,2);
  int item2 = pow(y2,2) + pow(x2,2);

  if(item1 == item2)
      return 0;
  else if(item1 < item2)
      return -1;
  else
      return 1;
}

vector<Point> jarvisAlgorithm(Point points[], int n)
{

  Point start = points[0];
  vector<Point> outputHull;

  for (size_t i = 0; i < n; i++) {
    if(points[i].x < start.x)
      start = points[i];
  }

  Point current = start;
  outputHull.push_back(start);

  vector<Point> *collinearPoints = new vector<Point>;

  while (true) {
    Point nextPoint = points[0];

    for (size_t i = 0; i < n; i++) {
      if(points[i] == current)
        continue;

      int val = crossProduct(current,nextPoint, points[i]);

        if (val > 0)
        {
            nextPoint = points[i];
            collinearPoints = new vector<Point>;
        }

        else if(val == 0)
        {
            if (distance(current, nextPoint, points[i]) < 0) {
              collinearPoints->push_back(nextPoint);
              nextPoint = points[i];
            }
            else
              collinearPoints->push_back(points[i]);
        }
    }

    vector<Point>::iterator it;

    for(it = collinearPoints->begin(); it != collinearPoints->end(); it++) {
      outputHull.push_back(*it);
    }

    if(nextPoint == start)        //when next point is start it means, the area covered
         break;
    outputHull.push_back(nextPoint);
    current = nextPoint;
  }

  return outputHull;
}

int main(int argc, char const *argv[]) {
   Point points[] = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
      {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
   int n = 18;
   std::vector<Point> result;
   result = jarvisAlgorithm(points, n);
   cout << "Boundary points of convex hull are: "<<endl;
   vector<Point>::iterator it;

   for(it = result.begin(); it!=result.end(); it++)
      cout << "(" << it->x << ", " <<it->y <<") " << "\n";

    vector<double> promedio;
  	double prom = 0;
  	for (int i = 0; i < 60; ++i)
  	{
  		auto start1 = chrono::high_resolution_clock::now();
  		jarvisAlgorithm(points, n);
  		auto end1 = chrono::high_resolution_clock::now();
  		chrono::duration<double> diff1 = end1 - start1;
  		promedio.push_back(diff1.count());
  		prom += promedio[i];
  	}
  	prom /= promedio.size();
  cout<<"Tiempo de ejecución de jarvis March: "<<fixed <<setprecision(10)<<prom<<"s"<<"\n";
  return 0;
}
