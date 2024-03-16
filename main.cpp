#include <iostream>
#include "plik.h"
using namespace std;

int main() {
    bool t;
    cout << "Kalkulator" << endl;
    long double l1, l2;
    char u;
    char znak;
    do {
        cout << "Wpisz pierwsza liczbe: " << endl;
        Kalkulator kalk;
        cin >> l1;
        while (cin.fail()) {
            cout << "to nie jest liczba! \nWpisz jeszcze raz: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> l1;
        }
        kalk.setL1(l1);

        cout << "Wpisz znak dzialania, Dostepne opcje: + - * /" << endl;
        cin >> znak;
        kalk.setZnak(znak);

        cout << "Wpisz druga liczbe: " << endl;
        cin >> l2;
        while (cin.fail() || (kalk.getZnak()=='/' && l2==0.0)) {
            if ((kalk.getZnak() == '/' && l2 == 0.0)) {
                cout << "Nie wolno dzielic przez 0! \nWpisz jeszcze raz:";
            }
            else {
                cout << "to nie jest liczba! \nWpisz jeszcze raz: " << endl;
            }
            cin.clear();
            cin.ignore(100, '\n');
            cin >> l2;
        }
        kalk.setL2(l2);

        kalk.SetWyn();  // Oblicz wynik po ustawieniu wszystkich wartości
        cout << "wynik: " << kalk.getWyn() << endl << endl;
        cout << endl << "Czy chcesz wykonac inne dzialanie?: [T/N]" << endl;
        cin >> u;
        while (cin.fail() || (u != 'T' && u != 'N')) {
            cout << "Bledna wartosc!\nWpisz odpowiedz jeszcze raz : [T/N] " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> u;
        }
        if (u == 'N') {
            t = false;
        }
        if (u == 'T') {
            t = true;
        }
    } while (t);
}