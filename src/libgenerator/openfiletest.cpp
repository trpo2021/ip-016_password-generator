#include <fstream>
#include <string>
#include "libgenerator/openfiletest.h"


int openfiletest(fstream& fin, string patch){

fin.open(patch);

    if (!fin.is_open()) {
        return 1;
        }
        return 0;
}
