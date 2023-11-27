#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    char buffer[1000]; // Adjust the buffer size as needed
    char *wordToReplace = argv[3];
    char *replacementWord = argv[4];

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


    // Read the input file line by line
    while (fgets(buffer, sizeof(buffer), plik) != NULL) {
        // Replace the word in the buffer
        char *occurrence = strstr(buffer, wordToReplace);
        while (occurrence != NULL) {
            memcpy(occurrence, replacementWord, strlen(replacementWord));
            occurrence = strstr(occurrence + strlen(replacementWord), wordToReplace);
        }

        // Write the modified line to the output file
        fputs(buffer, nowy_plik);
    }

    // Close the files
    fclose(plik);
    fclose(nowy_plik);

    printf("Zamiana udana.\n");

    return 0;
}