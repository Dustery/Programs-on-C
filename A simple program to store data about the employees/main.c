#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "mylib.h"

void wyswietl (dane pracownicy[ilosc_pracownikow]); //prototyp funkcjii
void menu(void);


int main(void)
{
dane pracownicy[ilosc_pracownikow] = {0};
char wybor = 0;

menu();

while (wybor != '6') {
wyswietl(pracownicy);
menu();

wybor = getch();

switch (wybor) {
case '1':
dodaj_uzytkownika (pracownicy);
break;
case '2':
usun_uzytkownika (pracownicy);
break;
case '3':
edytuj_uzytkownika (pracownicy);
break;
case '4':
zapisz_uzytkownika (pracownicy);
break;
case '5':
wczytaj_uzytkownika (pracownicy);
break;
}
}
return 0;

}

void wyswietl (dane pracownicy [ilosc_pracownikow]) {
int i;

system ("cls");

printf("\n                   Pracownicy firmy *** AmTrans sp z.o.o ***\n\n");
//%c to jest pojedynczy znak, %s to jest string czyli ciag znakow,
//%d to jest calkowita liczba, %f liczba z pzrecinkiem
printf ("%c", '|');
printf ("=====");
printf ("|");
printf ("============");
printf ("|");
printf ("==================");
printf ("|");
printf ("============");
printf ("|");
printf ("============");
printf ("|");
printf ("==============");
printf ("|\n");

printf ("|");
printf ("  Id ");
printf ("|");
printf ("  Imie ");
printf ("     |");
printf ("   Nazwisko ");
printf ("      |");
printf ("  Data ur. ");
printf (" |");
printf (" Stanowisko ");
printf ("|");
printf (" Pensja ");
printf ("      |\n");

printf ("|");
printf ("=====");
printf ("|");
printf ("============");
printf ("|");
printf ("==================");
printf ("|");
printf ("============");
printf ("|");
printf ("============");
printf ("|");
printf ("==============");
printf ("|\n");

for (i = 0; i < ilosc_pracownikow; i++) {
if (pracownicy[i].Id != 0) {//jesli id rozni sie od 0 to wyswietlamy wpis{
printf ("|");
printf ("%4d", pracownicy[i].Id);
printf (" | ");
printf ("%-10s", pracownicy[i].Imie);
printf (" | ");
printf ("%-16s", pracownicy[i].Nazwisko);
printf (" | ");
printf ("%02d", pracownicy[i].DataUrDzien);
printf (".");
printf ("%02d", pracownicy[i].DataUrMiesiac);
printf (".");
printf ("%04d", pracownicy[i].DataUrRok);
printf (" | ");
printf ("%-10s", pracownicy[i].Stanowisko);
printf (" | ");
printf ("%5.0f", pracownicy[i].Pensja);
printf ("        | \n");
}
}
printf ("|");
printf ("=====");
printf ("|");
printf ("============");
printf ("|");
printf ("==================");
printf ("|");
printf ("============");
printf ("|");
printf ("============");
printf ("|");
printf ("==============");
printf ("|\n");
}


void menu(void) {
printf ("[1] Dodaj uzytkownika\n");
printf ("[2] Usun uzytkownika\n");
printf ("[3] Edytuj uzytkownika\n");
printf ("[4] Zapisz pracownikow\n");
printf ("[5] Wczytaj pracownikow\n");
printf ("[6] Koniec\n");
printf ("Wybierz opcje:\n\n");
}
