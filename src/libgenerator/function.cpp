#include "libgenerator/function.h"
#include <fstream>
#include <string>

int getKey()
{
    std::random_device rd;
    mt19937 mersenne(rd());

    int key = mersenne() % 26;
    return key;
}

char* generate_password(int length)
{
    char* password = new char[100];

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_symbol = "!@#$%&:)(-_=";
    string number = "0123456789";
    int i = 0;

    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0,
             count_s_symbol = 0;

    int count = 0;
    while (count < length) {
        int k = selectArray();

        if (count == 0) {
            k = k % 3 + 1;
        }
        switch (k) {
        case 1:

            if ((count_alphabet == 2)
                && (count_number == 0 || count_ALPHABET == 0
                    || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            password[i] = alphabet[key];
            count_alphabet++;
            i++;
            count++;
            break;

        case 2:

            if ((count_ALPHABET == 2)
                && (count_number == 0 || count_alphabet == 0
                    || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password[i] = ALPHABET[key];
            i++;
            count_ALPHABET++;
            count++;
            break;

        case 3:

            if ((count_number == 1)
                && (count_alphabet == 0 || count_alphabet == 1
                    || count_ALPHABET == 1 || count_ALPHABET == 0
                    || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            password[i] = number[key];
            i++;
            count_number++;
            count++;
            break;

        case 4:

            if ((count_s_symbol == 1)
                && (count_alphabet == 0 || count_alphabet == 1
                    || count_ALPHABET == 0 || count_ALPHABET == 1
                    || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            password[i] = s_symbol[key];
            i++;
            count_s_symbol++;
            count++;
            break;
        }
    }
    return password;
}

int selectArray()
{
    std::random_device rd;
    mt19937 mersenne(rd());
    int i = mersenne() % 4 + 1;
    return i;
}

int selectAction(int opt)
{
    int length;
    string password;
    //Меню
    do {
        switch (opt) {
        case 1:
            cout << "Введите длину пароля :  ";
            cin >> length;
            // Если длина меньше 7, программа покажет ошибку
            if (length < 7) {
                cout << "\nОшибка : Длина пароля должна быть не менее 7 "
                        "символов\n";
                cout << "Нажмите любую кнопку для продолжения \n";
                getchar();
            }
            // Длина не должна превышать 100 символов, если превышает , то будет
            // ошибка
            else if (length > 100) {
                cout << "\nОшибка : Длина пароля не должна быть более 100 "
                        "символов\n";
                cout << "Нажмите любую кнопку для продолжения \n";
                getchar();
            }
            // В противном случае вызовите функцию generate_password () для
            // генерации пароля.
            else {
                return length;
            }
            getchar();
            break;

        default:
            // Если пользователь выбрал недопустимый вариант, он также покажет
            // ошибку
            if (opt != 2) {
                printf("\nНеправильый выбор\n");
                printf("Нажмите пожалуйста кнопку 1 для генерации пароля и "
                       "кнопку 2 для выхода из "
                       "программы.\n");
                cout << "Нажмите любую кнопку для повторения \n";
                getchar();
            }
            break;
        }
    } while (opt != 2);
    return -1;
}
