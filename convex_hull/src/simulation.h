#include <vector>
#include <fstream>
#include <string>

#include "convexHullTimer.h"
#include "grahamScan.h"
#include "randomPointsGenerator.h"
#include "giftWrapping.h"

#define TIMES 10

using namespace std;

void generateCsv(string name)
{
  fstream csv(name+".csv",ios::out);
  csv << "size,graham,jarvis" << "\n";

  for (size_t i = 10; i < 100000; i*=10) {
    double timeGraham = 0;
    double timeJarvis = 0;
    pointsVector points = generateCoordinates(80,-70,-10,0,i);
    for (size_t j = 0; j < TIMES; j++) {
      timeGraham += getExecutionTime(graham,points);
      timeJarvis += getExecutionTime(giftWrapping,points);
    }
    timeGraham /= TIMES;
    timeJarvis /= TIMES;
    csv << i << ',' << timeGraham << ',' << timeJarvis <<"\n";
  }
}
