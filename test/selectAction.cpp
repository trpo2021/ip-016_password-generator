#include "libgenerator/function.h"
#include "ctest.h"

CTEST(selectAction, exit)
{
     int opt_exit = 2;
     int expect = -1;
     int real = selectAction(opt_exit);
     ASSERT_EQUAL(expect, real);
}
