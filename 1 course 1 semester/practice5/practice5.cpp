#include <iostream>

using namespace std;

class DinArray {
private:
    int m_length = 0;
    int* m_list = new int[m_length];

public:
    DinArray() {}
    ~DinArray() {
        delete[] m_list;
    }

    void push_back(int el) {
        // добавление элемента в конец
        int* new_list = new int[m_length + 1];

        for (int i = 0; i < m_length; i++) {
            new_list[i] = m_list[i];
        }

        new_list[m_length] = el;

        delete[] m_list;

        m_list = new_list;

        m_length++;
    }

    void show_elements() {
        // вывод всех элементов
        for (int i = 0; i < m_length; i++) {
            cout << m_list[i] << " ";
        }
        cout << endl;
    }

    int get_length() {
        // вернуть количество элементов
        return m_length;
    }

    int get_element(int index) {
        // вернуть элемент по индексу
        return m_list[index];
    }

    void replace_element(int index, int el) {
        // изменить элемент по индексу
        m_list[index] = el;
    }

    void delete_element(int index) {
        // удалить элемент
        for (int i = 0; i < m_length-1; i++) {
            if (i >= index) {
                m_list[i] = m_list[i + 1];
            }
        }
        m_list[m_length - 1] = 0;
        m_length = m_length - 1;
    }

    void insert_element(int index, int el) {
        // вставить элемент по индексу
        int* new_list = new int[m_length + 1];

        for (int i = 0; i < m_length; i++) {
            if (i < index) {
                new_list[i] = m_list[i];
            }
            else if (i == index) {
                new_list[i + 1] = m_list[i];
                new_list[i] = el;
            }
            else if (i > index) {
                new_list[i+1] = m_list[i];
            }
        }
        delete[] m_list;

        m_list = new_list;

        m_length++;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    DinArray List;

    cout << "Добавление элементов в конец массива:" << endl;
    for (int i = 0; i < 5; i++) {
        List.push_back(i);
        List.show_elements();
    }

    cout << endl << "Кол-во элементов массива: " << List.get_length() << endl;

    cout << endl << "Элемент по индексу: " << List.get_element(2) << endl;

    List.replace_element(0, 10);
    cout << endl << "Замена элемента:" << endl;
    List.show_elements();

    cout << endl << "Удаление элемента:" << endl;
    List.delete_element(2);
    List.show_elements();

    cout << endl << "Вставка элемента по индексу:" << endl;
    List.insert_element(2, 22);
    List.show_elements();
}
