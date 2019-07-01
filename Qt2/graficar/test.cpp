#include "voronoi.h"
int main()
{
    coordinate one(-2, -2);
    coordinate two(0, 0);
    coordinate three(-3, 3);
    coordinate four(-1, 1);
    auto test = intersect(make_pair(one, two), make_pair(three, two));
    test;
}