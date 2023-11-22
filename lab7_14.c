#include <stdio.h>


// Zadanie 14
/*
Napisz  funkcje,  która  dostaje  jako  argument  ścieżkę  dostępu  do  pliku  tekstowego  i  wypisuje  na  standardowym  wyjściu zawartość pliku z pominięciem białych znaków. 
*/
int main(int argc, char **argv) {

    printf("Nazwa pliku:\n %s\n", argv[1]);
    FILE *plik = fopen(argv[1], "r");

    if (plik == NULL)
    {
        printf("Niestety nie udalo sie otworzyc pliku.\n");
        return 1;
    } else {

        int count = 0;

        char znak;
        while ((znak = fgetc(plik)) != EOF)
        {
            if (znak != ' ')
            {
                putchar(znak);
            }
            
        }

        fclose(plik);
        return 0;

    }
    
    return 0;   
}