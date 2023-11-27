#include <iostream>
#include <cstdlib>

// Zadanie 17
/* 
Napisz program, który zapisze do pliku (parametr programu) n linii wczytanych od użytkownika. 
*/
int main(int argc, char **argv) {

    printf("Plik zrodlowy: %s\n", argv[1]);
    printf("Plik docelowy: %s\n", argv[2]);
    printf("Ilosc linii ktore beda skopiowane: %s \n", argv[3]);
    printf("Ilosc argumentow %d\n", argc);


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

    int newLineCounter = 0;
    while ((character = fgetc(plik)) != EOF) {
        if (character == '\n')
        {
            newLineCounter++;
        }
        
        // Używamy pakietu atoi aby przeniesc zmienna char na integer.
        if (newLineCounter == atoi(&argv[3][0]))
        {
            printf("Dodalem %d linijek do pliku %s", newLineCounter, argv[2]);
            return 1;
        } else {
            fputc(character, nowy_plik);
        }
        
    }


    // Zamknij obydwa pliki
    fclose(plik);
    fclose(nowy_plik);

    return 0;
}