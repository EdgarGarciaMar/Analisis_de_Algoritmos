#include <bits/stdc++.h> //Amigos y regalos
using namespace std;
typedef long long int lint;
class Solution
{
public:
    lint f1, f2, x, y;
    void solve() //O(log(n))
    {
        cin >> f1 >> f2 >> x >> y;                //O(1)
        cout << binarySearch(f1 + f2, LLONG_MAX); //O(log(n))
    }
    lint binarySearch(lint start, lint end) //O(log(n))
    {
        lint mid = start + (end - start) / 2;
        if (isValid(mid))
            return (not isValid(mid - 1)) ? mid : binarySearch(start, mid - 1);
        else
            return binarySearch(mid + 1, end);
    }
    bool isValid(lint n) //O(1)
    {
        lint nv = n / (x * y);                //O(1)
        lint r1 = (n / x) - nv;               //O(1)
        lint r2 = (n / y) - nv;               //O(1)
        lint m1 = max(f1 - r2, 0LL);          //O(1)
        lint m2 = max(f2 - r1, 0LL);          //O(1)
        return (n - r1 - r2 - nv >= m1 + m2); //O(1)
    }
};
signed main()
{
    (new Solution())->solve();
}