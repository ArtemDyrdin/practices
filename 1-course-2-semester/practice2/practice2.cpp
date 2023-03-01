#include <iostream>

using namespace std;

void quickCopy(int *mas_a, int *mas_b, int N) {
    unsigned long long* source = (unsigned long long*)mas_a;
    unsigned long long* place = (unsigned long long*)mas_b;

    // копируем по long long
    for (int i = 0; i < N / sizeof(long long); i++) {
        *(place++) = *(source++);
    }

    unsigned char* source2 = (unsigned char*)source;
    unsigned char* place2 = (unsigned char*)place;

    // копируем остаток по 1 байту
    for (int i = 0; i < N % sizeof(long long); i++) {
        *(place2++) = *(source2++);
    }
}

void showElements(int* mas, int N) {
    for (int i = 0; i < N; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int N = 100;
    int mas_a[N] = { 1, 2, 3, 4, 5};
    int mas_b[N] = { 0 };

    quickCopy(mas_a, mas_b, sizeof(mas_a));

    showElements(mas_b, N);
}
