struct Point{
    double x, y;

    Point(){};

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(Point q)
    {
         if(x == q.x && y == q.y)
             return 1;
        return 0;
    }
  //~Point();
};
