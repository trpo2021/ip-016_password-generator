#include "ctest.h"
#include "libgenerator/function.h"
#include <fstream>
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
    ifstream in("ip-016_password-generator/password.txt");
    int b = is_empty(in) int real2 = 0 ASSERT_EQUAL(b, real2);
}

CTEST(selectAction, empty)
{
    ifstream in("ip-016_password-generator/password.txt");
    int b = is_empty(in);
    int real2 = 1 ASSERT_NOT_EQUAL(b, real2);
}

CTEST(getKey, key)
{
    int c = getKey();
    ASSERT_NOT_NULL(c);
}
