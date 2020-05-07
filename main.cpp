/*lottogan
version 1.1
author: Nachszon
Program to generate random numbers
may 2020

---
Release Notes
Numbers are located in array
Duplicate are remove
*/

#include <iostream>
#include <time.h>

using namespace std;


class randomNumbersHandlerClass{


    public:

    /*this method generate one random number

    Argumnets:
    start_number - first number of range
    end_number - last number of range
    rand_number - first part of rand() function's argument

    Return:
    out_number - variable with random number value
    */
    int m_create_one_random_number(int start_number,int end_number);


    /*this method generate table with take_numbres random_numbers*/
    void m_create_random_numbers_array(int take_number);

};

//generate one random number
int randomNumbersHandlerClass::m_create_one_random_number(int start_number,int end_number){

    //first part of rand() function's argument
    int rand_number;

    //variable with random number value
    int out_number;


    rand_number=(end_number-start_number)+1;

    //generate random number
    out_number=rand()%rand_number+start_number;

    return out_number;

}


void randomNumbersHandlerClass::m_create_random_numbers_array(int taking_number){


    //array for generate random numbers
    int tab_rand_numb[taking_number];

    //count of duplicate in array tab_rand_numb
    //set to 1 - can enter to while loop body
    int count_duplicate=1;




    /*tab_rand_numb[0]=m_create_one_random_number(1,49);
    tab_rand_numb[1]=m_create_one_random_number(1,49);
    tab_rand_numb[2]=m_create_one_random_number(1,49);
    tab_rand_numb[3]=m_create_one_random_number(1,49);
    tab_rand_numb[4]=m_create_one_random_number(1,49);
    tab_rand_numb[5]=m_create_one_random_number(1,49);*/



    while (count_duplicate!=0){

    count_duplicate=0;
    //create array with random numbers
    for (int min_taking_number=0;min_taking_number<taking_number;min_taking_number++){

    tab_rand_numb[min_taking_number]=m_create_one_random_number(1,49);

    }


    for (int i_check=0; i_check<taking_number;i_check++){


            for (int i=i_check+1;i<=taking_number-1;i++){

                    if (tab_rand_numb[i_check]==tab_rand_numb[i]){
                    count_duplicate+=1;

                }

            }

            }

    }



    //clear console
    system("cls");

    cout<<"your lucky numbers:\n"<<endl;

    //show array with random numbers
    for (int i=0;i<taking_number;i++){

        cout << tab_rand_numb[i] <<"\n"<< endl;
    }


    /*on this line for count of duplicate check
    if soft work correcly, should be 0*/

    /*cout << "liczba duplikatow:" << count_duplicate << endl;*/


}



using namespace std;

int main()
{

    //create object
    randomNumbersHandlerClass randomNumbersHandlerObject;

    //start rundom numbers generator
    srand(time(NULL));

    //show random numbers
    randomNumbersHandlerObject.m_create_random_numbers_array(6);

    system("Pause");

    return 0;
}
