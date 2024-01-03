#include <iostream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<< "MENU" <<endl<<endl;
    cout<< "Wybierz numer aby wykonac operacje: "<<endl<<endl;
    cout<<"1. Dodaj element tablicy x"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyświetl elementy tablicy x"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu x"<<endl<<endl;
    cout<<"podaj numer: ";
    cin>>x;

    cout<<endl;

    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden większej niż poprzednia)
                if(p != NULL) //jeżeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartość poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuń poprzednią tablicę
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nową wartość do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaźnika p
                n++; //zwiększ ilość elementów tablicy o 1
                break;
            }
        case 2:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden większej niż poprzednia)
                if(p != NULL) //jeżeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartość poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuń poprzednią tablicę
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nową wartość do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaźnika p
                n++; //zwiększ ilość elementów tablicy o 1
                break;
            }
        case 3:
            {
                    for(int i = 0 ; i < n ; i++)
                        {

                        delete[] p[i];
                        }
                    delete[] p;
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                break;
            }
        case 6:
            {
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }

    return 0;
}
