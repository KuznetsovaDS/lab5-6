#include <iostream>
#include <fstream>
using namespace std;

int* max_vect(int size, int* a, int* b) {
    int* c = new int[size];
    for (int i = 0; i < size; ++i) {
        if (a[i] > b[i]) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i];
        }
    }
    return c;
}

void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void arrayToFile(ofstream& file, const string& name, int* arr, int size) {
    file << name << ": ";
    for (int i = 0; i < size; ++i) {
        file << arr[i] << " ";
    }
    file << endl;
}

int main() {
    system("chcp 1251");
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 2 };
    int b[] = { 7, 6, 5, 4, 3, 2, 1, 3 };
    int kc = sizeof(a) / sizeof(a[0]); // Количество элементов массива
    int* c = max_vect(kc, a, b); // Вызов функции для создания массива

   
    ofstream file("arrays.txt");
    if (!file) {
        cerr << "Ошибка открытия файла" << endl;
        delete[] c;
        return 1;
    }
    arrayToFile(file, "исходный массив", c, kc);
    int* sortС = new int[kc];
    for (int i = 0; i < kc; ++i) {
        sortС[i] = c[i];
    }
    sortArray(sortС, kc);
    arrayToFile(file, "отсортированный массив", sortС, kc);
    delete[] sortС;
    delete[] c;
        
    file.close();
    return 0;
}