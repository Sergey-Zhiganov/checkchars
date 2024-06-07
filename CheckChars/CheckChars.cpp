#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

typedef bool (*CheckCharsInStringFunc)(const char*, const char*);


int main()
{
    SetConsoleCP(1251);
    setlocale(LC_ALL, "ru");
    string inputString;
    string inputChars;
    cout << "Введите строку: ";
    getline(cin, inputString);
    cout << "Введите символы для поиска: ";
    cin >> inputChars;
    HMODULE hDLL = LoadLibraryA("CheckCharsDLL.dll");
    if (!hDLL) {
        cout << "Не удалось загрузить библиотеку!" << endl;
        return 1;
    }
    CheckCharsInStringFunc checkCharsInString = (CheckCharsInStringFunc)GetProcAddress(hDLL, "CheckCharsInString");
    if (!checkCharsInString) {
        cout << "Не удалось получить адрес функции!" << endl;
        FreeLibrary(hDLL);
        return 1;
    }
    bool result = checkCharsInString(inputString.c_str(), inputChars.c_str());
    if (result) {
        cout << "Все символы найдены в строке" << endl;
    }
    else {
        cout << "Не все символы найдены в строке" << endl;
    }
    FreeLibrary(hDLL);
    return 0;
}
