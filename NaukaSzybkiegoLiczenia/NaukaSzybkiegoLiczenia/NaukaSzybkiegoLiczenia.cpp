#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <Windows.h>
using namespace std;

enum class Operacja {
    Dodawanie,
    Odejmowanie,
    Mnozenie,
    Dzielenie
};

int pokazMenu(){
	int wybor;
    cout << "=== MENU ===\n";
    cout << "1. Dodawanie\n";
    cout << "2. Odejmowanie\n";
    cout << "3. Mnozenie\n";
    cout << "4. Dzielenie\n";
    cout << "Wybor: ";
    cin >> wybor;
	system("cls");
    return wybor;
}   

Operacja wybierzOperacje(int wybor){
    switch (wybor) {
    case 1: return Operacja::Dodawanie;
    case 2: return Operacja::Odejmowanie;
    case 3: return Operacja::Mnozenie;
    case 4: return Operacja::Dzielenie;
    default:
        cout << "Zly wybor\n";
        exit(0);
    }
	system("cls");
}

void pobierzUstawienia(int& min, int& max, int& ilosc) {
    cout << "Podaj zakres liczb (min max): \n";
    cin >> min >> max;
    cout << "Podaj ilosc zadan: ";
    cin >> ilosc;
	system("cls");
}

void wymieszajListe(list<int>& l) {
    vector<int> v(l.begin(), l.end());

    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);

    l.assign(v.begin(), v.end());
}

list<int> utworzListe(int min, int max) {
    list<int> l;
    for (int i = min; i <= max; i++) {
        l.push_back(i);
    }
    return l;
}

void quiz(Operacja op, list<int>& l, int iloscPytan){
	int poprawne = 0;
	int bledne = 0;

    for (int i = 0; i < iloscPytan && l.size() >= 2; i++) {
        int a = l.front(); l.pop_front();
        int b = l.front(); l.pop_front();
        int wynik;

        switch (op){
        case Operacja::Dodawanie: wynik = a + b;
            break;
        case Operacja::Odejmowanie: wynik = a - b;
            break;
        case Operacja::Mnozenie: wynik = a * b;
            break;
        case Operacja::Dzielenie: if (b == 0) {
            wynik = a / b;
        }
        break;
        default:
            break;
        }
        int odp;
        cout << "Ile to " << a << " " << b << "= ";
        cin >> odp;
        if (odp == wynik) { poprawne++; } else { bledne++;}
		system("cls");
		cout << "=============\n";
        cout << "\nPoprawne: " << poprawne;
        cout << "\nBledne: " << bledne << "\n";
		Sleep(500);
        system("cls");
    }
}

int main(){
	int wybor = pokazMenu();
    Operacja op = wybierzOperacje(wybor);
	int min, max, ilosc;
	pobierzUstawienia(min, max, ilosc);
    list<int> l = utworzListe(min, max);
    wymieszajListe(l);

    int maxPytan = l.size() / 2;
    if (ilosc > maxPytan)
        ilosc = maxPytan;
	quiz(op, l, ilosc);
    return 0;
}