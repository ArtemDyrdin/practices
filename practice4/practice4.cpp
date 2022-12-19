//Целые числа от 0 до 63

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

void compose(vector<char>& numbers){
	string number;
	for (int i = 0; i < 64; i++) {	// переводим все числа в двоичную систему с макс длиной и складываем как строки
		string binary = bitset<6>(i).to_string();
		number += binary;
	}
	cout << "Все числа в двоичной системе: " << number << endl;
	string num = "";
	cout << endl << "Разбиваем по 8 знака" << endl;
	int k = 1;
	for (int i = 0; i < number.length(); i++) { // разбиваем числа по массиву
		num += number[i];
		if ((num.length() % 8 == 0) || i == number.length() - 1) {
			unsigned char decimal = bitset<8>(num).to_ulong();
			numbers.push_back(decimal);
			cout << num << "\t" << k << endl;
			num = "";
			k++;
		}
	}
}

void unpucking(vector<char>& numbers) {
	cout << endl << "unpucking" << endl;
	string number;
	for (int i = 0; i < 48; i++) {	// переводим все числа в двоичную систему с макс длиной и складываем как строки
		string binary = bitset<8>(numbers[i]).to_string();
		number += binary;
	}
	cout << endl << number << endl;

	string num = "";
	int k = 1;
	for (int i = 0; i < number.length(); i++) { // разбиваем числа по массиву
		num += number[i];
		if ((num.length() % 6 == 0) || i == number.length() - 1) {
			unsigned int decimal = bitset<6>(num).to_ulong();
			cout << decimal << endl;
			num = "";
			k++;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "russian");
	int bbb[64] = {0};
	cout << "Исходный размер чисел от 0 до 63: " << sizeof(bbb) << endl;

	// 2^6 = 64

	vector<char> numbers;

	compose(numbers); // сжимаем числа

	for (int i = 0; i < 48; i++) {
		cout << numbers[i] << "\t" << i+1 << endl;
	}

	cout << "После сжатия: " << numbers.size() << endl;

	unpucking(numbers);

	return 0;
}
