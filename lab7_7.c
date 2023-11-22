#include <stdio.h>

// Zadanie 7
/* 
Napisz  program,  który  wyświetla  na  ekranie  liczbę  wystąpień  cyfr,  małych  i  wielkich  liter  w  podanym  pliku  (parametr programu). 
*/
int main(int argc, char **argv) {


    printf("\nNazwa pliku:\n%s\n", argv[1]);
    FILE *plik = fopen(argv[1], "r");


    if (plik == NULL)
    {
        printf("Niestety nie udało się otworzyć pliku. \n");
        return 0;
    }
    else {
        int countBigChars = 0;
        int countSmallChars = 0;
        int countDigits = 0;

        char character;
        while ((character = fgetc(plik)) != EOF)
        {
            if (character >= 'A' && character <= 'Z')
            {
                countBigChars++;
            } else if (character >= 'a' && character <= 'z') {
                countSmallChars++;
            } else if (character >= '0' && character <= '9') {
                countDigits++;
            }
            

        }

        fclose(plik);
        printf(" Liczba malych znakow: %d\n Liczba duzych znakow: %d\n Liczba cyfr: %d\n", countSmallChars, countBigChars, countDigits);
    }
    
    return 0;   
}