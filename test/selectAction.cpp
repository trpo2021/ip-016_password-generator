#include "ctest.h"
#include "libgenerator/function.h"
#include "libgenerator/openfiletest.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

CTEST(selectAction, exit)
{
    int opt_exit = 2;
    int expect = -1;
    int real = selectAction(opt_exit);
    ASSERT_EQUAL(expect, real);
}

CTEST(selectAction, empty)
{
    string path = "password.txt";
    fstream in;
    int testResult = openfiletest(in, path);
    int expect = 1;
    ASSERT_EQUAL(expect, testResult);
}

CTEST(selectAction, fail)
{
    string path = "passasdfasdfword.txt";
    fstream in;
    int testResult = openfiletest(in, path);
    int expect = 0;
    ASSERT_EQUAL(expect, testResult);
}
