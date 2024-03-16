#include <iostream>
#include <vector>
using namespace std;

vector<char> znaki = { '+','-','*','/' };

class Kalkulator {
    long double wyn;
    long double l1, l2;
    char znak;

public:
    Kalkulator(long double l1 = 0, long double l2 = 1, char znak = '*') : l1(l1), l2(l2), znak(znak) {}

    // Gettery
    long double getWyn() const { return wyn; }
    long double getL1() const { return l1; }
    long double getL2() const { return l2; }
    char getZnak() const { return znak; }

    // Settery
    void setL1(long double l) { l1 = l; }
    void setL2(long double l) {
        if (znak == '/' && l == 0.0) {
            cout << "Nie wolno dzielic przez 0! \nWpisz jeszcze raz: " << endl;
        }
        else {
            l2 = l;
        }
    }
    void setZnak(char z) {
        bool valid = false;
        for (auto i:znaki) {
            if (i == z) {
                valid = true;
                break;
            }
        }
        if (valid) {
            znak = z;
        }
        else {
            cout << "nie ma takiego znaku! \nDostepne opcje: + - * / " << endl;
        }
    }
    void SetWyn() {
        if (znak == '+') {
            wyn = l1 + l2;
        }
        else if (znak == '-') {
            wyn = l1 - l2;
        }
        else if (znak == '*') {
            wyn = l1 * l2;
        }
        else if (znak == '/') {
            wyn = l1 / l2;
        }
    }

    ~Kalkulator() {}
};