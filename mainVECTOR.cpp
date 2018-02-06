#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <sstream>
#include <string>

using namespace std;

struct Kontakty {
    int idKontakt;
    string imieKontakt, nazwiskoKontakt,numerTelefonu, email, adres;
};

void dodawanieKontaktu(vector<Kontakty> &kontakty) {

    Kontakty kontakt;

    system("cls");
    if (kontakty.empty() == true) {
        kontakt.idKontakt = 1;
    } else {
        kontakt.idKontakt = kontakty.back().idKontakt + 1;
    }
    cout << "Podaj imie: ";
    cin >> kontakt.imieKontakt;
    cout << "Podaj nazwisko: ";
    cin >> kontakt.nazwiskoKontakt;
    cout << "Podaj nr telefonu: ";
    cin.sync();
    getline(cin, kontakt.numerTelefonu);
    cout << "Podaj email: ";
    cin >> kontakt.email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, kontakt.adres);

    kontakty.push_back(kontakt);

// otwarcie pliku i zapis

    fstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    if (plik.good()) {
        plik << kontakt.idKontakt << "|" << kontakt.imieKontakt << "|" << kontakt.nazwiskoKontakt << "|" << kontakt.numerTelefonu << "|" << kontakt.email << "|" << kontakt.adres << "|" << endl;

        plik.close();

        cout << "Kontakt zostal utworzony" << endl;
        Sleep(2000);
    } else
        cout << "Nie mozna otworzyc pliku" << endl;
}

vector<Kontakty> rozdzielanieStringow(vector<Kontakty> &kontakty, string wczytanaLinia, char znak) {

    Kontakty kontakt;

    int numerPojedynczejDanej = 1;
    stringstream ss(wczytanaLinia);
    string pojedynczaDana;

    while (getline(ss, pojedynczaDana, znak)) {

        switch(numerPojedynczejDanej) {
        case 1:
            kontakt.idKontakt = atoi(pojedynczaDana.c_str());
            break;
        case 2:
            kontakt.imieKontakt = pojedynczaDana;
            break;
        case 3:
            kontakt.nazwiskoKontakt = pojedynczaDana;
            break;
        case 4:
            kontakt.numerTelefonu = pojedynczaDana;
            break;
        case 5:
            kontakt.email = pojedynczaDana;
            break;
        case 6:
            kontakt.adres = pojedynczaDana;
            break;
        }
        numerPojedynczejDanej++;
    }

    kontakty.push_back(kontakt);
    return kontakty;
}

void wczytajOsobyZPliku(vector<Kontakty> &kontakty) {

    string wczytanaLinia;
    fstream plik;

    plik.open("Ksiazka_Adresowa.txt", ios::in);

    if (plik.good() == false) {
        cout << "Plik nie istnieje!";
        exit(0);
    }

    while (getline(plik, wczytanaLinia)) {
        kontakty = rozdzielanieStringow(kontakty, wczytanaLinia, '|');
    }
    plik.close();
}

void wyszukiwaniePoImieniu(vector<Kontakty> &kontakty) {

    system("cls");
    string imie;
    char wybor;
    int iloscOsob = 0;

    cout << "Wyszukiwanie kontaktow" << endl;
    cout << "Podaj imie: ";
    cin >> imie;

    vector<Kontakty>::iterator itr;

    for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

        if (itr -> imieKontakt == imie) {

            cout << "Id:                 " << itr -> idKontakt << endl;
            cout << "Imie:               " << itr -> imieKontakt << endl;
            cout << "Nazwisko:           " << itr -> nazwiskoKontakt << endl;
            cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
            cout << "Nr Email:           " << itr -> email << endl;
            cout << "Adres:              " << itr -> adres << endl;
            cout << "-------------------------" << endl;

            iloscOsob++;
        }
    }

    if (iloscOsob == 0) {
        cout << "Kontakt o imieniu " << imie << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    wybor = getch();
}

void wyszukiwaniePoNazwisku(vector<Kontakty> &kontakty) {

    system("cls");
    char wybor;
    string nazwisko;
    int iloscOsob = 0;

    cout << "Wyszukiwanie kontaktow" << endl;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;

    vector<Kontakty>::iterator itr;

    for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

        if (itr -> nazwiskoKontakt == nazwisko) {

            cout << "Id:                 " << itr -> idKontakt << endl;
            cout << "Imie:               " << itr -> imieKontakt << endl;
            cout << "Nazwisko:           " << itr -> nazwiskoKontakt << endl;
            cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
            cout << "Nr Email:           " << itr -> email << endl;
            cout << "Adres:              " << itr -> adres << endl;
            cout << "-------------------------" << endl;

            iloscOsob++;
        }
    }

    if (iloscOsob == 0) {
        cout << "Kontakt o nazwisku " << nazwisko << " nie wystepuje w ksiazce adresowej" << endl;
    }
    cout << endl;

    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
    wybor = getch();
}

void wyswietlListeKontaktow(vector<Kontakty> &kontakty) {

    system("cls");
    char wybor;
    vector<Kontakty>::iterator itr;

    if(kontakty.empty() == true) {

        cout << "Brak wpisow w ksiazce adresowej" << endl;
        cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
        wybor = getch();
    }

    else {

        cout << "Spis kontaktow w ksiazce adesowej:" << endl;

        for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

            cout << "Id:                 " << itr -> idKontakt << endl;
            cout << "Imie:               " << itr -> imieKontakt << endl;
            cout << "Nazwisko:           " << itr -> nazwiskoKontakt << endl;
            cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
            cout << "Nr Email:           " << itr -> email << endl;
            cout << "Adres:              " << itr -> adres << endl;
            cout << "-------------------------" << endl;
        }
        cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
        wybor = getch();
    }
}

void zapiszPlik(vector<Kontakty> &kontakty) {

    ofstream plik;
    plik.open("Ksiazka_Adresowa.txt", ios::out);

    for (int i = 0; i < kontakty.size(); i++) {

        plik << kontakty[i].idKontakt << "|" << kontakty[i].imieKontakt << "|" << kontakty[i].nazwiskoKontakt << "|" << kontakty[i].numerTelefonu << "|" << kontakty[i].email << "|" << kontakty[i].adres << "|" << endl;
    }
    plik.close();
}

void usunKontakt(vector<Kontakty> &kontakty) {

    system("cls");
    Kontakty kontakt;
    char wybor, znak;
    bool czyIstniejeAdresat = false;

    int numerKontaktuDoUsuniecia;

    vector<Kontakty>::iterator itr;

    if (!kontakty.empty()) {

        cout << "Spis kontaktow w ksiazce adesowej:" << endl;

        for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

            cout << "Id:                 " << itr -> idKontakt << endl;
            cout << "Imie:               " << itr -> imieKontakt << endl;
            cout << "Nazwisko:           " << itr -> nazwiskoKontakt << endl;
            cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
            cout << "Nr Email:           " << itr -> email << endl;
            cout << "Adres:              " << itr -> adres << endl;
            cout << "-------------------------" << endl;
        }

        cout << "Podaj numer adresata ktorego chcesz usunac: ";
        cin >> numerKontaktuDoUsuniecia;

        if (cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl;
            cin.clear();
            cin.sync();
        } else {
            for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

                if (itr -> idKontakt == numerKontaktuDoUsuniecia) {
                    czyIstniejeAdresat = true;

                    cout << endl << "Potwierdz naciskajac klawisz 't': ";
                    cin >> znak;
                    if (znak == 't') {
                        itr = kontakty.erase(itr);
                        cout << endl << "Wskazany kontakt zostal USUNIETY" << endl << endl;
                        zapiszPlik(kontakty);
                        break;
                    } else {
                        cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                        break;
                    }
                    cout << endl;
                    cout << "Jesli chcesz powrocic do menu glownego nacisnij dowolny klawisz" << endl;
                    wybor = getch();
                }
            }
            if (czyIstniejeAdresat == false) {
                cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            }
        }
    }

    else {
        cout << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    system("pause");
}

void edycjaKontaktu(vector<Kontakty> &kontakty) {

    system("cls");
    Kontakty kontakt;
    char wybor, wybor1;
    bool czyIstniejeAdresat = false;
    int wyborDanych;
    int numerKontaktuDoEdycji;
    vector<Kontakty>::iterator itr;

    if (!kontakty.empty()) {

        cout << "Spis kontaktow w ksiazce adesowej:" << endl;

        for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

            cout << itr -> idKontakt << endl;
            cout << itr -> imieKontakt << endl;
            cout << itr -> nazwiskoKontakt << endl;
            cout << itr -> numerTelefonu << endl;
            cout << itr -> email << endl;
            cout << itr -> adres << endl;
            cout << "-------------------------" << endl;
        }

        cout << "Podaj numer adresata ktorego chcesz edytowac: ";
        cin >> numerKontaktuDoEdycji;

        if (cin.fail()) {
            cout << endl << "Wprowadzono niepoprawne dane. Powrot do menu glownego" << endl << endl;
            cin.clear();
            cin.sync();
        } else {
            for (itr = kontakty.begin(); itr != kontakty.end(); itr++) {

                if (itr -> idKontakt == numerKontaktuDoEdycji) {
                    czyIstniejeAdresat = true;
                    system("cls");
                    cout << "-----Panel edycji kontaktu-----" << endl;

                    cout << endl;
                    cout << "Id:                 " << itr -> idKontakt << endl;
                    cout << "Imie:               " << itr -> imieKontakt << endl;
                    cout << "Nazwisko:           " << itr -> nazwiskoKontakt << endl;
                    cout << "Numer Telefonu:     " << itr -> numerTelefonu << endl;
                    cout << "Nr Email:           " << itr -> email << endl;
                    cout << "Adres:              " << itr -> adres << endl;

                    cout << endl;
                    cout << "-----Wybierz dostepne opcje-----" << endl;
                    cout << "1. Zmiana imienia" << endl;
                    cout << "2. Zmiana nazwiska" << endl;
                    cout << "3. Zmiana numeru telefonu" << endl;
                    cout << "4. Zmiana adresu email" << endl;
                    cout << "5. Zmiana adresu" << endl;
                    cout << "6. Powrot" << endl;
                    cout << endl << "Wybierz 1-6: ";
                    cin >> wyborDanych;

                    switch(wyborDanych) {
                    case 1:
                        system("cls");
                        cout << "Podaj nowe imie: ";
                        cin >> itr -> imieKontakt;
                        zapiszPlik(kontakty);
                        cout << "Zapisano pomyslnie zmiany";
                        break;
                    case 2:
                        system("cls");
                        cout << "Podaj nowe nazwisko: ";
                        cin >> itr -> nazwiskoKontakt;
                        zapiszPlik(kontakty);
                        cout << "Zapisano pomyslnie zmiany";
                        break;
                    case 3:
                        system("cls");
                        cout << "Podaj nowy numer telefonu: ";
                        cin.sync();
                        getline(cin, itr -> numerTelefonu);
                        zapiszPlik(kontakty);
                        cout << "Zapisano pomyslnie zmiany";
                        break;
                    case 4:
                        system("cls");
                        cout << "Podaj nowy adres email: ";
                        cin >> itr -> email;
                        zapiszPlik(kontakty);
                        cout << "Zapisano pomyslnie zmiany";
                        break;
                    case 5:
                        system("cls");
                        cout << "Podaj n owy adres: ";
                        cin.sync();
                        getline(cin, itr -> adres);
                        zapiszPlik(kontakty);
                        cout << "Zapisano pomyslnie zmiany";
                        break;
                    case 6:
                        break;
                    }
                    cout << endl;
                    if (czyIstniejeAdresat == false) {
                        cout << endl << "Nie ma takiego adresata w ksiazce adresowej." << endl << endl;
                    }
                }
            }
        }
    } else {
        cout << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void koniecProgramu() {

    cout << endl << "Koniec programu." << endl;
    exit(0);
}

int main() {

    vector<Kontakty> kontakty;
    int wybor, wybor1;

    if (kontakty.empty() == true) {
        fstream plik;
        plik.open("Ksiazka_Adresowa.txt", ios::out | ios::app);
    }

    wczytajOsobyZPliku(kontakty);

    while (true) {
        system("cls");
        cout << "1. Dodaj nowy kontakt" << endl;
        cout << "2. Wyszukiwanie" << endl;
        cout << "3. Wyswietl kontakty" << endl;
        cout << "4. Usun kontakt" << endl;
        cout << "5. Edycja kontaktu" << endl;
        cout << "9. Koniec programu" << endl;
        cin >> wybor;

        switch (wybor) {
        case 1: {
            dodawanieKontaktu(kontakty);
            break;
        }
        case 2: {
            system("cls");
            cout << "1. Wyszukiwanie kontaktow po imieniu" << endl;
            cout << "2. Wyszukiwanie kontaktow po nazwisku" << endl;
            cin >> wybor1;

            switch(wybor1) {
            case 1:
                wyszukiwaniePoImieniu(kontakty);
                break;
            case 2:
                wyszukiwaniePoNazwisku(kontakty);
                break;
            }
            break;
        }
        case 3:
            wyswietlListeKontaktow(kontakty);
            break;
        case 4:
            usunKontakt(kontakty);
            break;
        case 5:
            edycjaKontaktu(kontakty);
            break;
        case 9:
            koniecProgramu();
        default:
            cout << "Nie ma takie opcji" << endl;
            break;
        }
    }
    return 0;
}
