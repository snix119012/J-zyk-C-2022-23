#include <stdio.h>
#include <math.h>
#define max 100
int main()
{
    double ch[max];
    double srednia=0;
    double suma=0;
    double odchylenie=0;
    int f=0;
    printf("Podaj liczby. Aby zakonczyc wcisnij Ctrl-D  \n");
    while (EOF!=scanf("%lf", &ch[f]))
    {
        suma += ch[f];
        if (f==max-1)
        {
            printf("Przekroczenie maksymalnego rozmiaru tablicy.\n");
            break;
        }
        f++;
    }
    srednia = suma/f;
    printf("Srednia to %.1f\n", srednia);
    for (int i = 0; i < f; i++)
    {
        odchylenie += pow(ch[i] - srednia, 2);
    }
    odchylenie = sqrt(odchylenie / f);
    printf("Odchylenie to %f\n", odchylenie);
    return 0;
}