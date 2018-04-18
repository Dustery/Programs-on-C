#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define letters 20

// letters - символы которые ввели.
// - конвертирует
char *converting (char table[]) {

    // Вывод элементов массива
    char *result;
    int i = 0, j = 0;
    // i - и мал и вел литеры
    // j - личник ьаблицы 2

    // Выдепение памяти
    result = malloc (letters*sizeof(char)); // динамическое выделение памяти под символьную строку
    if (result == NULL) return NULL;  // если выделение памяти не выполнилось, завершить программу
    memset (result,0, sizeof(char) * letters); //memset(s,c, n) размещает символ c в первых n позициях строки s и возвращает s. 0 - зерует таблице бо может быть мусор

    // поиск малых букв и копирование в таблицу 2. тестует все элементы таблицы
    for (i = 0; i < letters; i++) if (islower(table[i])) result[j++] = table[i]; //islower - малые буквы//toupper - большие буквы
    // result[j++] - увеличивает таблицу 2

    return result;
}

int main()
{

    char table_1[letters];
    char *table_2;
    system ("cls");

    // считывает буквы введенные и записывает их в табл 1
    printf ("Letters:\n");
    fgets (table_1, letters, stdin);

    // конвертация табл 1 до табл 2 - и только малые буквы
    table_2 = converting (table_1);

    printf ("\nResult:\n%s\n", table_2);

    return 0;
}
