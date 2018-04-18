#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#define dlugosc 32 //definiujemy 32 znaki
#define ilosc_pracownikow 100
#define TRUE 1
#define FALSE 0


typedef struct {
int Id;
char Imie[dlugosc];
char Nazwisko[dlugosc];
int DataUrDzien;
int DataUrMiesiac;
int DataUrRok;
char Stanowisko[dlugosc];
float Pensja;
} dane;//wpis dotyczace jednego pracownika


// prototypy tych funkcji
int dodaj_uzytkownika (dane pracownicy[ilosc_pracownikow]);
int usun_uzytkownika (dane pracownicy[ilosc_pracownikow]);
int edytuj_uzytkownika (dane pracownicy[ilosc_pracownikow]);
int zapisz_uzytkownika (dane pracownicy[ilosc_pracownikow]);
int wczytaj_uzytkownika (dane pracownicy[ilosc_pracownikow]);

#endif // MYLIB_H_INCLUDED
