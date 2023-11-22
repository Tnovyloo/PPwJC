#include <stdio.h>

// Zadanie 8
// (*)Napisz program, który zlicza zapisane
// linijki w istniejącym pliku (parametr programu) i zapisuje ich liczbę do innego pliku
// (drugi parametr programu)(*). 
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


        FILE *nowy_plik = fopen(argv[2], "w");
        if (!(nowy_plik == NULL))
        {

            char str[50];
            sprintf(str, "Liczba nowych lini w pliku: %d", count);

            if (fputs(str, nowy_plik) == EOF) {
                printf("Problem z zapisaniem do nowego pliku");
            }

            fclose(nowy_plik);

            return 0;
        } else {
            printf("Nie podano nazwy pliku do ktorego mam zapisać informacje");
            fclose(nowy_plik);
            return 1;
        }

        return 0;

    }
    
    return 0;   
}