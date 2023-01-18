#include <iostream>
#include <vector>

using namespace std;

void show_elements(const vector<int>& Vector) {
    for (int i = 0; i < Vector.size(); i++) {
        cout << Vector[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> Vector = { 0, 1, 2, 3, 4 };
    show_elements(Vector);

    /*   1. push_back, erase, insert   */

    cout << endl << "push_back(n):" << endl;
    Vector.push_back(5); // добавление элемента в конец
    show_elements(Vector);

    cout << endl << "erase(iter):" << endl;
    vector<int>::iterator begin = Vector.begin(); // устанавливаем итератор - указатель на первый элемент
    Vector.erase(begin + 1); // удаляем второй элемент
    show_elements(Vector);

    cout << endl << "erase(begin, end):" << endl;
    vector<int>::iterator end = Vector.end(); // устанавливаем итератор - указатель на последний элемент
    Vector.erase(begin + 3, end); // удаляем все элементы, начиная с 4-го
    show_elements(Vector);

    cout << endl << "insert(iter, n):" << endl;
    Vector.insert(begin + 2, 8); // добавляем после второго элемента  
    show_elements(Vector);

    cout << endl << "insert(iter, t, n):" << endl;
    Vector.insert(begin, 2, 6); // добавляем перед первым элементом 2 раза
    show_elements(Vector);

    cout << endl << "insert(iter, begin1, begin1 + i):" << endl;
    vector<int> Vector1 = { 11, 12, 13, 14, 15 };
    begin = Vector.begin(); // переопределяем итератор - указатель на первый элемент
    Vector.insert(begin + 1, Vector1.begin(), Vector1.begin() + 3); // добавляем после первого элемента три первых элемента из вектора values
    show_elements(Vector);

    cout << endl << "insert(iter, mass):" << endl;
    end = Vector.end(); // переопределяем итератор - указатель на последний элемент
    Vector.insert(end, { 21, 22, 23 }); // добавляем в конец вектора элементы из списка { 21, 22, 23 }
    show_elements(Vector);

    /*   2. emplace_back   */

    cout << endl << "emplace_back(n):" << endl;
    Vector.emplace_back(31); // добавление элемента в конец без копирования внутри
    show_elements(Vector);

    /*   3. resize, reserve, shrink_to_fit, capacity   */   

    cout << endl << "resize(s):" << endl;
    Vector.resize(4); // оставляем первые четыре элемента
    show_elements(Vector);

    cout << endl << "resize(s, n):" << endl;
    Vector.resize(8, 1); // оставляем первые восемь элементов, если их меньше, то дописываем нули
    show_elements(Vector);

    cout << endl << "reserve(15)" << endl;
    Vector.reserve(15); // выделяем достаточно памяти для хранения 15 элементов

    cout << endl << "shrink_to_fit()" << endl;
    Vector.shrink_to_fit(); // подгоняем емкость под размер вектора

    cout << endl << "capacity():" << endl;
    cout << Vector.capacity() << endl; // выводим емкость вектора

    /*   4.	clear   */    

    cout << endl << "clear():" << endl;
    Vector.clear();
    show_elements(Vector);

    /*   5.	оператор присваивания и []   */

    Vector.emplace_back(7); // добавляем один элемент для дальнейших реализаций

    Vector1 = Vector; // присваиваем вектору Vector1 значение вектора Vector
    cout << "Vector1: " << endl;
    show_elements(Vector1);

    cout << "Vector[0]: " << Vector[0] << endl; // обращаемся элементу по индексу 0 к Vector

    cout << "Size: " << Vector.size() << endl;
    cout << "Capacity: " << Vector.capacity() << endl;

    cout << endl << "sizeof() : " << sizeof(vector<int>) << endl;
}
