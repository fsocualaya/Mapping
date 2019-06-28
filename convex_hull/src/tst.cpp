#include "graham.h"
#include <iostream>

int main(){
    
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}}; 
    
    for(int i = 0 ; i<8;++i)
        std::cout<<points[i].x<<' ' << points[i].y << '\n';

    return 0;
}
