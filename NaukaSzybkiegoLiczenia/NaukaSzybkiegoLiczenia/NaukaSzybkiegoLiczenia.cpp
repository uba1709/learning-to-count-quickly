#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <Windows.h>
#include <vector>
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
    cout << "4. Dzielenie (do dopracowania!) \n";
	cout << "5. KONIEC\n";
    cout << "Wybor: ";
    cin >> wybor;
	system("cls");
    if (wybor == 5) { exit(0); };
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
        pokazMenu();
    }
	system("cls");
}

void pobierzUstawienia(int& min, int& max, int& ilosc) {
    cout << "Podaj zakres liczb (min max): \n";
    cin >> min >> max;
    system("cls");
    cout << "Podaj ilosc zadan: ";
    cin >> ilosc;
	system("cls");
}

void wymieszajListe(vector<int>& v) {
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
}

vector<int> utworzListe(int min, int max) {
    vector<int> v;
    for (int i = min; i <= max; i++) {
        v.push_back(i);
    }
    return v;
}

void quiz(Operacja op, vector<int>& v, int iloscPytan){
	int poprawne = 0;
	int bledne = 0;

    for (int i = 0; i < iloscPytan && v.size() >= 2; i++) {
        int a = v[i * 2];
        int b = v[i * 2 + 1];
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
            wynik; round(100);
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
		Sleep(1000);
        system("cls");
    }
}

int main(){
    while (true) {
        int wybor = pokazMenu();
        Operacja op = wybierzOperacje(wybor);
        int min, max, ilosc;
        pobierzUstawienia(min, max, ilosc);
        vector<int> v = utworzListe(min, max);
        wymieszajListe(v);

        int maxPytan = v.size() / 2;
        if (ilosc > maxPytan)
            ilosc = maxPytan;
        quiz(op, v, ilosc);
    }
    return 0;
}