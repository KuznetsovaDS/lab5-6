#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("chcp 1251");
    ofstream out("poem.txt");
    if (!out) {
        cout << "невозможно открыть файл для записи";
        return 1;
    }

    string line;
    cout << "Введите стихотворение " << endl;
    while (true) {
        getline(cin, line);
        if (line.empty()) break; 
        out << line << endl;
    }
    out.close();

    ifstream in("poem.txt");
    if (!in) {
        cout << "невозможно открыть файл для чтения\n";
        return 1;
    }

    cout << "\ncодержимое файла " << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();

}