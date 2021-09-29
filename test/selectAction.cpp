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

CTEST(selectAction, length)
{
    ifstream in("ip-016_password-generator/password.txt");
    if (in.is_open()) {
        while (getline(in, password)) {
            cout << password << endl;
        }
    }
    int lenght;
    if lenght
        > 7 and < 100
        {
            int real = lenght;

            in.close();

            return 0;
        }
    ASSERT_EQUAL(expect, real);
}