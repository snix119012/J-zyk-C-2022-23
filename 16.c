#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define N_MAX 20

int main(int narg, char *Arg[]){

char haslo[N_MAX];
printf("Podaj haslo:\n");
scanf("%s", haslo);
int dlugosc_hasla = strlen(haslo); 
    


    FILE *file1;
    if (NULL==(file1=fopen(Arg[1],"rb"))){ 
        printf("Blad pliku 1");
        return 1;
    }

    FILE *file2;

    char Tymczasowy[L_tmpnam];
    tmpnam(Tymczasowy);
    


    if (NULL==(file2=fopen(Tymczasowy,"wb"))){
         printf("Blad pliku 2");
         return 1;}
    
    char znak;
    
 while((znak = getc(file1)) != EOF)     
    {   int j;
        znak ^= haslo[ j % (dlugosc_hasla/ sizeof(char)) ];
        putc(znak, file2);
        j++;
    } 

    unlink(Arg[1]);
    rename(Tymczasowy,Arg[1]);
    
    fclose(file1);
    fclose(file2);

    return 0;
}