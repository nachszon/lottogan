/*lottogan
wersja 10
maj 2020
Krzysztof Nachszon Lipa-Izdebski

Ogólnie
Program do generowania ca³kowitych liczb pseudolosowych.
Losowanych jest 6 liczb z puli 49 na wzór du¿ego lotka
Autor ani nie gwarantuje wygranej ani nie ponosi kosztów
ewentualnych strat poniesionych w wyniku u¿ywania programu.
Jednak w przypadku wygranej w du¿ego lotka przy u¿yciu tej maszyny losuj¹cej
zwyczajna grzecznoœæ nakazuje podzieliæ siê z autorem programu w stosunku 1:3.
Trzy czêœci dla autora programu, jedna dla gracza :)

Algorytm generowania liczby losowej
1) Przelicz pulê losowanych liczb
2) Uruchom generator liczb pseudolowych (srand(time(NULL))
3) Wygeneruj liczbê losow¹ funkcj¹ rand()
4) Umieœæ liczbê losow¹ w tablicy tablica_losow[]
5) Punkty 3-5 wykonaj liczba_ciagniec razy

W jednym zakladzie generowane s¹ duplikaty liczb pseudolosowych
Duplikaty usuwane s¹ przez porównywanie elementów tablicy:
a)pierwszy element porównywany jest z pozosta³ymi
b) drugi element porównywany jest z pozosta³ymi
.............itd
c)przedostani element porównywany jest z ostatnim

Pêtla porównawcza "a" wykonywana jest dopóty, dopóki liczba duplikatów nie jest równa 0.

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

    //ustawienie wartoœci na 1 umo¿liwia wejœcie w pêtlê "a"
    liczba_duplikatow=1;


    //deklaracja mo¿liwa dopiero po okreœleniu wartoœci size_tablica_losow
    int tablica_losow[rozmiar_tablica_losow];

    /*liczymy po amerykañsku od 0
    dlatego faktyczna liczba ci¹gniêæ to liczba_ciagniec+=1
    */
    liczba_ciagniec=5;

    pula_losow=(wartosc_losu_max-wartosc_losu_min)+1;

    //uruchomienie generatora liczb pseudolosowych
    srand(time(NULL));

    //wrzutka wylosowanych liczb do tablicy


    //pêtla "a"
    //wartoœæ inicjalna testowanej zmiennej to 1 (patrz wy¿ej)
    while (liczba_duplikatow!=0){


        //je¿eli duplikaty zaistniej¹, wartoœæ zwiêkszy siê o 1 z ka¿dym duplikatem
        //je¿eli duplikaty nie zaistniej¹, wartoœæ bêdzie równa 0 i pêtla "a" zakoñczy dzia³anie

        liczba_duplikatow=0;


    //losowanie liczby i umieszczenie jej w tablicy
    for (i_tablica_losow=0;i_tablica_losow<=liczba_ciagniec;i_tablica_losow++){

        //losowanie
        liczba_wylosowana=rand()%pula_losow+wartosc_losu_min;

        //umnieszczenie w tablicy
        tablica_losow[i_tablica_losow]=liczba_wylosowana;

    }



    /*porównywanie elementów tablicy w celu znalezienia duplikatów
    Je¿eli porównamy element [0] z pozosta³ymi, wówczas element [0] wypada z pozosta³ych iteracji.
    Tak dzieje siê z ka¿dym kolejnym elementem
    Je¿li porównali¿my elementy [0] i [1] nie ma potrzeby porównywaæ elementów [1] i [0].
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
        //potrzebne do testów
        //cout<<"liczba duplikatow: " << liczba_duplikatow << endl;

    //koniec prezentacji

    return 0;
}
