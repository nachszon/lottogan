/*lottogan
wersja 10
maj 2020
Krzysztof Nachszon Lipa-Izdebski

Og�lnie
Program do generowania ca�kowitych liczb pseudolosowych.
Losowanych jest 6 liczb z puli 49 na wz�r du�ego lotka
Autor ani nie gwarantuje wygranej ani nie ponosi koszt�w
ewentualnych strat poniesionych w wyniku u�ywania programu.
Jednak w przypadku wygranej w du�ego lotka przy u�yciu tej maszyny losuj�cej
zwyczajna grzeczno�� nakazuje podzieli� si� z autorem programu w stosunku 1:3.
Trzy cz�ci dla autora programu, jedna dla gracza :)

Algorytm generowania liczby losowej
1) Przelicz pul� losowanych liczb
2) Uruchom generator liczb pseudolowych (srand(time(NULL))
3) Wygeneruj liczb� losow� funkcj� rand()
4) Umie�� liczb� losow� w tablicy tablica_losow[]
5) Punkty 3-5 wykonaj liczba_ciagniec razy

W jednym zakladzie generowane s� duplikaty liczb pseudolosowych
Duplikaty usuwane s� przez por�wnywanie element�w tablicy:
a)pierwszy element por�wnywany jest z pozosta�ymi
b) drugi element por�wnywany jest z pozosta�ymi
.............itd
c)przedostani element por�wnywany jest z ostatnim

P�tla por�wnawcza "a" wykonywana jest dop�ty, dop�ki liczba duplikat�w nie jest r�wna 0.

*/




#include <iostream>
#include <time.h>

using namespace std;

int main()
{

    //minimalna wartosc losowanej liczby
    int wartosc_losu_min;

    //maksymalna wartosc losowanej liczby
    int wartosc_losu_max;

    //ilosc liczb w jednym zakladzie
    int liczba_ciagniec;

    //ilosc losowanych liczb
    int pula_losow;

    //wartosc losowanej liczby
    int liczba_wylosowana;

    //rozmiar tablicy, w ktorej umieszczone zostana wylosowane liczby
    int rozmiar_tablica_losow;

    //indeks elementow tablicy tablica_losow
    int i_tablica_losow;

    //indeks sprawdzanmego elementu tablicy pod katem duplikatow
    int i_sprawdzane;

    //liczba duplikatow - do testow
    int liczba_duplikatow;

    //walidacja zmiennych
    rozmiar_tablica_losow=6;
    wartosc_losu_min=1;
    wartosc_losu_max=49;

    //ustawienie warto�ci na 1 umo�liwia wej�cie w p�tl� "a"
    liczba_duplikatow=1;


    //deklaracja mo�liwa dopiero po okre�leniu warto�ci size_tablica_losow
    int tablica_losow[rozmiar_tablica_losow];

    /*liczymy po ameryka�sku od 0
    dlatego faktyczna liczba ci�gni�� to liczba_ciagniec+=1
    */
    liczba_ciagniec=5;

    pula_losow=(wartosc_losu_max-wartosc_losu_min)+1;

    //uruchomienie generatora liczb pseudolosowych
    srand(time(NULL));

    //wrzutka wylosowanych liczb do tablicy


    //p�tla "a"
    //warto�� inicjalna testowanej zmiennej to 1 (patrz wy�ej)
    while (liczba_duplikatow!=0){


        //je�eli duplikaty zaistniej�, warto�� zwi�kszy si� o 1 z ka�dym duplikatem
        //je�eli duplikaty nie zaistniej�, warto�� b�dzie r�wna 0 i p�tla "a" zako�czy dzia�anie

        liczba_duplikatow=0;


    //losowanie liczby i umieszczenie jej w tablicy
    for (i_tablica_losow=0;i_tablica_losow<=liczba_ciagniec;i_tablica_losow++){

        //losowanie
        liczba_wylosowana=rand()%pula_losow+wartosc_losu_min;

        //umnieszczenie w tablicy
        tablica_losow[i_tablica_losow]=liczba_wylosowana;

    }



    /*por�wnywanie element�w tablicy w celu znalezienia duplikat�w
    Je�eli por�wnamy element [0] z pozosta�ymi, w�wczas element [0] wypada z pozosta�ych iteracji.
    Tak dzieje si� z ka�dym kolejnym elementem
    Je�li por�wnali�my elementy [0] i [1] nie ma potrzeby por�wnywa� element�w [1] i [0].
    */
    for (i_sprawdzane=0;i_sprawdzane<=liczba_ciagniec;i_sprawdzane++){


        for (i_tablica_losow=i_sprawdzane+1;i_tablica_losow<=liczba_ciagniec;i_tablica_losow++){


            if (tablica_losow[i_sprawdzane]==tablica_losow[i_tablica_losow]){

                liczba_duplikatow+=1;

            }

        }

    }

    }



    //prezentacja tablicy wylosowanych liczb
    for (i_tablica_losow=0;i_tablica_losow<=liczba_ciagniec;i_tablica_losow++){

        cout << tablica_losow[i_tablica_losow] << endl;


    }
        //potrzebne do test�w
        //cout<<"liczba duplikatow: " << liczba_duplikatow << endl;

    //koniec prezentacji

    return 0;
}
