#include <stdio.h>
int silnia(int n)
{
    if(n<2)
        return 1;

    return n*silnia(n-1);
}
int main()
{   int n;
    int k;
    int symbol;
    printf("Podaj pierwsza liczbe do dwumianu newtona \n ");
    scanf("%ld",&n);
    printf("Podaj druga liczbe do dwumianu newtona \n ");
    scanf("%ld",&k);
    symbol = (silnia(n))/((silnia(k))*(silnia(n-k)));
    if (n>k)
    {
        printf (" Wynik to %d", symbol);
    }
    else
    {
        printf ("Pierwszy wyraz musi byc wiekszy od drugiego");
    }
    return 0;
}