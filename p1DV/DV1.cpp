#include <iostream> //dv1 suma de subarreglos

using namespace std;

long int i;

long int max(long int num1, long int num2, long int num3)
{
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 > num3)
        return num2;
    else
        return num3;
}

long int sumaMaxima(long int A[], long int inicio, long int fin)
{
    long int mitad, izq, der, suma, sumaIzquierda, sumaDerecha, sumaCentral;

    if (inicio == fin)
    {
        return A[inicio];
    }
    mitad = (inicio + fin) / 2;

    izq = sumaMaxima(A, inicio, mitad);
    der = sumaMaxima(A, mitad + 1, fin);
    suma = 0;
    sumaIzquierda = A[mitad];
    for (i = mitad; i >= inicio; i--)
    {
        suma += A[i];
        if (suma > sumaIzquierda)
            sumaIzquierda = suma;
    }
    suma = 0;
    sumaDerecha = A[mitad + 1];
    for (i = mitad + 1; i <= fin; i++)
    {
        suma += A[i];
        if (suma > sumaDerecha)
            sumaDerecha = suma;
    }
    sumaCentral = sumaIzquierda + sumaDerecha;

    return max(izq, der, sumaCentral);
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    // TODO: fixme.
    long int n;
    std::cin >> n;
    long int A[n];
    for (i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    if (n == 1)
    {
        std::cout << n + A[0];
    }
    else
    {
        std::cout << sumaMaxima(A, 0, n);
    }
    return 0;
}