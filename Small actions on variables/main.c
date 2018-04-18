#include <stdio.h>
#include <stdlib.h>

int main()
{
    int variable = 10; // variable переменная
    // p1 и p2 -поинтер
    int *p1 = (int *)&variable, *p2 = (int *)&variable; // приведение типа i к типу указатель на int.
    system ("cls");
    // приписывание адреса
    p1 = (int *)&variable;
    p2 = (int *)&variable;
    *p1 += 2; // Jeżeli wskaźnik pI wskazuje na zmienną i, to *pI może wystąpić
              // wszędzie tam, gdzie może wystąpić i. Zmienna pI jest aliasem,
              // linikiem do i.
    printf ("The value of int is  : %d\n", variable); //Значение пееременной
    printf ("The address of the variable int is  : %d\n", (int)&variable); // адрес переменной (int)
    printf ("the address of pointers : p1 = %d, p2 = %d\n", (int)&p1, (int)&p2); // адрес поинтеров
    printf ("New address of pointers : p1 = %d, p2 = %d\n", (int)p1, (int)p2); // приписаный адрес для поинтеров

    return 0;
}
