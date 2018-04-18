#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define line 10

float input (char *);

int main()
{
int text_for_number;
float sum = 0, average = 0, max = 0;
float table[10];

for (text_for_number = 0; text_for_number < 10; text_for_number++) {
table[text_for_number] = input ("Please state the number : ");
}
//
max = table[0];
for (text_for_number = 0; text_for_number < 10; text_for_number++) {
sum = sum + table [text_for_number];
if (table[text_for_number] > max) max = table [text_for_number];
}
average = sum / 10;

printf ("Sum of elements in table are : %.02f\n", sum);
printf ("Average number of elements in table are: %.02f\n", average);
printf ("Maximum value of elements in table are : %.02f\n", max);

return 0;
}


float input (char message[]) {
float number;
char text[line];

printf (message);
fgets (text, line, stdin);
number = atof (text);

return number;
}
