#include <iostream>
#include <vector>

using namespace std;

void fillArr(vector<int>& arr, int size) {
    
    cout << "введите элементы массива ";
    for (int i = 0; i < size; i++) {
        int value;
        cout << "mas[" << i << "] = ";
        cin >> value;
        arr.push_back(value);
    }
}

int sumArr(vector<int>& arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double averageArr(vector<int>& arr, int size) {
    int sum = sumArr(arr, size);
    return (sum * 1.0) / size;
}

int sumNeg(vector<int>& arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) sum += arr[i];
    }
    return sum;
}

int sumPos(vector<int>& arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) sum += arr[i];
    }
    return sum;
}

int sumOdd(vector<int>& arr, int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int sumEven(vector<int>& arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += arr[i];
    }
    return sum;
}

void findMax(vector<int>& arr, int size, int& maxElement, int& maxIndex) {
    maxElement = arr[0];
    maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxIndex = i;
        }
    }
}
void findMin(vector<int>& arr, int size, int& minElement, int& minIndex) {
    minElement = arr[0];
    minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
            minIndex = i;
        }
    }
}

int betweenMaxMin(vector<int>& arr, int maxIndex, int minIndex) {
    if (maxIndex == minIndex) return 0;
    int start = min(maxIndex, minIndex);
    int end = max(maxIndex, minIndex);
    int res = 1;

    for (int i = start + 1; i < end; i++) {
        res *= arr[i];
    }
    return res;
}

void sort(vector<int>& arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    system("chcp 1251");
    int size;
    cout << "введите количество элементов ";
    cin >> size;
    vector<int> arr;
    fillArr(arr, size);

    cout << "cумма элементов " << sumArr(arr, size) << endl;
    cout << "cреднее значение  " << averageArr(arr, size) << endl;
    cout << "cумма отрицательных  " << sumNeg(arr, size) << endl;
    cout << "cумма положительных  " << sumPos(arr, size) << endl;
    cout << "cумма элементов с нечётными индексами " << sumOdd(arr, size) << endl;
    cout << "cумма элементов с чётными индексами " << sumEven(arr, size) << endl;

    int maxElement, maxIndex, minElement, minIndex;
    findMax(arr, size, maxElement, maxIndex);
    findMin(arr, size, minElement, minIndex);

    cout << "max элемент " << maxElement << " с индексом " << maxIndex << endl;
    cout << "min элемент " << minElement << " с индексом " << minIndex << endl;

    if (maxIndex != minIndex) {
        cout << "произведение между максимальным и минимальным " << betweenMaxMin(arr, maxIndex, minIndex) << endl;
    }
    sort(arr, size);
    cout << "отсортированный массив ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

}