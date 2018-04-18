#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

        //U — напряжение, voltage
        //I — сила тока, current
        //R — сопротивление, resistance
void current()
{
    float u, r, i;
    printf("Enter the VOLTAGE U: ");
    scanf("%f", &u);
    printf("Enter the RESISTANCE R: ");
    scanf("%f", &r);
    i = u / r;
    printf("CURRENT (I) is = %.2f\n", i);

}
void voltage()
{
    float u, r, i;
    printf("Enter the CURRENT I: ");
    scanf("%f", &i);
    printf("Enter the RESISTANCE R: ");
    scanf("%f", &r);
    u = i * r;
    printf("VOLTAGE IS U = %.2f\n", u);
}
void resistance()
{

    float u, r, i;
    printf("Enter the VOLTAGE U: ");
    scanf("%f", &u);
    printf("Enter the CURRENT I: ");
    scanf("%f", &i);
    r = u / i;
    printf("RESISTANCE (R) is = %.2f\n", r);

}

int main()
{
    int select = 0;
    do
    {
        printf("***********************************************\n");
        printf("*  *       *                       *       *  *\n");
        printf("*  *  *       OHM'S LAW CALCULATOR      *  *  *\n");
        printf("*  *       *                       *       *  *\n");
        printf("***********************************************\n\n\n");
        printf("Please choose from following calculations:\n\n");
        printf("[1] <== to calculate the CURRENT (I)\n");
        printf("[2] <== to calculate the VOLTAGE (U)\n");
        printf("[3] <== to calculate the RESISTANCE (R)\n");
        printf("[4] <== End\n");

        scanf("%d", &select);
        if (select == 1)
            current(0,0,0);
        if (select == 2)
            voltage(0,0,0);
        if (select == 3)
            resistance(0,0,0);
        if (select == 4)
            return 0;
        if (select != 1 || select != 2 || select != 3 || select != 4 )
            printf("ERROR! Try again :)\n");

    } while (select!=4);

    return 0;
}
