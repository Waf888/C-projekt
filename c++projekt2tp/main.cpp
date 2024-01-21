#include <iostream>
#include <fstream>

using namespace std;

int Menu() {
    int x;
    cout << endl;
    cout << "1. Dodaj element tablicy" << endl;
    cout << "2. Wstaw element tablicy" << endl;
    cout << "3. Usun element tablicy" << endl;
    cout << "4. Wyświetl elementy tablicy" << endl;
    cout << "5. Zapisz do pliku" << endl;
    cout << "6. Wczytaj z pliku" << endl;
    cout << "7. Wyjscie z programu" << endl;
    cin >> x;
    cout << endl;
    return x;
}

int main() {
    int m;
    int *p = nullptr;
    int n = 0;

    while (true) {
        m = Menu();

        switch (m) {
            case 7: {
                delete[] p;
                return 0;
            }
            case 1: {
                int *tmp = new int[n + 1];
                if (p != nullptr) {
                    for (int i = 0; i < n; i++) {
                        tmp[i] = p[i];
                    }
                    delete[] p;
                }
                cout << "Podaj wartosc elementu tablicy: ";
                cin >> tmp[n];
                p = tmp;
                n++;
                break;
            }
            case 2: {
                int index;
                if (n == 0) {
                    cout << "Tablica jest pusta. Nie mozna wstawic elementu." << endl;
                    break;
                }
                cout << "Podaj indeks, na ktory chcesz wstawic element: ";
                cin >> index;

                if (index < 0 || index > n) {
                    cout << "Nieprawidlowy indeks." << endl;
                } else {
                    int *tmp = new int[n + 1];
                    for (int i = 0; i < index; i++) {
                        tmp[i] = p[i];
                    }
                    cout << "Podaj wartosc elementu tablicy: ";
                    cin >> tmp[index];
                    for (int i = index + 1; i <= n; i++) {
                        tmp[i] = p[i - 1];
                    }
                    delete[] p;
                    p = tmp;
                    n++;
                }
                break;
            }
            case 3: {
                int index;
                if (n == 0) {
                    cout << "Tablica jest pusta. Nie ma elementow do usuniecia." << endl;
                    break;
                }
                cout << "Podaj indeks elementu, ktory chcesz usunac: ";
                cin >> index;

                if (index < 0 || index >= n) {
                    cout << "Nieprawidlowy indeks." << endl;
                } else {
                    int *tmp = new int[n - 1];
                    for (int i = 0, j = 0; i < n; i++) {
                        if (i != index) {
                            tmp[j++] = p[i];
                        }
                    }
                    delete[] p;
                    p = tmp;
                    n--;
                }
                break;
            }
            case 4: {
                cout << "Zawartosc tablicy:" << endl;
                for (int i = 0; i < n; i++) {
                    cout << p[i] << ", ";
                }
                cout << endl;
                break;
            }
            case 5: {
                cout << "Podaj sciezke dostepu do pliku: ";
                string sciezka_pliku;
                cin >> sciezka_pliku;
                ofstream fout(sciezka_pliku, ios::trunc);
                if (!fout.is_open()) {
                    cout << "Nie mozna otworzyc pliku." << endl;
                    break;
                }
                fout << n << endl;
                for (int i = 0; i < n; i++) {
                    fout << p[i] << " ";
                }
                cout << "Pomyslne zapisano tablice do pliku." << endl;
                fout.close();
                break;
            }
            case 6: {
                cout << "Podaj sciezke dostepu do pliku, do ktorego chcesz zapisac tablice: " << endl;
                string sciezka_pliku;
                cin >> sciezka_pliku;
                ifstream fin(sciezka_pliku);
                if (!fin.is_open()) {
                    cout << "Nie mozna otworzyc pliku." << endl;
                    break;
                }
                int rozmiar;
                fin >> rozmiar;
                delete[] p;
                p = new int[rozmiar];
                for (int i = 0; i < rozmiar; i++) {
                    fin >> p[i];
                }
                n = rozmiar;
                cout << "Tablica zostala wczytana z pliku." << endl;
                fin.close();
                break;
            }
            default: {
                cout << "Nieprawidlowa opcja" << endl;
            }
        }
    }

    return 0;
}
//vsvsvsv
