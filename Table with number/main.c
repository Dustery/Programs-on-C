#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int table_number[20] = {1,2,3,-4,5,6,7,8,9,-10,11,12,13,14,15,-16,17,18,19,20};
// a ���������� ����������� ����� � �������
// table_number ���������� � ������� ���������� ��� �����
    system ("cls");
    for (a = 0; a < 20; a++)
        if (table_number[a] % 2 == 0)
            printf("Even number %d\n", table_number[a]); // ������
    for (a = 0; a < 20; a++)
        if (table_number[a] > 0 && table_number[a] % 5 == 0)
            printf("Number %d is positive and divisible by 5\n", table_number[a]); // ������� � ���������� �� 5

    return 0;
}
