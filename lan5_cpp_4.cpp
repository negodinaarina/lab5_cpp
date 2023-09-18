#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    // Проверяем, что количество введенных аргументов равно 4, иначе выводим сообщение об ошибке и возвращаем 1
    if (argc != 4) {
        cerr << "Wrong parameters number, expected 3, got" << (argc - 1) << endl;
        return 1;
    }
    // Берем первый аргумент, инициализируем переменную его значением и проверяем, если он не равен
    // "-a" или "-m", печатаем сообщение об ошибке и возвращаем 1
    string param = argv[1];
    if (param != "-a" && param != "-m") {
        cerr << "Wrong flag value, expected -a or -m, got " << param << "\"" << endl;
        return 1;
    }
    // Пробуем с помощью функции stoi преобразовать строку в целое число,
    // если выходит - в зависимости от флага выводим ответ,
    // иначе - ловим исключение std::invalid_argument, брошенное stoi и выводим
    // сообщение о некорректном вводе.
    try {
        int a = stoi(argv[2]);
        int b = stoi(argv[3]);
        if (param == "-a") {
            cout << a + b << endl;
        } else if (param == "-m") {
            cout << a * b << endl;
        }
    } catch (const std::invalid_argument&) {
        cout << "Invalid input" << endl;
        return 1;
    }
}