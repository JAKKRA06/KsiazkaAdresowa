#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
#include <conio.h>

using namespace std;

struct Kontakty {
    int idKontakt;
    string imieKontakt, nazwiskoKontakt, numerTelefonu, email, adres;
};

int dodawanieKontaktu(Kontakty kontakty[], int iloscKontaktow) {
    string imieKontakt, nazwiskoKontakt, numerTelefonu, email, adres;

    system("cls");

    cout << "Podaj imie: ";
    cin >> imieKontakt;
    cout << "Podaj nazwisko: ";
    cin >> nazwiskoKontakt;
    cout << "Podaj nr telefonu: ";
    cin.sync();
    getline(cin, numerTelefonu);
    cout << "Podaj email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, adres);

//zapisanie wczytanych zmiennych do tablicy

    int idKontakt = iloscKontaktow + 1;

    kontakty[iloscKontaktow].idKontakt = idKontakt;
    kontakty[iloscKontaktow].imieKontakt = imieKontakt;
    kontakty[iloscKontaktow].nazwiskoKontakt = nazwiskoKontakt;
    kontakty[iloscKontaktow].numerTelefonu = numerTelefonu;
    kontakty[iloscKontaktow].email = email;
    kontakty[iloscKontaktow].adres = adres;

// otwarcie pliku i zapis

    fstream plik;
    plik.open("Ksiazka adresowa.txt", ios::out | ios::app);
    if (plik.good()) {
        plik << idKontakt << endl;
        plik << imieKontakt << endl;
        plik << nazwiskoKontakt << endl;
        plik << numerTelefonu << endl;
        plik << email << endl;
        plik << adres << endl;

        plik.close();

        cout << "Kontakt zostal utworzony" << endl;
        Sleep(2000);
    } else
        cout << "Nie mozna otworzyc pliku" << endl;
    iloscKontaktow++;

    return iloscKontaktow;
}

int wczytajOsobyZPliku(Kontakty kontakty[]) {
    int iloscKontaktow = 0;
    string idKontakt, imieKontakt, nazwiskoKontakt, numerTelefonu, email, adres;
    fstream plik;
    plik.open("Ksiazka adresowa.txt", ios :: in);

    if (plik.good() == false) {
        cout << "Plik nie istnieje!";
        exit(0);
    }
    string linia;
    int numerLinii = 1;

    while (getline(plik, linia)) {
        switch (numerLinii) {
        case 1:
            kontakty[iloscKontaktow].idKontakt = atoi(linia.c_str());
            break;
        case 2:
            kontakty[iloscKontaktow].imieKontakt = linia;
            break;
        case 3:
            kontakty[iloscKontaktow].nazwiskoKontakt = linia;
            break;
        case 4:
            kontakty[iloscKontaktow].numerTelefonu = linia;
            break;
        case 5:
            kontakty[iloscKontaktow].email = linia;
            break;
        case 6:
            kontakty[iloscKontaktow].adres = linia;
            break;
        }
        if (numerLinii == 6) {
            numerLinii = 0;
            iloscKontaktow++;
        }
        numerLinii++;
    }
    plik.close();

    return iloscKontaktow;
}

void wyszukiwaniePoImieniu (Kontakty kontakty[], int iloscKontaktow) {
    system("cls");
    string imie;
    char wybor;
    int iloscOsob = 0;

    cout << "Wyszukiwanie kontaktow" << endl;
    cout << "Podaj imie: ";
    cin >> imie;

    for(int i = 0; i < iloscKontaktow; i++) {
        if (kontakty[i].imieKontakt == imie) {
            cout << kontakty[i].idKontakt << endl;
            cout << kontakty[i].imieKontakt << endl;
            cout << kontakty[i].nazwiskoKontakt << endl;
            cout << kontakty[i].numerTelefonu << endl;
            cout << kontakty[i].email << endl;
            cout << kontakty[i].adres << endl;
            iloscOsob++;
        }
    }
    cout << endl;

    if (iloscOsob == 0) {
        cout << "Kontakt o imieniu " << imie << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    wybor = getch();
}

void wyszukiwaniePoNazwisku(Kontakty kontakty[], int iloscKontaktow) {
    system("cls");
    string nazwisko;
    char wybor;
    int iloscOsob = 0;

    cout << "Wyszukiwanie kontaktow" << endl;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    for (int i = 0; i < iloscKontaktow; i++) {
        if (kontakty[i].nazwiskoKontakt == nazwisko) {
            cout  << kontakty[i].idKontakt << endl;
            cout  << kontakty[i].imieKontakt << endl;
            cout  << kontakty[i].nazwiskoKontakt << endl;
            cout  << kontakty[i].numerTelefonu << endl;
            cout  << kontakty[i].email << endl;
            cout  << kontakty[i].adres << endl;
            iloscOsob++;
        }
    }
    cout << endl;

    if (iloscOsob == 0) {
        cout << "Kontakt o nazwisku " << nazwisko << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    wybor = getch();
}

void wyswietlListeKontaktow(Kontakty kontakty[], int iloscKontaktow) {
    system("cls");
    char wybor;
    cout << "Spis kontaktow w ksiazce adesowej:" << endl;

    iloscKontaktow = wczytajOsobyZPliku(kontakty);

    for (int i = 0; i < iloscKontaktow; i++) {
        cout << kontakty[i].idKontakt << endl;
        cout << kontakty[i].imieKontakt << endl;
        cout << kontakty[i].nazwiskoKontakt << endl;
        cout << kontakty[i].numerTelefonu << endl;
        cout << kontakty[i].email << endl;
        cout << kontakty[i].adres << endl;
        cout << "-------------------------" << endl;
    }
    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    wybor = getch();
}

int main() {
    Kontakty kontakty[1000];
    int iloscKontaktow = 0;
    int wybor, wybor1;

    iloscKontaktow = wczytajOsobyZPliku(kontakty);

    while (true) {
        system("cls");
        cout << "1. Dodaj nowy kontakt" << endl;
        cout << "2. Wyszukiwanie" << endl;
        cout << "3. Wyswietl kontakty" << endl;
        cout << "9. Koniec programu" << endl;
        cin >> wybor;

        switch (wybor) {
        case 1: {
            iloscKontaktow = dodawanieKontaktu(kontakty, iloscKontaktow);
            break;
        }
        case 2: {
            system("cls");
            cout << "1. Wyszukiwanie kontaktow po imieniu" << endl;
            cout << "2. Wyszukiwanie kontaktow po nazwisku" << endl;
            cin >> wybor1;

            switch(wybor1) {
            case 1:
                wyszukiwaniePoImieniu(kontakty, iloscKontaktow);
                break;
            case 2:
                wyszukiwaniePoNazwisku(kontakty, iloscKontaktow);
                break;
            }
            break;
        }
        case 3:
            wyswietlListeKontaktow(kontakty, iloscKontaktow);
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "Nie ma takie opcji" << endl;
            break;
        }
    }
    return 0;
}
