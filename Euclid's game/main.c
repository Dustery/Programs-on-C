#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define number_length 10

int main (void) {

    int a, b, sa, sb;
    //    a, b - игроки
    //    sa - ход игрока А (step)
    //    sb - ход игрока В (step)
    char first1[number_length];
    char second2[number_length];

    //Получаем число жетонов игрокка А и В
    //Вводимый текст = 0. 0 это ERROR

    a = 0, b = 0;
    while (!a || !b) {
        printf ("Enter the number of tokens for player A: ");
        fgets (first1, number_length, stdin);
        a = atoi (first1);
        if (a <= 0) {
            printf ("ERROR! Enter the correct number\n");
            continue;
        }

        printf ("Enter the number of tokens for player B: ");
        fgets (second2, number_length, stdin);
        b = atoi (second2);
        if (b <= 0) {
            printf ("ERROR! Enter the correct number\n");
            continue;
        }
    }

    // Игра
    // Минусование чисел пока = a и b > 0

    sa = 0, sb = 0;
    while (a!= b) {

        if (a < b) {
            printf ("Player A makes a move.\n");
            switch (a) {
                case 1:
                    printf ("Player A takes player's B %d token .\n", a);
                    break;
                default :
                    printf ("Player A takes player's B %d tokens.\n", a);
                    break;
            }
            b -= a; //минусование
            sa ++; // посчет ходов
            printf ("Player A has tokens: %d, player B has tokens: %d.\n\n", a, b);
        }

        if (b < a) {
            printf ("Player B makes a move.\n");
            switch (b) {
                case 1:
                    printf ("Player B takes player A %d token.\n", b);
                    break;
                default :
                    printf ("Player B takes player A %d tokens.\n", b);
                    break;
            }
            a -= b; //минусование
            sb ++; // подсчет ходов
            printf ("Player A has tokens: %d, player B has tokens: %d.\n\n", a, b);
        }

    }
    // результат
    printf ("Players A and B have the same number of tokens: %d\n", a);
    printf ("The number of moves of the player A : %d\n", sa);
    printf ("The number of moves of the player B : %d\n\n", sb);
    printf ("               GAME OVER :)\n");

    return 0;
}
