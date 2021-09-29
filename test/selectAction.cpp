#include "ctest.h"
#include "libgenerator/function.h"

using namespace std;

CTEST(selectAction, exit)
{
    int opt_exit = 2;
    int expect = -1;
    int real = selectAction(opt_exit);
    ASSERT_EQUAL(expect, real);
}

CTEST(selectAction, exit)
{
    int length = 6;
    int real = selectAction(1);
    ASSERT_EQUAL(100, real);
}

CTEST(selectAction, exit)
{
    int length = 1000000000;
    int real = selectAction(1);
    ASSERT_EQUAL(200, real);
}
