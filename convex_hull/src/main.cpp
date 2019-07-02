#include "parallelGraham.h"
#include "randomPointsGenerator.h"
#include "giftWrapping.h"

int main(){

    pointsVector Map = {{0,0},{7,0,},{5,1},{4,1},{5,3},{7,5},{2,2},{3,4},{1,3},{0,5}};
    pointsVector auxMap = {{4,4},{3,3},{3,1},{5,-10},{2,2},{1,2},{0,3},{1,1},{0,0}};
    pointsVector aux =  {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},
                         {3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4},{0,10}};


    pointsVector coordinates = aux;//generateCoordinates(-80,-70,-10,0,100);


    for(auto&i:coordinates)
        std::cout<<i<<std::endl;

    std::cout<<coordinates.size()<<"\n-------------\n\n";


    for(auto&i:parallelGraham(coordinates))
        std::cout<<i<<std::endl;

    std::cout<<parallelGraham(coordinates).size()<<"\n-------------\n\n";

    for(auto&i:graham(coordinates))
        std::cout<<i<<std::endl;

    std::cout<<graham(coordinates).size()<<"\n-------------\n\n";

    for(auto&i:giftWrapping(coordinates))
        std::cout<<i<<std::endl;

    std::cout<<giftWrapping(coordinates).size()<<"\n-------------\n\n";
    return 0;
}