#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            if (i > 0) {
                swap(arr[i], arr[i - 1]);
            }
            return i;
        }
    }
    return -1;
}
int main()
{
    system("chcp 1251");
    vector<int> arr = { 4, 2, 5, 1, 3 };
    int key = 1;
    cout << "Исходный массив ";
    for (int i : arr) cout << i << " ";
    cout << endl;
    int index = search(arr, key);
    if (index != -1) {
        cout << "Элемент " << key << " найден на индексе " << index << endl;
        cout << "Массив после поиска ";
        for (int i : arr) cout << i << " ";
        cout << endl;
    }
    else {
        cout << "Элемент " << key << " не найден в массиве" << endl;
    }

}

