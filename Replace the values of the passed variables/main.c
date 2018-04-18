#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define line 10
#define TRUE 1
#define FALSE 0

int read (char *message);
// funkcja zwraca 1 w przypadku zamiany, 0 jezeli nie ma zamiany
int replace (int *p1, int *p2);

int main()
{
    int number1, number2;
    int *p1 = &number1, *p2 = &number2;
    //number1,2 = number1,2

    system("cls");

    *p1 = read ("Number 1: "); // вписываем числа(личбе)
    *p2 = read ("Number 2: ");

    printf ("\n");
    // Liczba na ktora wskazuje p1 i p2 przed wywolaniem fukcji
    printf ("The number pointed to by p1, before calling the function: %d\n", *p1);
    printf ("The number pointed to by p2, before calling the function: %d\n", *p2);
    printf ("\n");

    // сравненине
    if (replace (p1, p2)) {
        printf ("All numbers which indicate are pair. They were changed.\n"); //Все числа на которое указывают - парные. Они были изменены.
        // Wszystkie wartosci na ktore wskazuja wskazniki sa parzyste i zostaly wymienione
    } else {  // если не парные, то
        printf ("All numbers which indicate are not pair. They can't be changed.\n");
    }
    printf ("\n");
    // Liczba na ktora wskazuje p1 po wywolaniu fukcji Число, на которую указывает p1 после вызова функции
    printf ("The number pointed to by p1 after calling the function : %d\n", *p1);
    printf ("The number pointed to by p1 after calling the function: %d\n", *p2);

    return EXIT_SUCCESS;
}

// funkcja zwraca TRUE w przypadku zamiany, FALSE jezeli nie ma zamiany
int replace (int *p1, int *p2) {
    int test;
// testujemy czy wartosci pod p1 i pod p2 sa podzielne przez 2, jezeli sa podzielne to je zamieniamy
    if (*p1 % 2 == 0 && *p2 % 2 == 0) {
        test = *p1;
        *p1 = *p2;
        *p2 = test;
        return TRUE;
    }
    return FALSE;
}

int read (char *message) {
    int number;
    char text[line];

    printf (message);
    fgets (text, line, stdin);
    number = atoi (text);

    return number;
}
