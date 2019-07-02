#ifndef POINT_H
#define POINT_H
template <typename T>
struct Point
{
    T x, y;

    Point(){};

    Point(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(Point q)
    {
        return x == q.x && y == q.y;
    }

    friend std::ostream &operator<<(std::ostream &os, Point<T> p)
    {
        os << p.x << ' ' << p.y;
        return os;
    }
    ~Point()= default;
};
#endif