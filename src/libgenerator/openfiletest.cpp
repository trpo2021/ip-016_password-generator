#include "libgenerator/openfiletest.h"
#include <fstream>
#include <string>

int openfiletest(fstream& fin, string patch)
{
    fin.open(patch);

    if (!fin.is_open()) {
        return 1;
    }
    return 0;
}
