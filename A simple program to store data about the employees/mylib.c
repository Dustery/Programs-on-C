#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "mylib.h"


// przyjmuje zerowy wpis w bazie danych
int dodaj_uzytkownika (dane pracownicy[ilosc_pracownikow]) {

int i, j;
char tekst[dlugosc];
char liczba[5] = {0};
char imie[dlugosc] = {0};
char nazwisko[dlugosc] = {0};

// wprowadz imie i nazwisko bez newline
system("cls");
printf ("Dodawanie pracownikow\n");
printf ("---------------------\n\n");
printf ("Prosze podac imie : ");
fgets (imie, dlugosc, stdin);
for (j = 0; j < strlen (imie); j++) if (imie[j] == '\n') imie[j] = 0;
if (j == 1) return FALSE;
printf ("Prosze podac nazwisko : ");
fgets (nazwisko, dlugosc, stdin);
for (j = 0; j < strlen (nazwisko); j++) if (nazwisko[j] == '\n') nazwisko[j] = 0;
if (j == 1) return FALSE;

// sprawdz czy wpis juz istnieje
for (i = 0; i < ilosc_pracownikow; i++) {
if ((strcmp(pracownicy[i].Imie, imie) == 0) && (strcmp(pracownicy[i].Nazwisko, nazwisko) == 0)) {
system("cls");
printf ("\nPracownik juz istnieje w bazie danych!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();
return FALSE;
}
}

// znajdz pierwszy wolny wpis, i = pozycja wpisu badz koniec bazy danych
for (i= 0; i < ilosc_pracownikow; i++) if (pracownicy[i].Id == 0) break;

// czy lista jest pełna
if (i == ilosc_pracownikow) {
system("cls");
printf ("\nBaza danych jest pelna!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();
return FALSE;
}

// dodaj nowy wpis
pracownicy[i].Id = i + 1;
strcpy (pracownicy[i].Imie, imie);
strcpy (pracownicy[i].Nazwisko, nazwisko);

printf ("Prosze podac date urodzin w formacie DD.MM.RRRR : ");
fgets (tekst, dlugosc, stdin);
liczba[0] = tekst[0];
liczba[1] = tekst[1];
liczba[2] = 0;
pracownicy[i].DataUrDzien = atoi (liczba);
liczba[0] = tekst[3];
liczba[1] = tekst[4];
liczba[2] = 0;
pracownicy[i].DataUrMiesiac = atoi (liczba);
liczba[0] = tekst[6];
liczba[1] = tekst[7];
liczba[2] = tekst[8];
liczba[3] = tekst[9];
liczba[4] = 0;
pracownicy[i].DataUrRok = atoi (liczba);

printf ("Prosze podac stanowisko : ");
fgets (pracownicy[i].Stanowisko, dlugosc, stdin);
for (j = 0; j < strlen (pracownicy[i].Stanowisko); j++) if (pracownicy[i].Stanowisko[j] == '\n') pracownicy[i].Stanowisko[j] = 0;
printf ("Prosze podac wysokosc pensji : ");
fgets (tekst, dlugosc, stdin);
pracownicy[i].Pensja = atof (tekst);

printf ("\nPracownik dodany do bazy danych!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();

return TRUE;
}

int usun_uzytkownika (dane pracownicy[ilosc_pracownikow]) {

// wprowadz dane bez newline
int i, j;
char imie[dlugosc] = {0};
char nazwisko[dlugosc] = {0};

system("cls");
printf ("Usuwanie pracownikow\n");
printf ("---------------------\n\n");
printf ("Prosze podac imie : ");
fgets (imie, dlugosc, stdin);
for (j = 0; j < strlen (imie); j++) if (imie[j] == '\n') imie[j] = 0;
if (j == 1) return FALSE;
printf ("Prosze podac nazwisko : ");
fgets (nazwisko, dlugosc, stdin);
for (j = 0; j < strlen (nazwisko); j++) if (nazwisko[j] == '\n') nazwisko[j] = 0;
if (j == 1) return FALSE;

// wyszukaj wpis
for (i = 0; i < ilosc_pracownikow; i++) {
if ((strcmp(pracownicy[i].Imie, imie) == 0) && (strcmp(pracownicy[i].Nazwisko, nazwisko) == 0)) break;
}

// czy przeszukalismy wszystkie wpisy
if (i == ilosc_pracownikow) {
system("cls");
printf ("\nPracownik nie istnieje!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();
return FALSE;
}

// zeruj wpis, Id musi byc wyzerowane
memset (&pracownicy[i], 0, sizeof(dane));
printf ("\nPracownik usuniety z bazy danych!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();

return TRUE;
}

int edytuj_uzytkownika (dane pracownicy[ilosc_pracownikow]) {

int i, j;
char tekst[dlugosc];
char liczba[5] = {0};
char imie[dlugosc] = {0};
char nazwisko[dlugosc] = {0};
// wprowadz imie i nazwisko bez newline
system("cls");
printf ("Edytowanie pracownikow\n");
printf ("----------------------\n\n");
printf ("Prosze podac imie : ");
fgets (imie, dlugosc, stdin);
for (j = 0; j < strlen (imie); j++) if (imie[j] == '\n') imie[j] = 0;
if (j == 1) return FALSE;
printf ("Prosze podac nazwisko : ");
fgets (nazwisko, dlugosc, stdin);
for (j = 0; j < strlen (nazwisko); j++) if (nazwisko[j] == '\n') nazwisko[j] = 0;
if (j == 1) return FALSE;

// wyszukaj wpis
for (i = 0; i < ilosc_pracownikow; i++) {
if ((strcmp(pracownicy[i].Imie, imie) == 0) && (strcmp(pracownicy[i].Nazwisko, nazwisko) == 0)) break;
}

// czy przeszukalismy wszystkie wpisy
if (i == ilosc_pracownikow) {
system("cls");
printf ("\nPracownik nie istnieje!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();
return FALSE;
}

// edytuj wpis
system("cls");
printf ("Edytowanie pracownikow - brak danych pomija wpis\n");
printf ("------------------------------------------------\n\n");
printf ("Aktualne imie : %s\n", pracownicy[i].Imie);
printf ("Prosze podac imie : ");
fgets (tekst, dlugosc, stdin);
if (tekst[0] >= 'A' && tekst[0] <= 'z') {
strcpy (pracownicy[i].Imie, tekst);
for (j = 0; j < strlen (pracownicy[i].Imie); j++) if (pracownicy[i].Imie[j] == '\n') pracownicy[i].Imie[j] = 0;
}

printf ("\nAktualne nazwisko : %s\n", pracownicy[i].Nazwisko);
printf ("Prosze podac nazwisko : ");
fgets (tekst, dlugosc, stdin);
if (tekst[0] >= 'A' && tekst[0] <= 'z') {
strcpy (pracownicy[i].Nazwisko, tekst);
for (j = 0; j < strlen (pracownicy[i].Nazwisko); j++) if (pracownicy[i].Nazwisko[j] == '\n') pracownicy[i].Nazwisko[j] = 0;
}

printf ("\nAktualna data urodzin : ");
printf ("%02d", pracownicy[i].DataUrDzien);
printf (".");
printf ("%02d", pracownicy[i].DataUrMiesiac);
printf (".");
printf ("%04d\n", pracownicy[i].DataUrRok);

printf ("Prosze podac date urodzin w formacie DD.MM.RRRR : ");
fgets (tekst, dlugosc, stdin);
liczba[0] = tekst[0];
liczba[1] = tekst[1];
liczba[2] = 0;
if (liczba[0] >= '0' && liczba[0] <= '9') pracownicy[i].DataUrDzien = atoi (liczba);
liczba[0] = tekst[3];
liczba[1] = tekst[4];
liczba[2] = 0;
if (liczba[0] >= '0' && liczba[0] <= '9') pracownicy[i].DataUrMiesiac = atoi (liczba);
liczba[0] = tekst[6];
liczba[1] = tekst[7];
liczba[2] = tekst[8];
liczba[3] = tekst[9];
liczba[4] = 0;
if (liczba[0] >= '0' && liczba[0] <= '9') pracownicy[i].DataUrRok = atoi (liczba);

printf ("\nAktualne stanowisko : %s\n", pracownicy[i].Stanowisko);
printf ("Prosze podac stanowisko : ");
fgets (tekst, dlugosc, stdin);
if (tekst[0] >= 'A' && tekst[0] <= 'z') {
strcpy (pracownicy[i].Stanowisko, tekst);
for (j = 0; j < strlen (pracownicy[i].Stanowisko); j++) if (pracownicy[i].Stanowisko[j] == '\n') pracownicy[i].Stanowisko[j] = 0;
}

printf ("\nAktuala pensja : %.2f\n", pracownicy[i].Pensja);
printf ("Prosze podac wysokosc pensji : ");
fgets (tekst, dlugosc, stdin);
if (tekst[0] >= '0' && tekst[0] <= '9') pracownicy[i].Pensja = atof (tekst);

printf ("\nDane pracownika poprawione!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();

return TRUE;
}

int zapisz_uzytkownika (dane pracownicy[ilosc_pracownikow]) {

FILE *plik;
char tekst[dlugosc];

// otworz plik w trybie write-binary z nadpisywaniem starej tresci
if ((plik = fopen ("records.dat", "wb")) == NULL) {
system("cls");
printf ("Blad otwarcia pliku danych do zapisu!\n");
return FALSE;
}

// ustawienie pozycji w pliku na poczatek
fseek (plik, 0L, SEEK_SET);

// zapisz naglowek
strcpy (tekst, "Baza danych firmy 123456789");
fwrite (tekst, strlen(tekst), 1, plik);

// zapisz baze danych
fwrite (pracownicy, sizeof(dane) * ilosc_pracownikow, 1, plik);

// zamknij plik
fclose (plik);

system("cls");
printf ("\nBaza danych zapisana na dysk do pliku recods.dat!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic domenu.\n");
getch();

return TRUE;
}

int wczytaj_uzytkownika (dane pracownicy[ilosc_pracownikow]) {

FILE *plik;
char tekst[dlugosc];
char tekst2[dlugosc];

// otworz plik w trybie read-binary
if ((plik = fopen ("records.dat", "rb")) == NULL) {
system("cls");
printf ("Blad otwarcia pliku danych do czytania!\n");
return FALSE;
}

// ustawienie pozycji w pliku na poczatek
fseek (plik, 0L, SEEK_SET);

// odczytaj naglowek i porownaj czy jest to nasza baza danych
memset(tekst,0,dlugosc);
memset(tekst2,0,dlugosc);
strcpy (tekst, "Baza danych firmy 123456789");
fread (tekst2, strlen(tekst), 1, plik);
if (strcmp(tekst, tekst2) != 0) {
fclose(plik);
system("cls");
printf ("Blad w pliku records.dat - to nie jest nasza baza danych!\n");
return FALSE;
}

// odczytaj baze danych
fread (pracownicy, sizeof(dane) * ilosc_pracownikow, 1, plik);

// zamknij plik
fclose (plik);

system("cls");
printf ("\nBaza danych wczytana z pliku recods.dat!\n");
printf ("Prosze nacisnac dowolny klawisz aby powrocic do menu.\n");
getch();

return TRUE;
}
