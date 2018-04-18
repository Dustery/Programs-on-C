#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#define line 10

//определение структуры типа вектор
typedef struct {
    float x;
    float y;
} vector;
//прототипы функции
void vectors_addition(vector *result, vector *vector1, vector *vector2);
void substraction_vectors (vector *result, vector *vector1, vector *vector2);
void multiplication_vector_number (vector *result, vector *vector1, float number);
float scalar_multiplication_vector (vector *vector1, vector *vector2);
float calculate_length_vector (vector *vector1);

#endif // MYLIB_H_INCLUDED
