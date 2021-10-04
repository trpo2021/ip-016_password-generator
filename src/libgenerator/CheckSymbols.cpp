#include "libgenerator/CheckSymbols.h"
#include "libgenerator/function.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int CheckSymbols(fstream& file, string path, string symbol)
{
    file.open(path, ios::app | ios::out | ios::in | ios::binary);
    if (!file.is_open()) {
        return 1;
        // cout << "File do not open" << endl;
    } else {
        string msg;
        while (!file.eof()) {
            msg = "";
            file >> msg;
            // cout << msg << endl;
            if (msg.find(symbol) != string::npos) {
                return 2;
                // cout << "Symbol " << symbol << " find" << endl;
            } else
                return 0;
            // cout<<  "Symbol " << symbol << " not find" << endl;
        }
    }
    file.close();
    return -1;
}
