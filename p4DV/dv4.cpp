#include <bits/stdc++.h> //Amigos y regalos
using namespace std;
typedef long long int lint;
class Solution
{
public:
    lint f1, f2, x, y;
    void solve()
    {
        cin >> f1 >> f2 >> x >> y;
        cout << binarySearch(f1 + f2, LLONG_MAX);
    }
    lint binarySearch(lint start, lint end)
    {
        lint mid = start + (end - start) / 2;
        if (isValid(mid))
            return (not isValid(mid - 1)) ? mid : binarySearch(start, mid - 1);
        else
            return binarySearch(mid + 1, end);
    }
    bool isValid(lint n)
    {
        lint nv = n / (x * y);
        lint r1 = (n / x) - nv;
        lint r2 = (n / y) - nv;
        lint m1 = max(f1 - r2, 0LL);
        lint m2 = max(f2 - r1, 0LL);
        return (n - r1 - r2 - nv >= m1 + m2);
    }
};
signed main()
{
    (new Solution())->solve();
}