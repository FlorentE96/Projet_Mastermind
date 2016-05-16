#include "zero_joueur.h"

void algo_1();
void algo_2();
void get_gnuplot_trace_algo_1();
void get_average_value_algo_1();
void test_algo_1();
void test_algo_2();

int main ()
{
    //get_gnuplot_trace_algo_1();
    //get_average_value_algo_1();

    int combinaison[4] = {1, 2, 1, 4};
    test_algo_1(combinaison);
    
    return 0;
}