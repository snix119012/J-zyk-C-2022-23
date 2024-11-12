#include <stdio.h>
int main()
{

    int n,tymczasowe, Liczby[100],x;
    printf("Podaj ile liczb chcesz porownac \n");
    scanf("%d", &n);
    printf("Podaj liczby do sortowania \n");
    for (int i = 0; i < n; ++i)
        scanf("%d", &Liczby[i]);
    printf("Jezeli chcesz posortowac rosnaco wcisnij 1 a jezeli malejaco wscisnij 2 \n");
    scanf("%d", &x);
    switch(x)
    {
        case 1:
        {
            for (int i = 0; i < n; ++i)
            {

                for (int j = i + 1; j < n; ++j)
                {

                    if (Liczby[i] > Liczby[j])
                    {

                        tymczasowe =  Liczby[i];
                        Liczby[i] = Liczby[j];
                        Liczby[j] = tymczasowe;

                    }

                }

            }

            printf("Posortowane liczby: ");
            for (int i = 0; i < n; ++i)
                printf(" %d ", Liczby[i]);
            break;
        }
        case 2:
        {
            for (int i = 0; i < n; ++i)
            {

                for (int j = i + 1; j < n; ++j)
                {

                    if (Liczby[i] > Liczby[j])
                    {

                        tymczasowe =  Liczby[i];
                        Liczby[i] = Liczby[j];
                        Liczby[j] = tymczasowe;

                    }

                }

            }

            printf("Posortowane liczby: ");
            for (int i = n - 1; i >= 0; --i)
                printf(" %d ", Liczby[i]);
            break;
        }
    }

}