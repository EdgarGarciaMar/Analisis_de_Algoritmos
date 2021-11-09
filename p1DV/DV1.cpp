#include <iostream> //dv1 suma de subarreglos

using namespace std;

long int i;

long int max(long int num1, long int num2, long int num3) //O(1)
{
    if (num1 >= num2 && num1 >= num3) //O(1)
        return num1;                  //O(1)
    else if (num2 > num3)
        return num2; //O(1)
    else
        return num3; //O(1)
}

long int sumaMaxima(long int A[], long int inicio, long int fin) //O(nlog(n))
{
    long int mitad, izq, der, suma, sumaIzquierda, sumaDerecha, sumaCentral;

    if (inicio == fin) //O(1)
    {
        return A[inicio]; //O(1)
    }
    mitad = (inicio + fin) / 2; //O(1)

    izq = sumaMaxima(A, inicio, mitad);  //O(nlog(n)) debido a la recursion 2T(n/2)+n
    der = sumaMaxima(A, mitad + 1, fin); //O(nlog(n))
    suma = 0;                            //O(1)
    sumaIzquierda = A[mitad];            //O(1)
    for (i = mitad; i >= inicio; i--)
    {
        suma += A[i];             //O(1)
        if (suma > sumaIzquierda) //O(1)
            sumaIzquierda = suma; //O(1)
    }
    suma = 0;                   //O(1)
    sumaDerecha = A[mitad + 1]; //O(1)
    for (i = mitad + 1; i <= fin; i++)
    {
        suma += A[i];           //O(1)
        if (suma > sumaDerecha) //O(1)
            sumaDerecha = suma; //O(1)
    }
    sumaCentral = sumaIzquierda + sumaDerecha; //O(1)

    return max(izq, der, sumaCentral); //O(1)
}

int main() //O(n)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    // TODO: fixme.
    long int n;
    std::cin >> n;          //O(1)
    long int A[n];          //O(1)
    for (i = 0; i < n; i++) //O(n)
    {
        std::cin >> A[i]; //O(1)
    }
    if (n == 1) //O(1)
    {
        std::cout << n + A[0]; //O(1)
    }
    else
    {
        std::cout << sumaMaxima(A, 0, n); //O(1)
    }
    return 0;
}