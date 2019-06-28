#include "jarvis.h"

int main(int argc, char const *argv[]) {
    Point points[] = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
      {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
    int n = 18;
    vector<Point> result;
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
