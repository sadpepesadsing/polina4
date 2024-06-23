#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

using namespace std;

class editFile{
private:
    string filename; // имя a.txt
    string line; // строка из файла
    vector<int> lines; // вектор строк из файла
public:
    editFile(string filename) : filename(filename) {}
    editFile() {
        cout << "Введите имя существующего файла (без .txt): ";
        cin >> filename;
        cin.ignore();
    }
    ~editFile() {}
    void readMyFile(); // чтение файла
    void add_to_end(); // добавление строки в конец файла a.txt
    void make_new_file(); // создать новый файл newFile.txt, прибавив к каждой строке первое четное число из a.txt
};
