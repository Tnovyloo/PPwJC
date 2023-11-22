#include <stdio.h>
#include <ctype.h>  // isspace funkcja


// Zadanie 5
/*
Napisz program, który policzy słowa w pliku (parametr programu). 
*/
int main(int argc, char **argv) {

    printf("Nazwa argumentu:\n %s\n", argv[1]);
    FILE *plik = fopen(argv[1], "r");

    if (plik == NULL)
    {
        printf("Niestety nie udało się otworzyć pliku. \n");
        return 1;
    }
    else {
        int count = 0;
        int inWord = 0;
        int character;


        while ((character = fgetc(plik)) != EOF)
        {
            // Sprawdzamy czy znak jest spacją
            if (isspace(character))
            {
                inWord = 0;
            } else {
                // Jesli nie jest spacją, i jeśli nie jest w słowie
                if (!inWord)
                {
                    count++;
                    // Jesteśmy w słowie i dlatego zmienna inWord jest równa jeden
                    inWord = 1;
                }
            }
            
        }

        fclose(plik);
        printf("Liczba slow w pliku: %d\n", count);
    }
    
    return 0;   
}