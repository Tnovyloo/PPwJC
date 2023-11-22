#include <stdio.h>

// Zadanie 4
/*
Napisz program, który policzy linie w pliku (parametr programu). 
*/ 
int main(int argc, char **argv) {


    printf("Nazwa argumentu:\n %s\n", argv[1]);
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
            if (znak == '\n')
            {
                count ++;
            }
        }

        fclose(plik);
        printf("Liczba nowych linii w pliku: %d", count);
        return 0;

    }
    
    return 0;   
}