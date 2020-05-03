/*lottogan
wersja 3.0
maj 2020

Program do generowania ca�kowitych liczb pseudolosowych.
Losowanych jest 6 liczb z puli 49 na wz�r du�ego lotka
Autor ani nie gwarantuje wygranej ani nie ponosi koszt�w
ewentualnych strat poniesionych w wyniku u�ywania programu
Jednak w przypadku wygranej w du�ego lotka przy u�yciu teej maszyny losuj�cej
zwyczajna grzeczno�� nakazuje podzieli� si� z autorem programu w stosunku 1:3.
Trzy cz�ci dla autora programu, jedna dla gracza :)
*/

/*zmienne i ich przeznaczenie

//pierwsza liczba zakresu losowania
int liczba_start;

//ostatnia liczba zakresu losowania
int liczba_end;

//liczba b�d�ca argumenetem modulo funkcji rand()
int liczba_rand;

//liczba wylosowana
int liczba_out;

//liczba losowanych liczb
int liczba_losowanych_liczb;

//zmienna przechowuj�ca rozmiar tablicy tab_out
int size_tab_out

//tablica tab_out przechowuj�ca wylosowane liczby
int tab_out[size_tab_out]

//index tablicy tab_out
int i_tab_out

//indeks elementu tablicy tab_out
//por�wnywany z pozosta�ymi elementami
//w celu wyeliminowania duplikat�w
int i_check

//flaga stanu tablicy
//je�eli wi�ksza od 0 to tablica zawiera duplikaty
//pocz�tkowa warto�� 0;
int status_flag


liczba w funkcji rand()%liczba to liczba losowanych liczb
Poniewa� funkcja rand()%liczba losuje liczby z zakresu 0-(liczba-1)
to og�lny wz�r dla wyliczenia liczby liczba_rand, wygl�da nast�puj�co:

liczba_rand=(liczba_end-liczba_start)+1

posta� funkcji rand() dla zakresu od 1 do 49:

rand()%liczba_rand+liczba_start;

je�eli liczba_out to nasza liczba losowana, w�wczas pe�na posta� losowania wygl�da� b�dzie nast�puj�co:

liczba_rand=(liczba_end-liczba_start)+1
liczba_out=rand()%liczba_rand+liczba_start;

*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    //zmienne konfiguracyjna
    //wymagana natychmiastowa inicjalizacja
    int size_tab_out=5;
    int liczba_start=1;
    int liczba_end=49;
    int liczba_losoliczb=6;



    int liczba_rand;
    int liczba_out;
    int tab_out[size_tab_out];
    int i_tab_out;
    int i_check;
    int status_flag;

    /*injicjalizacja generatora liczb pseudolosowych*/
    srand(time(NULL));


    //wykonaj losowanie liczby size_tab_out razy (liczenie po ameryka�sku od 0)
    for (liczba_losoliczb=0;liczba_losoliczb<=size_tab_out;liczba_losoliczb++){

    /*oblicz argument dla funkcji rand(), czyli liczb� liczb*/
    liczba_rand=(liczba_out-liczba_end)+1;

    //wylosuj liczb�
    liczba_out=rand()%liczba_rand+liczba_start;

    //ka�d� z losowanych liczb umie�� w tablicy tab_out[]:
    tab_out[liczba_losoliczb]=liczba_out;

    //cout << liczba_out << endl;

    }

    //w tym miejscu wszystkie wyloswane liczby znalza�y si� w tablicy tab_out[]
    //teraz sprawdzamy obecno�� duplikat�w w tablicy tab_out[]
    //ka�dy element tablicy tab_out zostanie por�wnany z wszystkimi pozosta�ymi o indeksach
    //kt�rych warto�� jest wi�ksza od elementu testowanego
    //elementy o indeksach mniejszcyh zosta�y przetestowane w poprzednich iteracjach


    for (i_check=0;i_check<=size_tab_out;i_check++){


            for (i_tab_out=i_check+1;i_tab_out<=size_tab_out;i_tab_out++){


                if (tab_out[i_check]==tab_out[i_tab_out]){

                    status_flag+=1;
                }

            }


    }

    //prezentujemy liczby czyli zawarto�� tablicy tab_out
    for (i_tab_out=0;i_tab_out<=size_tab_out;i_tab_out++){

        cout << tab_out[i_tab_out] << endl;

        }

        cout <<"Status flagi: " << status_flag << endl;


    return 0;
}
