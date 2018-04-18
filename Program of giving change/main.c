#include <stdio.h>
#include <math.h>

int main(void)
{
        int amount; // amount - число которое введет пользователь

printf("***********************************************\n");
printf("*  *                                       *  *\n");
printf("*  *  *       EXCHANGE YOUR MONEY!      *  *  *\n");
printf("*  *                                       *  *\n");
printf("***********************************************\n");
    do
    {
        printf("Enter the currency for the exchange: ");
        scanf("%d", &amount);
    }
    while (amount < 0);

    int hundred = 0;
    int fifty = 0;
    int twenty = 0;
    int ten = 0;
    int five = 0;
    int two = 0;
    int one = 0;


    while(amount >= 100)
    {
        amount = amount - 100;
        hundred++;
        continue;
    }

    while(amount >= 50)
    {
        amount = amount - 50;
        fifty++;
        continue;
    }

    while(amount >= 20)
    {
        amount = amount - 20;
        twenty++;
        continue;
    }

    while(amount >= 10)
    {
        amount = amount - 10;
        ten++;
        continue;
    }

    while(amount >= 5)
    {
        amount = amount - 5;
        five++;
        continue;
    }

    while(amount >= 2)
    {
        amount = amount - 2;
        two++;
        continue;
    }

    while(amount >= 1)
    {
        amount = amount - 1;
        one++;
        continue;
    }
    // ВЫВОД
printf ("The result of exchange:\n");
printf("100zl - %d\n", hundred);
printf("50zl - %d\n", fifty);
printf("20zl - %d\n", twenty);
printf("10zl - %d\n", ten);
printf("5zl - %d\n", five);
printf("2zl - %d\n", two);
printf("1zl - %d\n",one);

return 0;
}
