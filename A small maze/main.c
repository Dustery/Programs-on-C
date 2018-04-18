#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    int x;
    int y;
} position;
// labyrinth - отображение лабиринта
// table - сам лабиринт и его прорисовка
// position - позиция
// player - игрок
void labyrinth(int table[10][10], position player);
int main()
{
    char keyboard; //клавиатура WASD
    int steps = 0;
    int table[10][10] = { // две квадратные дужки - ибо таблица 2-х мерная
  //x=0  1  2  3  4  5  6  7  8  9
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // y=o
    { 0, 0, 1, 1, 1, 1, 0, 0, 1, 0}, // y=1
    { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, // y=2
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0}, // y=3
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // y=4
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // y=5
    { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // y=6
    { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0}, // y=7
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // y=8
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}  // y=9
    };

    position player;

    // Стартовая позиция игрока
    player.x = 1;
    player.y = 9;

    while (1) {
        labyrinth(table, player);

        if (player.x == 2 && player.y == 0) break; // Конец игры
        keyboard = getch();

        switch (keyboard) {

            //ВВЕРХ
            case 'w':
                if ((player.y > 0) && (table[player.y - 1][player.x] == 1)) {
                    player.y--;
                    steps++;
                }
                break;

            // ВЛЕВО
            case 'a':
                if ((player.x > 0) && (table[player.y][player.x - 1] == 1)) {
                    player.x--;
                    steps++;
                }
                break;

            // ВПРАВО
            case 'd':
                if ((player.x < 9) && (table[player.y][player.x + 1] == 1)) {
                    player.x++;
                    steps++;
                }
                break;

            // ВНИЗ
            case 's':
                if ((player.y < 9) && (table[player.y + 1][player.x] == 1)) {
                    player.y++;
                    steps++;
                }
                break;
                return 0;
        }
    }

    printf ("\n\n GAME OVER :) You did %d steps.\n", steps);
    return 0;
}

void labyrinth(int table[10][10], position player) {
    //
    int a, b;
    system("cls");
    for (a = 0; a < 10; a++) {
        for (b = 0; b < 10; b++) {
                // a = y
                // b = x
            if (b == player.x && a == player.y) printf ("@");
            else if (table[a][b] == 0) printf("#"); // стена
            else printf (" "); // если не стена и не игрок = то проход
        }
        printf("\n");
    }
}
