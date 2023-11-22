#include <stdio.h>

// 9.Napisz program, który kopiuje plik tekstowy (pierwszy parametr programu)
// do drugiego pliku (drugi parametr programu). 
int main(int argc, char **argv) {


    printf("Nazwa pliku zrodlowego:\n %s\n", argv[1]);
    printf("Nazwa pliku docelowego:\n %s\n", argv[2]);
    FILE *plik = fopen(argv[1], "r");
    FILE *plik2 = fopen(argv[2], "w");

    if (plik == NULL) {
        printf("Nie udalo sie otworzyc pliku zrodlowego.\n");
        return 1;
    }

    if (plik2 == NULL) {
        printf("Nie udalo sie otworzyc pliku docelowego.\n");
        fclose(plik2);
        return 1;
    }

    int character;

    // Kopiowanie plików
    while ((character = fgetc(plik)) != EOF) {
        fputc(character, plik2);
    }

    printf("Kopiowanie powiodlo sie.\n");

    fclose(plik);
    fclose(plik2);

    return 0;
}