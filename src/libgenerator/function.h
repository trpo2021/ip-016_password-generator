#pragma once

#include <iostream>
#include <random>

using namespace std;
random_device rd;


int selectArray()
{
    mt19937 mersenne(rd());
    int i = mersenne() % 4 + 1;
    return i;
}
