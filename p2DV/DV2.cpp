#include <bits/stdc++.h> //Cumulo
using namespace std;
struct Point
{
    double x, y;
};
double Distance(Point &P1, Point &P2) //O(1)
{
    return (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y); //O(1)
}
double BruteForce(Point Points[], size_t Size) //O(n^2)
{
    double MinimunDistance = numeric_limits<double>::max(); //O(1)
    for (auto i = 0; i < Size; ++i)                         //O(n^2)
    {
        for (auto j = i + 1; j < Size; ++j) //O(n)
        {
            double CurrentDistance = Distance(Points[i], Points[j]); //O(1)
            if (CurrentDistance < MinimunDistance)                   //O(1)
                MinimunDistance = CurrentDistance;                   //O(1)
        }
    }
    return MinimunDistance; //O(1)
}
double LineClosest(Point Strip[], size_t Size, double d) //O(n log n)
{
    double MinimunDistance = d; //O(1)
    sort(Strip, Strip + Size,
         [](const Point &P1, const Point &P2)
         { return P1.y < P2.y; });
    for (int i = 0; i < Size; ++i) //O(n log n)
    {
        for (int j = i + 1; j < Size; ++j) //O(n)
        {
            if ((Strip[j].y - Strip[i].y) >= MinimunDistance)      //O(1)
                break;                                             //O(1)
            double CurrentDistance = Distance(Strip[i], Strip[j]); //O(1)
            if (CurrentDistance < MinimunDistance)                 //O(1)
                MinimunDistance = CurrentDistance;                 //O(1)
        }
    }
    return MinimunDistance; //O(1)
}
double minDistPoints(Point Points[], size_t n) //O(n)
{
    if (n < 80)                                                                                              //O(1)
        return BruteForce(Points, n);                                                                        //O(1)
    size_t Middle = n / 2;                                                                                   //O(1)
    double MinDistanceSide = min(minDistPoints(Points, Middle), minDistPoints(Points + Middle, n - Middle)); //O(1)
    Point Strip[n];                                                                                          //O(1)
    int SizeOfStrip = 0;                                                                                     //O(1)
    for (int i = 0; i < n; i++)                                                                              //O(n)
    {
        if (abs(Points[i].x - Points[Middle].x) < MinDistanceSide) //O(1)
            Strip[SizeOfStrip++] = Points[i];                      //O(1)
    }
    return min(
        MinDistanceSide,
        LineClosest(Strip, SizeOfStrip, MinDistanceSide)); //O(1)
}
double ClosestPairOfPoints(Point Points[], int n) //O(1)
{

    sort(Points, Points + n,
         [](const Point &P1, const Point &P2)
         { return P1.x < P2.x; });   //O(1)
    return minDistPoints(Points, n); //O(1)
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