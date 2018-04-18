#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // unknown_number - загаданое игрой число
    // lucky - загаданое число игроком
    // attempt - попытка
    //
    int unknown_nubmer, lucky, attempt;

    srand(time(NULL));
    int unknown_number = rand() % 100;

printf("***********************************************\n");
printf("*  *                                       *  *\n");
printf("*  *  *        GUESS THE NUMBER!        *  *  *\n");
printf("*  *                                       *  *\n");
printf("***********************************************\n");

attempt = 1;
    do {
        printf("Attempt %d \n",attempt);
        printf("Please enter the number: ");
        scanf("%d", &lucky);
        attempt++;


// Что бы не было чисел больше 100
        if (lucky>100) {
                printf ("ERROR! NUMBER CAN NOT BE MORE THEN 100! TRY AGAIN :) \n\n");
                continue;
        }

// Что бы не было чисел меньше 0
        if (lucky<0) {
            printf ("ERROR! NUMBER CAN NOT BE LESS THEN 0! TRY AGAIN :) \n\n");
            continue;
        }

        if(lucky > unknown_number)
            printf("Too big\n\n");

        if(lucky < unknown_number)
            printf("Too small\n\n");

    } while (lucky != unknown_number);

    printf ("You Win! Number is %d. Attempts were %d.\n", unknown_number, attempt-1);
    getchar();

    return 0;
}
