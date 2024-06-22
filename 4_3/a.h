#pragma once 
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class store{
public:
  char code[50];
  char name[50];
  int price;
  char date[50];
  int amount;
};

class base{
private:
  vector<store> goods;
  string fileNameTxt;
  string fileNameBin;
public:
  base(){
    cout << "Введите имя файла (без .txt): ";
    cin >> fileNameTxt;
    fileNameTxt += ".txt";
    cout << "Введите имя файла (без .bin): ";
    cin >> fileNameBin;
    fileNameBin += ".bin";
  }
  base(string filename1, string filename2){
    fileNameTxt = filename1;
    fileNameBin = filename2;
  }
  ~base(){
    goods.clear();
  }
  void read_bin(); // прочитать бинарный файл
  void write_bin(); // записать товары (второй пункт) в бинарный файл
  void read_txt(); // взять товары из тхт и записать их в goods
  void write_txt(); // записать в тхт файл
  void to_add(); // добавить товар в goods
  void sales_per_day(); // вывести выручку за определенный день
  void total_sales(); // вывести общую выручку
};
