#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[]) {
    system("chcp 1251");
    if (argc != 4) {
        cerr << "недостаточно аргументов\n";
        return 1;
    }
    string flag = argv[1];
    int num1 = stoi(argv[2]);
    int num2 = stoi(argv[3]);

    if (flag == "-a") {
        cout << "сумма " << num1 + num2 << endl;
    }
    else if (flag == "-m") {
        cout << "произведение " << num1 * num2 << endl;
    }
    else {
        cerr << "неправильный флаг\n";
        return 1;
    }
    return 0;
}