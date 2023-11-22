#include <stdio.h>

// (*)Napisz program, który kopiuje plik tekstowy (pierwszy parametr programu) do drugiego pliku (drugi parametr programu) w ten sposób, że każdy ciąg spacji redukuje do jednej i na końcu pliku podaje liczbę usuniętych spacji. 

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    printf("Plik zrodlowy: %s\n", argv[1]);
    printf("Plik docelowy: %s\n", argv[2]);

    FILE *plik = fopen(argv[1], "r");
    FILE *plik_bez_spacji = fopen(argv[2], "w");

    if (plik == NULL) {
        printf("Unable to open source file.\n");
        return 1;
    }

    if (plik_bez_spacji == NULL) {
        printf("Unable to open destination file.\n");
        fclose(plik);
        return 1;
    }

    int character;
    int prevCharacter = EOF;
    int countSpaces = 0;

    while ((character = fgetc(plik)) != EOF) {
        
        if (character == ' ' && prevCharacter == ' ') {
            countSpaces++;
            continue;
        }

        // Wpisz char do nowego pliku
        fputc(character, plik_bez_spacji);

        // Aktualizuj poprzedni char
        prevCharacter = character;
    }

    printf("Usunieto %d spacji", countSpaces);

    // Close both files
    fclose(plik);
    fclose(plik_bez_spacji);

    return 0;
}
