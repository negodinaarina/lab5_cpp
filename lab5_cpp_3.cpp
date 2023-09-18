#include <iostream>;
using namespace std;
//Объявляем прототип функции, принимающей два целочисленных значения и один указатель
int search(int, int*, int);

int main(){
    // Объявляем размер входного массива и сам массив, инициализируем его, прося пользователя ввести значения
    int n;
    cout << "Enter array size";
    cin >> n;
    int mas[n];
    for(int i=0; i < n; i++){
        cout << "Enter " << i <<" element:" << endl;
        cin >> mas[i];
    }
    // Объявляем переменную, в которой будет храниться искомое значение, просим пользователя вводить это значение
    // в цикле, или для выхода из цикла ввсети -1
    int se;
    while(se != -1){
        cout << "Enter element value to search for, to exit type -1";
        cin >> se;
        cout << "Index of " << se << " is " << search(se, mas, n) << endl;
    }
    return 0;
}
// Функция поиска элемента с транспозицией
int search(int el, int* mas, int n){
    // проходим по циклу и ищем нужный элемент
    for(int i=0; i<n; i++){
        // если он первый - сразу выводим
        if(mas[i] == el){
            if(i==0){
                return i;
            }
            // иначе меняем местами значение искомого элемента с предыдущим и возвращаем позицию, на которой
            // искомый элемент стоял
            int temp = mas[i-1];
            mas[i-1] = el;
            mas[i] = temp;
            return i;
        }
    }
    // если не нашли - выводим -1
    return -1;
}