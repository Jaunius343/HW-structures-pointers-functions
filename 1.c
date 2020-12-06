#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    float x, y;
} Point;

void print_point (Point p);
Point create_point(double x, double y);
double get_distance(Point a, Point b);

int main()
{
//    Point p1, p2;
//    p1.x = 2.0; p1.y = 3.0;
//    p2.x = 4.0; p2.y = 5.0;

//    p1 = create_point(2.0, 3.0);
//    p2 = create_point(4.0, 5.0);

    printf("%f\n", get_distance(create_point(2.0, 3.0), create_point(4.0, 5.0)));

//    print_point(p1);
    return 0;
}

double get_distance(Point a, Point b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

Point create_point(double x, double y)
{
    Point p;

    p.x = x;
    p.y = y;

    return p;
}

void print_point (Point p)
{
    printf("(%0.1f, %0.1f)", p.x, p.y);
}
