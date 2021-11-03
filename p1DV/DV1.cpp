#include <iostream>

using namespace std;

short i;

short max(short num1, short num2, short num3)
{
    if (num1 >= num2 && num1 >= num3)
        return num1;
    else if (num2 > num3)
        return num2;
    else
        return num3;
}

short sumaMaxima(short A[], short inicio, short fin)
{
    short mitad, izq, der, suma, sumaIzquierda, sumaDerecha, sumaCentral;

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
    short n;
    std::cin >> n;
    short A[n];
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