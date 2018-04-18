#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "mylib.h"


//vectory przekazywany  w formie wskaznikuw(*) do struktury typu vector
void vectors_addition (vector *result, vector *vector1, vector *vector2)
{
    result->x = vector1->x + vector2->x;
    result->y = vector1->y + vector2->y;
}

void substraction_vectors (vector *result, vector *vector1, vector *vector2)
{
    result->x = vector1->x - vector2->x;
    result->y = vector1->y - vector2->y;
}

void multiplication_vector_number(vector *result, vector *vector1, float number)
{
    result->x = vector1->x * number;
    result->y = vector1->y * number;
}
//zwraca liczbe typu zmienno przecinrowego
float scalar_multiplication_vector (vector *vector1, vector *vector2)
{
    return (vector1->x * vector2->x) + (vector1->y * vector2->y);
}

float calculate_length_vector (vector *vector1)
{
    return sqrt((vector1->x * vector1->x) + (vector1->y * vector1->y));
}
