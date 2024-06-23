#include "a.h"

void editFile::readMyFile(){
    ifstream MyFile(filename + ".txt");
    if (MyFile.is_open()){
        while (getline(MyFile, line)) {
            cout << line << endl;
        }
    }
    else{
        cout << "Не получилось открыть файл" << endl;
    }
}

void editFile::add_to_end(){
    ofstream MyFile(filename + ".txt", std::ios_base::app);
    if (MyFile.is_open()){
        cout << "Введите строку, которую хотите добавить в конец файла: ";
        getline(cin, line);
        cout << endl;
        MyFile << endl << line;
    }
    else cout << "Не получилось открыть файл" << endl;
}


void editFile::make_new_file(){
    int firstEven = 1;
    ifstream MyFile(filename + ".txt");
    if (MyFile.is_open()){
        while (getline(MyFile, line)){
            if (firstEven == 1 && stoi(line) % 2 == 0) firstEven = stoi(line);
            lines.push_back(stoi(line));
        }
        MyFile.close();
    }
    else cout << "Не получилось открыть файл" << endl;
    ofstream newFile("newFile.txt");
    if (newFile.is_open()){
        for (int i = 0; i < lines.size(); i++){
            newFile << lines[i] + firstEven;
            if (i != lines.size() - 1) newFile << endl;
        }
    }
}
