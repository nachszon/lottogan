/*lottogan
wersja 3.0
maj 2020

Program do generowania całkowitych liczb pseudolosowych.
Losowanych jest 6 liczb z puli 49 na wzór dużego lotka
Autor ani nie gwarantuje wygranej ani nie ponosi kosztów
ewentualnych strat poniesionych w wyniku używania programu
Jednak w przypadku wygranej w dużego lotka przy użyciu tej maszyny losującej
zwyczajna grzeczność nakazuje podzielić się z autorem programu w stosunku 1:3.
Trzy części dla autora programu, jedna dla gracza :)
*/

/*zmienne i ich przeznaczenie

//pierwsza liczba zakresu losowania
int liczba_start;

//ostatnia liczba zakresu losowania
int liczba_end;

//liczba będąca argumenetem modulo funkcji rand()
int liczba_rand;

//liczba wylosowana
int liczba_out;

//liczba losowanych liczb
int liczba_losowanych_liczb;

//zmienna przechowująca rozmiar tablicy tab_out
int size_tab_out

//tablica tab_out przechowująca wylosowane liczby
int tab_out[size_tab_out]

//index tablicy tab_out
int i_tab_out

//indeks elementu tablicy tab_out
//porównywany z pozostałymi elementami
//w celu wyeliminowania duplikatów
int i_check

//flaga stanu tablicy
//jeżeli większa od 0 to tablica zawiera duplikaty
//początkowa wartość 0;
int status_flag


liczba w funkcji rand()%liczba to liczba losowanych liczb
Ponieważ funkcja rand()%liczba losuje liczby z zakresu 0-(liczba-1)
to ogólny wzór dla wyliczenia liczby liczba_rand, wygląda następująco:

liczba_rand=(liczba_end-liczba_start)+1

postać funkcji rand() dla zakresu od 1 do 49:

rand()%liczba_rand+liczba_start;

jeżeli liczba_out to nasza liczba losowana, wówczas pełna postać losowania wyglądać będzie następująco:

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


    //wykonaj losowanie liczby size_tab_out razy (liczenie po amerykańsku od 0)
    for (liczba_losoliczb=0;liczba_losoliczb<=size_tab_out;liczba_losoliczb++){

    /*oblicz argument dla funkcji rand(), czyli liczbę liczb*/
    liczba_rand=(liczba_out-liczba_end)+1;

    //wylosuj liczbę
    liczba_out=rand()%liczba_rand+liczba_start;

    //każdą z losowanych liczb umieść w tablicy tab_out[]:
    tab_out[liczba_losoliczb]=liczba_out;

    //cout << liczba_out << endl;

    }

    //w tym miejscu wszystkie wyloswane liczby znalzały się w tablicy tab_out[]
    //teraz sprawdzamy obecność duplikatów w tablicy tab_out[]
    //każdy element tablicy tab_out zostanie porównany z wszystkimi pozostałymi o indeksach
    //których wartość jest większa od elementu testowanego
    //elementy o indeksach mniejszcyh zostały przetestowane w poprzednich iteracjach


    for (i_check=0;i_check<=size_tab_out;i_check++){


            for (i_tab_out=i_check+1;i_tab_out<=size_tab_out;i_tab_out++){


                if (tab_out[i_check]==tab_out[i_tab_out]){

                    status_flag+=1;
                }

            }


    }

    //prezentujemy liczby czyli zawartość tablicy tab_out
    for (i_tab_out=0;i_tab_out<=size_tab_out;i_tab_out++){

        cout << tab_out[i_tab_out] << endl;

        }

        cout <<"Status flagi: " << status_flag << endl;


    return 0;
}
