/*lottogan
version 1.0
author: Nachszon
Program to generate random numbers

---

Numbers are located in array
This version not delete duplicate
*/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    //first number of range
    int start_number;

    //last number of range
    int end_number;

    //first part of rand() function's argument
    int rand_number;

    //variable with random number value
    int out_number;

    //how many numbers we draw
    int max_count_draw_numbers;


    /*configuration section*/
    start_number=1;
    end_number=49;
    max_count_draw_numbers=6;
    /*end of configuration section*/

    //array for generate random numbers
    int tab_rand_numb[max_count_draw_numbers];


    //rand_number is the amount of numbers in the range
    rand_number=(end_number-start_number)+1;


    //start random generator
    //only ones
    srand(time(NULL));




    for (int min_count_draw_numbers=0;min_count_draw_numbers<max_count_draw_numbers;min_count_draw_numbers++){
    //generate rand number
    out_number=rand()%rand_number+start_number;
    tab_rand_numb[min_count_draw_numbers]=out_number;

    }


    //show generate numbers
    for (int i=0; i<max_count_draw_numbers;i++){
    cout << tab_rand_numb[i] << endl;
    }

    return 0;
}
