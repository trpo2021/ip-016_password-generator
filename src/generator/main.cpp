#include "libgenerator/lib.h"
#include <iostream>
#include <ctime>
#include <time.h>
#include <random>


using namespace std;
random_device rd;


int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "rus");
    int opt, length;
    //Меню
    do 
    {
        cout << "\n-----------------------------\n";
        cout << "      Генератор паролей \n";
        cout << "------------------------------\n\n";
        cout << "    1. Сгенерировать пароль"
            << "\n";
        cout << "    2. Выход"
            << "\n\n";
        cout << "Нажмите кнопку 1 для генерации пароля и кнопку 2 для выхода из программы  : ";
        cin >> opt;

        switch (opt) 
        {
        case 1:
            cout << "Введите длину пароля :  ";
            cin >> length;
            // Если длина меньше 7, программа покажет ошибку
            if (length < 7) 
            {
                cout << "\nОшибка : Длина пароля должна быть не менее 7 символов\n";
                cout << "Нажмите любую кнопку для продолжения \n";
                getchar();
            }
            // Длина не должна превышать 100 символов, если превышает , то будет ошибка
            else if (length > 100) 
            {
                cout << "\nОшибка : Длина пароля не должна быть более 100 символов\n";
                cout << "Нажмите любую кнопку для продолжения \n";
                getchar();
            }
            // В противном случае вызовите функцию generate_password () для генерации пароля.
            else
                generate_password(length);
            break;

        default:
            // Если пользователь выбрал недопустимый вариант, он также покажет ошибку
            if (opt != 2) 
            {
                printf("\nНеправильый выбор\n");
                printf("Нажмите пожалуйста кнопку 1 для генерации пароля и кнопку 2 для выхода из программы.\n");
                cout << "Нажмите любую кнопку для повторения \n";
                getchar();
            }
            break;
        }
    } while (opt != 2);

    return 0;
}