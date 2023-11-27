#include <stdio.h>


// Zadanie 15
/* Napisz funkcje, która dostaje jako argumenty ścieżkę dostępu do pliku tekstowego oraz znak c i
    zwraca jako wartość liczbę wystąpień znaku c w podanym w argumencie pliku. 
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
            if (znak == argv[2][0])
            {
                count++;
            }
            
        }
        

        printf("W twoim pliku zawiera sie %d znakow '%c'", count, *argv[2]);
        fclose(plik);
        return 0;

    }
    
    return 0;   
}