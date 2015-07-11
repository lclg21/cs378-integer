// -----------------------------------
// projects/c++/integer/RunInteger.c++
// Copyright (C) 2015
// Glenn P. Downing
// -----------------------------------

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <deque>    // deque
#include <ctime>

#include "Integer.h"

// ----
// main
// ----

int main () {
    using namespace std;
    cout << "RunInteger.c++" << endl << endl;

    // less than 500 ms
    cout << "*** 20th Mersenne prime: 1,332 digits ***" << endl << endl;
    std::clock_t start;
    {
      start = std::clock();
    const Integer<int> n = Integer<int>(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    cout << "Time: " <<(std::clock()-start)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl << endl;
    }
    std::clock_t start3;
    {
      start3 = std::clock();
    const Integer< int, std::deque<int> > n = Integer< int, std::deque<int> >(2).pow(4423) - 1;
    cout << "2^4423 - 1 = " << n << endl << endl;
    cout << "Time: " <<(std::clock()-start3)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl << endl;
    }

    // --------------------------
    // extra credit (5 bonus pts)
    // --------------------------

    // // less than 4 min
    // cout << "*** 30th Mersenne prime: 39,751 digits ***" << endl << endl;
    // std::clock_t start2;
    // {
    //   start2 = std::clock();
    // const Integer<int> n = Integer<int>(2).pow(132049) - 1;
    // cout << "2^132049 - 1 = " << n << endl << endl;
    // cout << "Time: " <<(std::clock()-start2)/(double)(CLOCKS_PER_SEC/1000) << " ms" << endl;
    // }

    // cout << "Done." << endl;

    return 0;}