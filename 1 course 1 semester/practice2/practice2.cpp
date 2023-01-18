#include <iostream>
#include <string>

using namespace std;


void fill_arrays(string number, int* number_arr) {
    // если длина строки не более 1000 (по условию задачи)
    if (number.length() < 1001) {
        int k = 0;
        for (int i = number.length() - 1; i >= 0; i--) {
            number_arr[k] = number[i] - 0x30; // записываем символы строки в массив как число с конца
            k += 1;
        }
    }
}

void fix_result(string &result) {
    cout << result << endl;
    while (result[0] == '0'){
        result.erase(0, 1);
        if (result.length() == 1) {
            result = "0";
            break;
        }
    }
}

void addition(int* A, int* B, int lengthA, int lengthB) {
    // операция сложения

    int C[1001] = { 0 }; // создаем массив суммы (на 1 элемент больше для макс больших A и B)

    int length = 0; // длина 

    // ищем массив с макс длиной
    if (lengthA > lengthB) {
        length = lengthA;
    }
    else {
        length = lengthB;
    }

    int c = 0; // индекс C
    bool k = 0; // добавка к след. разряду

    // повторяем на один раз больше, чем длина макс массива, т.к. сумма может быть на 1 разряд больше
    for (int i = 0; i < length + 1; i++) {

        int summ = 0; // значение разряда

        // недостающий (пустой) элемент массива приравниваем к 0 (пустой элемент имеет значение меньше 0)
        if (A[i] < 0) {
            A[i] = 0;
        }
        if (B[i] < 0) {
            B[i] = 0;
        }

        cout << A[i] << "\t" << B[i] << endl;

        summ = A[i] + B[i] + k;

        // значение разряда равно остатку суммы двух слагаемых и добавки от прошлой операции
        C[c] = summ % 10;

        k = summ / 10;

        c += 1;
    }

    string result;

    for (int i = c-1; i >= 0; i--) {
        result.push_back(C[i] + '0');
    }

    fix_result(result);

    cout << "\t= " << result << endl;
}

void multiplication(int* A, int* B, int lengthA, int lengthB) {
    // операция умножения

    int C[2000] = { 0 }; // создаем массив произведения (длина массива может достигать 2000 при макс A и B)

    int k = 0; // добавка к след. разряду
    int c = 0; // индекс массива C

    int digit = 0; // сдвиг на разряд

    for (int i = 0; i < lengthA + lengthB; i++) {
        for (int j = 0; j < lengthB; j++) {
            int mlt = 0; // значение разряда

            int add_to_digit = 0; // добавка к следующему разряду из предыдущего разряда

            // придаем недостающему элементу значение 0
            if (A[i] < 0) {
                A[i] = 0;
            }
            if (B[j] < 0) {
                B[j] = 0;
            }

            mlt = (A[i] * B[j]) + k; // произведение элементов массива + добавка\
                                                                    от значения предыдущей суммы

            C[c + digit] += mlt % 10; // прибавляем к существующему значению разряда значения\
                                                                    от произведения других элеменотов

            add_to_digit = C[c + digit] / 10; // находим добавку от суммы значений разряда

            C[c + digit] = C[c + digit] % 10; // определяем значение разряда

            C[c + digit + 1] += add_to_digit; // добавляем добавку к след. разряду

            k = mlt / 10;

            c += 1;
        }
        digit += 1; // начинаем след. шаг с разряда большего на 1
        c = 0;
    }

    string result;

    for (int i = digit; i >= 0; i--) {
        result.push_back(C[i] + '0');
    }

    fix_result(result);

    cout << "\t= " << result << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string A, B; // создаем строки для вводимых чисел

    cout << "Введите числа A и B не более, чем из 1000 цифр" << endl;
    cout << "A: ";
    cin >> A;
    cout << "B: ";
    cin >> B;

    int A1[1000] = { 0 }; // создаем массивы int для посимвольного хранения чисел
    int B1[1000] = { 0 };

    fill_arrays(A, A1); // заполняем массивы символами из строки
    fill_arrays(B, B1);

    int lengthA = A.length(); // определяем длины массивов
    int lengthB = B.length();
    
    cout << A << "\t" << B << endl;

    cout << "Операция сложения:" << endl;
    addition(A1, B1, lengthA, lengthB);

    cout << endl << "Операция умножения" << endl;
    multiplication(A1, B1, lengthA, lengthB);

}
