#include "iostream"
#include <cctype>
#include <string>
#include <fstream>
#include <windows.h>


using namespace std;

void count_letters(int letters[32]) {
	ifstream in("input.txt", ios::in);
	while (!in.eof()) {
		unsigned char letter;
		in >> letter;
		int code_letter = tolower(letter);
		letters[code_letter - 224] += 1;
	}
}

void find_popular_letters(int letters_counts[32], char letters[32]) {
	int alphabet = 33;
	for (int i = 0; i < alphabet + 1; i++)
	{
		for (int j = alphabet - 1; j > i; j--)
		{
			if (letters_counts[j] > letters_counts[j - 1])
			{
				swap(letters_counts[j], letters_counts[j - 1]);
				
				swap(letters[j], letters[j - 1]);
			}
		}
	}
}

bool count_letter(string word, char l) {
	for (int i = 0; i < word.size(); i++) {
		if (toupper(word[i]) == l) {
			return 1;
		}
	}
	return 0;
}

string tolower_str(string word) {
	string low_word = "";
	for (int i = 0; i < word.length(); i++) {
		low_word.push_back(tolower(word[i]));
	}
	return low_word;
}

string toupper_str(string word) {
	string up_word = "";
	for (int i = 0; i < word.length(); i++) {
		up_word.push_back(toupper(word[i]));
	}
	return up_word;
}

string changed_word(string word, char a, char b) {
	string new_word = toupper_str(word);
	char last;
	bool punct = 0;
	if (ispunct(new_word[new_word.length() - 1])) { // проверка на знак пунктуации 
		last = new_word[new_word.length() - 1];
		new_word.erase(new_word.length()-1, 1);
		punct = 1;
	}

	new_word.push_back('(');
	new_word.push_back(a);
	new_word.push_back(b);
	new_word.push_back(')');
	if (punct) {
		new_word.push_back(last);
	}

	return new_word;
}

string check_word(string word, string popular) {
	cout << word << endl;
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			if (popular[a] != popular[b]) {
				for (int i = 0; i < word.length() - 1; i++) {
					if (word[i] == popular[a]) {
						if (word[i + 1] == popular[b]) {
							return changed_word(word, popular[a], popular[b]);
						}
					}
				}
			}
		}
	}
	return word;
}

void compose_output(string popular) {
	ifstream in("input.txt", ios::in);
	ofstream out;
	out.open("output.txt");
	string line;
	while (getline(in, line)) {
		string word;
		cout << line << endl;
		for (int i = 0; i < line.length(); i++) {
			cout << line[i] << endl;
			word.push_back(line[i]);
			if (line[i] == ' ' || i == line.length()-1) {
				out << check_word(tolower_str(word), tolower_str(popular)) << " ";
				word = "";
			}
		}
		out << "\n";
	}
}

int main() {

	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char letters[] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', \
						'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', \
							'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', \
								'э', 'ю', 'я' };

	int letters_counts[32] = { 0 };

	count_letters(letters_counts);

	find_popular_letters(letters_counts, letters);

	string popular = "";
	for (int i = 0; i < 4; i++) {
		popular.push_back(letters[i]);
	}

	compose_output(popular);

    return 0;
}