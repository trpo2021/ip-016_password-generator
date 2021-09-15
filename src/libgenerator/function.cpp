#include <libgenerator\function.h>

#include <ctime>
#include <time.h>


using namespace std;
random_device rd;


int selectArray()
{
    mt19937 mersenne(rd());
    int i = mersenne() % 4 + 1;
    return i;
}
