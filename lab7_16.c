#include <stdio.h>


// Zadanie 16
/* 
Napisz funkcje, która dostaje jako argumenty ścieżki dostępu do dwóch plików i dopisuje zawartość pierwszego pliku na koniec drugiego pliku. 
*/
int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <Plik źródłowy> <Plik docelowy>\n", argv[0]);
        return 1;
    }

    printf("Plik zrodlowy: %s\n", argv[1]);
    printf("Plik docelowy: %s\n", argv[2]);

    FILE *plik = fopen(argv[1], "rb");
    FILE *nowy_plik = fopen(argv[2], "ab");

    if (plik == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    if (nowy_plik == NULL) {
        printf("Unable to open destination file.\n");
        fclose(plik);
        return 1;
    }

    int character;

    // Dodaję new line do pliku.
    fputc('\n', nowy_plik);
    while ((character = fgetc(plik)) != EOF) {
        
        fputc(character, nowy_plik);
    }


    // Zamknij obydwa pliki
    fclose(plik);
    fclose(nowy_plik);

    return 0;
}