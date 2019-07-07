#include "voronoi.h"
int main()
{
    vector<coordinate> myvec1, myvec2;
    coordinate myCoord(-1, 0);
    coordinate myCoord2(-2, 1);
    coordinate myCoord3(1, 3);
    myvec1.push_back(myCoord);
    myvec1.push_back(myCoord2);
    myvec1.push_back(myCoord3);
    auto hull1 = graham(myvec1);
    coordinate myCoord4(2, 0);
    coordinate myCoord5(3, -1);
    coordinate myCoord6(4, 2);
    myvec2.push_back(myCoord5);
    myvec2.push_back(myCoord4);
    myvec2.push_back(myCoord6);

    auto hull2 = graham(myvec2);
    auto LCS = lowerCommonSupportLine(hull1, hull2);
}