#include "geometry.h"

#include <cmath>

// długość odcinka
double distance(point A, point B)
{
    auto x = A.x - B.x;
    auto y = A.y - B.y;
    return sqrt(x*x + y*y);
}

static point wektor(point A, point B)
{
    point W;
    W.x = B.x - A.x;
    W.y = B.y - A.y;
    return W;
}

static double il_wekt(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

static double il_wekt(point A, point B, point C)
{
    auto AB = wektor(A, B);
    auto AC = wektor(A, C);
    return il_wekt(AB, AC);
}

// czy punkty tworzą trójkąt
bool is_triangle(point A, point B, point C)
{
    return(il_wekt(A, B, C) != 0.0);
}

// pole trójkąta
double area_triangle(point A, point B, point C)
{
    return(fabs(il_wekt(A, B, C)) * 0.5);
}

// pole wielokąta wypukłego o n-kątach
double area_polygon(point P[], int n)
{
    double s = 0.0;
    for(int i = 1; i < n - 1; i++)
    {
        s += il_wekt(P[0], P[i], P[i + 1]);
    }
    return fabs(s * 0.5);
}
