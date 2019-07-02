/*
#include "jarvis.h"


int main(int argc, char const *argv[]) {
    vector<coordinate> points = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
      {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
    vector<coordinate> result;
    result = jarvisAlgorithm(points);
    removePoints(result);
    cout << "Boundary points of convex hull are: "<<endl;
    vector<coordinate>::iterator it;

    for(it = result.begin(); it!=result.end(); it++)
        cout << "(" << it->x << ", " <<it->y <<") " << "\n";

    vector<double> promedio;
    double prom = 0;
    for (int i = 0; i < 60; ++i)
  	{
  		auto start1 = chrono::high_resolution_clock::now();
  		jarvisAlgorithm(points);
  		auto end1 = chrono::high_resolution_clock::now();
  		chrono::duration<double> diff1 = end1 - start1;
  		promedio.push_back(diff1.count());
  		prom += promedio[i];
  	}
    prom /= promedio.size();
    cout<<"Tiempo de ejecución de jarvis March: "<<fixed <<setprecision(10)<<prom<<"s"<<"\n";
  return 0;
}
*/

#include "parallelGraham.h"
#include "randomPointsGenerator.h"
#include "giftWrapping.h"

int main(){

    pointsVector Map = {{0,0},{7,0,},{5,1},{4,1},{5,3},{7,5},{2,2},{3,4},{1,3},{0,5}};
    pointsVector auxMap = {{4,4},{3,3},{3,1},{5,-10},{2,2},{1,2},{0,3},{1,1},{0,0}};
    pointsVector aux =  {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
                         {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4},{0,10}};

    /*
     -77.0184, -12.1344
-77.0718, -12.0973
-76.9892, -12.0694
-77.0411, -12.0793
-76.9745, -12.107
-77.0656, -12.0828
-76.9713, -12.1279
-77.0171, -12.1442
-76.9782, -12.2175
-77.0169, -12.0853
     */
/*
    pointsVector taxi = {{-77.0184, -12.1344},
                         {-77.0718, -12.0973},
                         {-76.9892, -12.0694},
                         {-77.0411, -12.0793},
                         {-76.9745, -12.107},
                         {-77.0656, -12.0828},
                         {-76.9713, -12.1279},
                         {-77.0171, -12.1442},
                         {-76.9782, -121.2175},
                         {-77.0169, -12.0853}};

    pointsVector convexHullLeft = leftGraham(aux);
    pointsVector convexHullRight = rightGraham(aux);

    pointsVector merge = graham(aux);

    for(auto&i:convexHullLeft)
        std::cout<<i<<std::endl;

    std::cout<<std::endl;

    for(auto&i:convexHullRight)
        std::cout<<i<<std::endl;

    std::cout<<std::endl;

    for(auto&i:merge)
        std::cout<<i<<std::endl;

*/
    //std::cout<<getExecutionTime(graham, auxMap);

    pointsVector coordinates = generateCoordinates(-80,-70,-10,0,100);

    for(auto&i:coordinates)
        std::cout<<i<<std::endl;

    std::cout<<"-------------\n\n";

    for(auto&i:graham(coordinates))
        std::cout<<i<<std::endl;

    std::cout<<"-------------\n\n";

    for(auto&i:giftWrapping(coordinates))
        std::cout<<i<<std::endl;

    return 0;
}