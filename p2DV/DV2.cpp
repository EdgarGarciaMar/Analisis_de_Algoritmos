#include <bits/stdc++.h> //Cumulo
using namespace std;
struct Point
{
    double x, y;
};
double Distance(Point &P1, Point &P2)
{
    return (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);
}
double BruteForce(Point Points[], size_t Size)
{
    double MinimunDistance = numeric_limits<double>::max();
    for (auto i = 0; i < Size; ++i)
    {
        for (auto j = i + 1; j < Size; ++j)
        {
            double CurrentDistance = Distance(Points[i], Points[j]);
            if (CurrentDistance < MinimunDistance)
                MinimunDistance = CurrentDistance;
        }
    }
    return MinimunDistance;
}
double LineClosest(Point Strip[], size_t Size, double d)
{
    double MinimunDistance = d;
    sort(Strip, Strip + Size,
         [](const Point &P1, const Point &P2)
         { return P1.y < P2.y; });
    for (int i = 0; i < Size; ++i)
    {
        for (int j = i + 1; j < Size; ++j)
        {
            if ((Strip[j].y - Strip[i].y) >= MinimunDistance)
                break;
            double CurrentDistance = Distance(Strip[i], Strip[j]);
            if (CurrentDistance < MinimunDistance)
                MinimunDistance = CurrentDistance;
        }
    }
    return MinimunDistance;
}
double minDistPoints(Point Points[], size_t n)
{
    if (n < 80)
        return BruteForce(Points, n);
    size_t Middle = n / 2;
    double MinDistanceSide = min(minDistPoints(Points, Middle), minDistPoints(Points + Middle, n - Middle));
    Point Strip[n];
    int SizeOfStrip = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(Points[i].x - Points[Middle].x) < MinDistanceSide)
            Strip[SizeOfStrip++] = Points[i];
    }
    return min(
        MinDistanceSide,
        LineClosest(Strip, SizeOfStrip, MinDistanceSide));
}
double ClosestPairOfPoints(Point Points[], int n)
{

    sort(Points, Points + n,
         [](const Point &P1, const Point &P2)
         { return P1.x < P2.x; });
    return minDistPoints(Points, n);
}
int main()
{
    int n;
    std::cin >> n;
    Point Points[n];
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%lf %lf", &Points[i].x, &Points[i].y))
        {
        };
    }
    printf("%.3lf\n", sqrt(ClosestPairOfPoints(Points, n)));
    return 0;
}