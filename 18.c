#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10
double stos[MAXSIZE];
int k = 0; //aktualna liczba potrzebna do funkcji push i pop
double pop()
{
    k--;
    return stos[k];
};

void push(double x)
{
    stos[k] = x;
    k++;
}
double siedemnasty(char* funkcja[], int tk, double x)
{
    char oper[MAXSIZE];
    for (int i = 0; i < tk; i++)
    {
        strcpy(oper, funkcja[i]);

        if (isdigit(*oper))
        {
            double z;
            scanf(oper, "%lf", &z);
            push(z);
        }
        else
        {
            if (oper[0] == '-' && oper[1] != '\n')
            {
                char tymczas[MAXSIZE - 1];
                for (int i = 1; i < MAXSIZE; i++)
                {
                    tymczas[i - 1] = oper[i];
                    if (oper[i] == '\n')
                        break;
                }
                if (isdigit(*tymczas))
                {
                    double z;
                    sscanf(tymczas, "%lf", &z);
                    push(z);
                }
            }
            if (strncmp(oper, "^", 2) == 0)
            {
                double x = pop();
                double y = pop();
                push(pow(y, x));
            }
            else if (strncmp(oper, "*", 1) == 0)
            {
                double x = pop();
                double y = pop();
                push(x * y);
            }
            switch (*oper)
            {
                case 'x':
                    push(x);
                    break;

                case '+':
                {
                    double x = pop();
                    double y = pop();
                    push(x + y);
                    break;
                }
                case '-':
                {
                    double x = pop();
                    double y = pop();
                    push(y - x);
                    break;
                }
                case '/':
                {
                    double x = pop();
                    double y = pop();
                    push(y / x);
                    break;
                }
                default:
                    break;
            }

        }
    }
    return pop();
}
int main()
{
    char in[MAXSIZE];  //Deklaracja zmiennej przechowującej wprowadzony ciąg znaków
    char* pch;

    char* funkcja[MAXSIZE]; //Deklaracja tablicy przechowującej tokeny funkcji
    int tk = 0;//licznik tokenow funkcji
    printf("Program wykonuje calkowanie numeryczne metodą prostokątów.\n");
    printf("Użytkownik wprowadza funkcję do zintegrowania,\npoczątek i koniec przedziału calkowania oraz krok calkowania.\n");
    printf("Wpisz funkcje: ");

    fgets(in, MAXSIZE, stdin); //Pobieranie wprowadzonego ciągu znaków
    pch = strtok(in, " "); //Dzielenie ciągu na tokeny
    while (pch != NULL)
    {
        funkcja[tk] = malloc(strlen(pch) + 1);  //Alokacja pamięci dla kolejnego tokena
        strcpy(funkcja[tk], pch);  //Kopiowanie tokena do tablicy
        tk++;
        pch = strtok(NULL, " ");//Pobranie kolejnego tokena
    }

    double x_start, x_end, delta_x, n, integral = 0;

    printf("Wpisz x_start: ");
    scanf("%lf", &x_start);
    printf("Wpisz x_end: ");
    scanf("%lf", &x_end);
    printf("Wpisz delta_x: ");
    scanf("%lf", &delta_x);


    n = (x_end - x_start) / delta_x;


    for (int i = 0; i < n; i++)     //Petla obliczająca calkę
    {
        integral += siedemnasty(funkcja, tk, x_start + (i * delta_x));
    }
    integral += siedemnasty(funkcja, tk, x_start) * 0.5;
    integral += siedemnasty(funkcja, tk, x_end) * 0.5;
    integral *= delta_x;

    printf("Calka to: %.1lf\n", integral);

    for (int i = 0; i < tk; i++) //Zwolnienie pamięci zaalokowanej dla tokenów funkcji
        free(funkcja[i]);

    return 0;
}