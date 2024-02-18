#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int**& a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void Sort(int**& a, const int n);

int main() {
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    Sort(a, n);
    Print(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int**& a, const int n, const int Low, const int High) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int**& a, const int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][n - i - 1] < a[j][n - j - 1]) {
                int temp = a[i][n - i - 1];
                a[i][n - i - 1] = a[j][n - j - 1];
                a[j][n - j - 1] = temp;
            }
        }
    }
}