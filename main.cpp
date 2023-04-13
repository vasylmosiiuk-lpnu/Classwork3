// Classwork3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CRandomNumberGenerator.h"

using namespace std;

int main()
{
    CRandomNumberGenerator rnd{ 5 }; // ctor(seed)

    cout << rnd << endl; // operator<<()
    cout << rnd.getNext() << endl; // getNext(min, max)
    cout << rnd.getNext(5,4) << endl; // getNext(min, max)
    cout << rnd.getNextDouble() << endl; // getNextDouble()
    cout << rnd() << endl; // operator()

    unsigned int numbers[10];
    rnd.getNextNumbers(numbers, 10); // getNextNumbers()

    auto rnd2{ rnd }; // copy ctor
    CRandomNumberGenerator rnd3; // ctor default
    rnd3 = rnd; //copy assignment

    auto rnd4{ std::move(rnd) }; // move ctor
    rnd4 = std::move(rnd3); // move assignment
    
    cout << "Hello World!\n";
}
