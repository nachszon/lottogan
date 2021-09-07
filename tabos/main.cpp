#include <iostream>
#include<algorithm>
#include<ctime>

using namespace std;

int start_rand=1;
int end_rand=49;
int count_rand=6;;

class generateRandClass{

    public:
    int meth_generate_one_rand(int skel_start_rand,int skel_end_rand);
    void meth_generate_set_rand(int skel_tab[],int skel_count_elements);



    };


class manageArrayClass{


    public:
    void meth_sort_arr(int skel_tab[],int skel_number_elements);
    void meth_show_arr(int skel_tab[],int skel_max_index);
    void meth_erase_duplicat();
};

int generateRandClass::meth_generate_one_rand(int skel_start_rand,int skel_end_rand){

    int rand_arg;
    int rand_out;

    rand_arg=(skel_end_rand-skel_start_rand)+1;

    rand_out=rand()%rand_arg+skel_start_rand;

    return rand_out;
}

void generateRandClass::meth_generate_set_rand(int skel_tab[],int skel_count_elements){

    for(int _index=0;_index<=skel_count_elements;_index++){

        skel_tab[_index]=meth_generate_one_rand(start_rand,end_rand);

    }

}

void manageArrayClass::meth_sort_arr(int skel_tab[],int skel_number_elements){

    sort(skel_tab,skel_tab+skel_number_elements);

}

void manageArrayClass::meth_show_arr(int skel_tab[],int skel_max_index){

    int arr_index;

    for (arr_index=0;arr_index<skel_max_index;arr_index++){

            cout << skel_tab[arr_index] << " ";


    }

    cout << endl;

}

void manageArrayClass::meth_erase_duplicat(){

    int tab[count_rand];
    generateRandClass generateRandObj;


    int check_duplicate=1;

    while (check_duplicate!=0){

            check_duplicate=0;

        generateRandObj.meth_generate_set_rand(tab,count_rand);
        for (int _index=0;_index<count_rand;_index++){

            for (int _index_in=_index+1;_index_in<=count_rand;_index_in++){

                if (tab[_index]==tab[_index_in]){

                    check_duplicate++;
                }
            }
        }

    }



    meth_sort_arr(tab,count_rand);
    meth_show_arr(tab,count_rand);


}


int main()
{
    //start engine rand
    srand(time(NULL));

    manageArrayClass manageArrayObj;
    manageArrayObj.meth_erase_duplicat();







}
