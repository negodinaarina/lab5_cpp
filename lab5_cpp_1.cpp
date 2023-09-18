#include <iostream>
using namespace std;

// Функция подсчета суммы отрицательных или положительных чисел, принимающая
// флаг со значениями -1,0,1, указатель на массив и размер массива
int pos_neg_sum(int fl, const int* mas, int n){
    int s = 0;
    // В зависимости от значения fl подсчитываем сумму в переменную s.
    switch(fl){
        case -1:
            for(int i=0; i<n; i++){
                if(mas[i] < 0) {
                    s += mas[i];
                }
            }
            return s;
        case 0:
            for(int i=0; i<n; i++){
                s += mas[i];
            }
            return s;

        case 1:
            for(int i=0; i<n; i++){
                if(mas[i] > 0) {
                    s += mas[i];
                }
            }
            return s;
    }
}
//  Функция подсчета суммы чисел на четной/нечетной позиции, fl - позиция, с которой начинаем считать
// если fl = 0, считаем на нечетной позиции, иначе - на четной.
int even_uneven_sum(int fl, int* mas, int n){
    int s = 0;
    for(int i=fl; i < n; i+=2){
        s += mas[i];
    }
    return s;
}

int main() {
    const int n = 5;
    int mas[n];
    // Получаем данные от пользователя и инициализируем массив
    for (int i = 0; i < n; i++) {
        cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    string ans;
    // Спрашиваем, какую сумму он хоче подсчитать и в зависимости от ответа вызываем соответствующую функцию
    // с нужными нам аргументами
    cout << "Which sum do you want to find? - positive/negative/even/uneven";
    cin >> ans;
    if(ans=="positive") {
        cout << pos_neg_sum(1, mas, n);
    }
    else if(ans=="negative"){
        cout << pos_neg_sum(-1, mas, n);
    }
    else if(ans=="even"){
        cout << even_uneven_sum(1, mas, n);
    }
    else if(ans=="uneven"){
        cout << even_uneven_sum(0, mas, n);
    }
}