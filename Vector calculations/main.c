#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "mylib.h"
//<conio.h> - ��� ����� ���������������� ���������, ������� ��������� ����� ������ ����� � ��� � ��� ������, �� ������ � ��� �������� getch();
//getch() is used to get a character from the console but does not echo to the screen.

void menu (void);
float input (char *message);
void take_vector (char *message, vector *take_results);

//argc- ���������� ���������� ������������ � �����-������
//argv- ��������� �� ������� ���������� ����� ������
int main (int argc, char *argv[])
{
    vector result, first, second;
    float number;
    char select = 0;

    int conversion;
    // DOS
    if (argc > 1) {

        //(*argv[1] ������ �������� ����� ������� ��������� ����� �������� ���������
        if (*argv[1] == '(') {
            conversion = 1;
            first.x = atof(&argv[1][conversion]); // ��������� ������ �������� ����� � � ������� 1 (����������� �����)
            while (argv[1][conversion] != ',') conversion++; //����� ���� ���� � 1-� �������
            conversion++;
            first.y = atof(&argv[1][conversion]); //����������� 2-� �������� ����� � Y ������� 1

            // ��� ����� ������ ��������� ������ ����� - case 5
            if (argc == 2) {
                number = calculate_length_vector(&first);
                printf ("The length of the vector is equal to: %.2f\n\n", number);
                return 0;
            }
        }

        if (argc == 4) {
            // ������ �������� - ������ ��� �����
            if (*argv[3] == '(') {
                conversion = 1;
                second.x = atof(&argv[3][conversion]);
                while (argv[3][conversion] != ',') conversion++;
                conversion++;
                second.y = atof(&argv[3][conversion]);
            } else {
                number = atof(&argv[3][0]);
                if (*argv[2] == 'x') {
                    multiplication_vector_number (&result, &first, number);
                    printf ("The result of the multiplication of vectors by number: (%.2f,%.2f)\n\n", result.x, result.y);
                    return 0;
                }
            }

            // ��������
            if (*argv[2] == '+') {
                vectors_addition (&result, &first, &second); // ���������
                printf ("The result of adding of vectors : (%.2f,%.2f)\n\n", result.x, result.y);
                return 0;
            } else if (*argv[2] == '-') {
                substraction_vectors (&result, &first, &second); // �����
                printf ("The result of the subtraction of vectors : (%.2f,%.2f)\n\n", result.x, result.y);
                return 0;
            } else if (*argv[2] == 'x') {
                number = scalar_multiplication_vector (&first, &second); // ��������
                printf ("The result of scalar multiplication of vectors: %.2f\n\n", number);
                return 0;
            }
        }

    } // argc > 1

    menu();

    while (select != '6') {

        // ����� �������� ������ ������ � ����
        // ��� � ���� ���������� �����
        select = getch();
        menu();

        switch (select) {
            // ��������� �������� +
            case '1':
                first.x = input ("Please enter the value of X (vector 1) : ");
                first.y = input ("Please enter the value of Y (vector 1) : ");
                second.x = input ("Please enter the value of X (vector 2) : ");
                second.y = input ("Please enter the value of Y (vector 2) : ");
                vectors_addition (&result, &first, &second); //����� ������� ������������ � ����������
                printf ("The result of adding vectors is : (%.2f,%.2f)\n\n", result.x, result.y);
                printf ("Please, press any key to return to the menu.\n");
                break;

            // ����� �������� -
            case '2':
                first.x = input ("Please enter the value of X (vector 1) : ");
                first.y = input ("Please enter the value of Y (vector 1) : ");
                second.x = input ("Please enter the value of X (vector 1) : ");
                second.y = input ("Please enter the value of Y (vector 1) : ");
                substraction_vectors (&result, &first, &second); //����� ������� ������������ � ����������
                printf ("The result of subtracting vectors : (%.2f,%.2f)\n\n", result.x, result.y);
                printf ("Please, press any key to return to the menu.\n");
                break;

            // ��������� ������� �� ����� *
            case '3':
                first.x = input ("Please enter the value of X (vector 1) : ");
                first.y = input ("Please enter the value of Y (vector 1): ");
                number = input ("Please enter the number by which the vector will be multiplied : ");
                multiplication_vector_number (&result, &first, number);
                printf ("The result of multiplying the vectors by a number: (%.2f,%.2f)\n\n", result.x, result.y);
                printf ("Please, press any key to return to the menu.\n");
                break;

            // ��������� ��������� ��������
            case '4':
                first.x = input ("Please enter the value of X (vector 1) : ");
                first.y = input ("Please enter the value of Y (vector 1) : ");
                second.x = input ("Please enter the value of X (vector 2) : ");
                second.y = input ("Please enter the value of Y (vector 2) : ");
                number = scalar_multiplication_vector (&first, &second);
                printf ("The result of scalar multiplication: %.2f\n\n", number);
                printf ("Please, press any key to return to the menu.\n");
                break;

            // �������� ����� �������
            case '5':
                first.x = input ("Please enter the value of X (vector 1) : ");
                first.y = input ("Please enter the value of Y (vector 1) : ");
                number = calculate_length_vector (&first);
                printf ("The length of the vector is: %.2f\n\n", number);
                printf ("Please, press any key to return to the menu.\n");
                break;

            default:
                break;
        }

    }

    return 0;
}


void menu (void) {
    system("cls");
    printf ("[1] Adding vectors\n");
    printf ("[2] Subtraction of vectors\n");
    printf ("[3] Multiplication of the vector by the number\n");
    printf ("[4] The scalar multiplication of vectors\n");
    printf ("[5] Calculate the length of the vector\n");
    printf ("[6] End\n");
    printf ("Choose the option:\n\n");
}

float input (char message[]) {
    float number;
    char text[line];

    printf (message);
    fgets (text, line, stdin);
    number = atof (text);

    return number;
}
