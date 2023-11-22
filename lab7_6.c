#include <stdio.h>

// Zadanie 6
int main(int argc, char **argv) {


    printf("Nazwa argumentu:\n %s\n", argv[1]);
    FILE *plik = fopen(argv[1], "a");

    printf("Znak ktory bedzie powielany w pliku:\n %s\n to %s", argv[1], argv[2]);

    if (plik == NULL)
    {
        printf("Niestety nie udało się otworzyć pliku. \n");
        return 0;
    }
    else {
        
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                
                if (fputc(*argv[2], plik) == EOF)
                {
                    printf("Problem z wpisaniem char.");
                    fclose(plik);
                    return 1;
                }
            }

            if (fputc('\n', plik) == EOF)
            {
                printf("Problem z wpisaniem nowej lini");
                fclose(plik);
                return 1;
            }
        }
        
        fclose(plik);
    }
    
    return 0;   
}