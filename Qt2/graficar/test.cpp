#include "voronoi.h"
int main()
{
    coordinate one(0, 0);
    coordinate two(0, 4);
    auto a = bisect(make_pair(one, two));
    auto primero = a.first;
    auto segundo = a.second;
}