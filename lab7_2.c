// LAB 7

#include <stdio.h>

/*
Zadanie 2

Napisz  program,  który  zapyta  użytkownika  o  nazwę  pliku,  a  następnie  otworzy  ten  plik  do  odczytu  i  wyświetli  całą  jego zawartość na ekranie. 

*/ 
void zadanie1() {

    // Pobieranie nazwy pliku.
    char nazwaPliku[100];

    printf("Podaj nazwę pliku do odczytu: ");
    scanf("%s", nazwaPliku);

    FILE *plik = fopen(nazwaPliku, "r");

    if (plik == NULL)
    {
        printf("Niestety nie udało się otworzyć pliku. \n");
        return;
    }
    else {
        char znak;
        while ((znak = fgetc(plik)) != EOF)
        {
            putchar(znak);
            
        }

        fclose(plik);
        
    }
    
    return;
}

int main(int argc, char **argv) {

    zadanie1();

    return 0;
}