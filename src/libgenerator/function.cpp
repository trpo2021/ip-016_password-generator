#include <iostream>
#include <ctime>
#include <time.h>
#include <random>

using namespace std;
random_device rd;


int selectArray()
{
    mt19937 mersenne(rd());
    int i = mersenne() % 4 + 1;
    return i;
}

int getKey()
{
    mt19937 mersenne(rd());

    int key = mersenne() % 26;
    return key;
}
void generate_password(int length)
{
    string password = "";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_symbol = "!@#$%&:)(-_=";
    string number = "0123456789";

    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    int count = 0;
    while (count < length) {


        int k = selectArray();

        if (count == 0) {
            k = k % 3 + 1;
        }
        switch (k) {
        case 1:

            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;

        case 2:

            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:

            if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:

            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        }
    }

    cout << "\n-----------------------------\n";
    cout << "         Пароль             \n";
    cout << "------------------------------\n\n";
    cout << " " << password;
    cout << "\n\nНажмите любую кнопку для продолжения \n";
    getchar();
}