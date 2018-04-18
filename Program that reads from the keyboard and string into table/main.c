#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define letters 20

// letters - ������� ������� �����.
// - ������������
char *converting (char table[]) {

    // ����� ��������� �������
    char *result;
    int i = 0, j = 0;
    // i - � ��� � ��� ������
    // j - ������ ������� 2

    // ��������� ������
    result = malloc (letters*sizeof(char)); // ������������ ��������� ������ ��� ���������� ������
    if (result == NULL) return NULL;  // ���� ��������� ������ �� �����������, ��������� ���������
    memset (result,0, sizeof(char) * letters); //memset(s,c, n) ��������� ������ c � ������ n �������� ������ s � ���������� s. 0 - ������ ������� �� ����� ���� �����

    // ����� ����� ���� � ����������� � ������� 2. ������� ��� �������� �������
    for (i = 0; i < letters; i++) if (islower(table[i])) result[j++] = table[i]; //islower - ����� �����//toupper - ������� �����
    // result[j++] - ����������� ������� 2

    return result;
}

int main()
{

    char table_1[letters];
    char *table_2;
    system ("cls");

    // ��������� ����� ��������� � ���������� �� � ���� 1
    printf ("Letters:\n");
    fgets (table_1, letters, stdin);

    // ����������� ���� 1 �� ���� 2 - � ������ ����� �����
    table_2 = converting (table_1);

    printf ("\nResult:\n%s\n", table_2);

    return 0;
}
