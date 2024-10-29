#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Deklaracja funkcji
void initmenu();
void decyzjaMenu(int wybor, vector<string>& zadania);
void dodajZadanie(vector<string>& zadania);
void wyswietlZadania(const vector<string>& zadania);
void ukonczZadanie(vector<string>& zadania);
void usunZadanie(vector<string>& zadania);

int main()
{
    vector<string> zadania;
    int wybor;

    do {
        initmenu();
        cin >> wybor;
        decyzjaMenu(wybor, zadania);
    } while (wybor != 5);

    return 0;
}

void initmenu()
{
    cout << "Co chcesz zrobic?" << endl;
    cout << "1. Dodaj zadanie" << endl;
    cout << "2. Wyswietl zadania" << endl;
    cout << "3. Uknocz zadanie" << endl;
    cout << "4. Usun zadanie" << endl;
    cout << "5. Zakoncz" << endl;
    cout << "Wybierz opcje: ";
}

void decyzjaMenu(int wybor, vector<string>& zadania)
{
    switch (wybor) {
        case 1:
            dodajZadanie(zadania);
            break;
        case 2:
            wyswietlZadania(zadania);
            break;
        case 3:
            ukonczZadanie(zadania);
            break;
        case 4:
            usunZadanie(zadania);
            break;
        case 5:
            cout << "Koniec programu." << endl;
            break;
        default:
            cout << "Wybrales zly numer, sprobuj ponownie." << endl;
            break;
    }
}

void dodajZadanie(vector<string>& zadania)
{
    string zadanie;
    cout << "Podaj tresc zadania: ";
    cin.ignore(); // Ignoruje znak nowej linii pozostały w buforze
    getline(cin, zadanie);
    zadania.push_back(zadanie);
    cout << "Dodano zadanie." << endl;
}

void wyswietlZadania(const vector<string>& zadania)
{
    if (zadania.empty()) {
        cout << "Brak zadan do wyswietlenia." << endl;
    } else {
        cout << "Lista zadan:" << endl;
        for (size_t i = 0; i < zadania.size(); ++i) {
            cout << i + 1 << ". " << zadania[i] << endl;
        }
    }
}

void ukonczZadanie(vector<string>& zadania)
{
    int nr;
    cout << "Podaj numer zadania do ukonczenia: ";
    cin >> nr;
    if (nr > 0 && nr <= zadania.size()) {
        zadania[nr - 1] += " (ukonczone)";
        cout << "Zadanie ukonczone." << endl;
    } else {
        cout << "Niepoprawny numer zadania." << endl;
    }
}

void usunZadanie(vector<string>& zadania)
{
    int nr;
    cout << "Podaj numer zadania do usuniecia: ";
    cin >> nr;
    if (nr > 0 && nr <= zadania.size()) {
        zadania.erase(zadania.begin() + nr - 1);
        cout << "Zadanie usuniete." << endl;
    } else {
        cout << "Niepoprawny numer zadania." << endl;
    }
}