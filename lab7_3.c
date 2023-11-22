#include <stdio.h>


// Zadanie 3
int main(int argc, char **argv) {

    // int i;
    // printf("Nazwa programu:\t%s\n", argv[0]);
    // printf("Ilosc argumentow programu: \t%d \n", argc);

    // for (int i = 0; i < argc; i++)
    // {
    //     printf("Argumentem nr %d jest %s\n", i, argv[i]);
    // }

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
            // putchar(znak);
            count ++;
        }

        fclose(plik);
        printf("Liczba znakow w pliku: %d", count);
        return 0;

    }
    
    return 0;   
}