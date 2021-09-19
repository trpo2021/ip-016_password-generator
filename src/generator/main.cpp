#include "libgenerator/function.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    int opt, length, exit;
    char* password;
    cout << "\n-----------------------------\n";
    cout << "      Генератор паролей \n";
    cout << "------------------------------\n\n";
    cout << "    1. Сгенерировать пароль"
         << "\n";
    cout << "    2. Выход"
         << "\n\n";
    cout << "Нажмите кнопку 1 для генерации пароля и кнопку 2 для выхода из программы  : ";
    cin >> opt;
    exit = selectAction(opt);
    if (exit > 0) 
    {
        length = exit;
        password = generate_password(length);
        cout << "\n-----------------------------\n";
        cout << "         Пароль             \n";
        cout << "------------------------------\n\n";
        for (int i = 0; i < length; i++) {
            cout << password[i];
        }
    }

    delete[] password;

    return 0;
}
