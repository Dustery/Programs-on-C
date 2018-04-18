#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>

//a - число которое вводим
//b - число которое ищем
void sine()
{
    float a, b;
    printf("Enter the value: ");
    scanf("%f", &a);
    b = sin(a);
    printf("sin = %.2f\n", b);

}

void cosine()
{
    float a, b;
    printf("Enter the value: ");
    scanf("%f", &a);
    b = cos(a);
    printf("cos = %.2f\n", b);
}

void tangent()
{
    float a, b;
    printf("Enter the value: ");
    scanf("%f", &a);
    b = tan(a);
    printf("tg = %.2f\n", b);

}

void logarithm()
{

    float a, b;
    printf("Enter the value: ");
    scanf("%f", &a);
    b = log(a);
    printf("log = %.2f\n", b);

}

int main(int argc, char *argv[])
{

float value;

if(argc > 1) {
value = atof (argv[2]);

//M_PI - число Пи
if(strcmp(argv[1], "sin") == 0)
printf("Sine of %.2f will be %.2f\n\n", value, sin(value * M_PI/180.0));
else if(strcmp(argv[1], "cos") == 0)
printf("Cosine of %.2f will be %.2f\n\n", value, cos(value * M_PI/180.0));
else if(strcmp(argv[1], "tan") == 0)
printf("Tangent of %.2f will be %.2f\n\n", value, tan(value * M_PI/180.0));
else if(strcmp(argv[1], "log") == 0)
printf("The natural logarithm of %.2f will be %.2f\n\n", value, log(value * M_PI/180.0));

        else {
        printf("ERROR! Try again\n");
        exit (0);
        }
}
    int option = 0;
    do
    {
        printf("\n");
        printf("\n");
        printf("====================================\n");
        printf("    Select the option: \n\n");
        printf("[1] To calculate the sine\n");
        printf("[2] To calculate the cosine\n");
        printf("[3] To calculate the tangent\n");
        printf("[4] To calculate the logarithm\n");
        printf("[5] End\n\n");
        scanf("%d", &option);
        if (option == 1)
            sine();
        if (option == 2)
            cosine();
        if (option == 3)
            tangent();
        if (option == 4)
            logarithm();
        if (option == 5)
            return 0;
        printf("===================================\n");
    } while (option!=5);

    return 0;
}
