#include <iostream>
using namespace std;

int conteoInversiones(int A[], int p, int r)
{
    int q, inverder, inverizq, invdiv;
    if (p < r)
    {
        q = parteEntera((p + r) / 2);
        inverder = ConteoInversiones(A, p, q);
        inverizq = ConteoInversiones(A, q + 1, r);
        invdiv = ConteoDivididas(A, p, q, r);
        return inverder + inverizq + invdiv;
    }
    else
    {
        return 0;
    }
}

int main()
{

    return 0;
}