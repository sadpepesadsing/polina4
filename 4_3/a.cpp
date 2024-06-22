#include "a.h"

void base::read_bin(){
    store new_goods;
    ifstream file(fileNameBin, ios::binary);
    if (file.is_open()){
        cout << endl << "Записи в файле .bin" << endl << "----------------------------" << endl;
        while (file.read(reinterpret_cast<char*>(&new_goods), sizeof(new_goods))) {
            cout << "Код: " << new_goods.code << endl;
            cout << "Количество проданных: " << new_goods.amount << endl;
            cout << "Цена: " << new_goods.price << endl << endl;
        }
        cout << endl << "----------------------------" << endl;
    }
    else{
        cout << "Файл не найден" << endl;
    }
    file.close();
}

void base::to_add(){
    store new_goods;
    cout << "\nВведите код товара: ";
    cin >> new_goods.code;
    cout << "Введите название товара: ";
    cin >> new_goods.name;
    cout << "Введите цену товара: ";
    cin >> new_goods.price;
    cout << "Введите дату прождажи товара: ";
    cin >> new_goods.date;
    goods.push_back(new_goods);
}

void base::write_txt(){
    ofstream file(fileNameTxt, ios::app);
    if (file.is_open()){
        for (int i = 0; i < goods.size(); i++){
            file << goods[i].code << endl << goods[i].name << endl << goods[i].price << endl << goods[i].date << endl;
        }
    }
    else{
        cout << "Файл не найден" << endl;
    }
    file.close();
}

void base::write_bin(){
    vector<string> codes;
    store new_goods;
    int amount;
    read_txt();
    ofstream file(fileNameBin, ios::binary);
    if (file.is_open()){
        for (auto& i : goods){
            amount = 0;
            bool is_in = false;

            for (auto& j : codes){ // проверяем записывали ли мы товар в файл
                if (i.code == j){
                    is_in = true;
                    break;
                }
            }
          
            if (!is_in){
                codes.push_back(i.code);
              
                for (auto& j : goods){ // считаем количество товаров
                    if (strcmp(i.code, j.code) == 0){
                        amount++;
                    }
                }

                for (int j = 0; j < 50; j++){
                    new_goods.code[j] = i.code[j];
                }
                new_goods.amount = amount;
                new_goods.price = i.price;
                
                file.write(reinterpret_cast<const char*>(&new_goods), sizeof(new_goods));
            }
      
        }
    }
    else{
        cout << "Файл не найден" << endl;
    }
    file.close();
}


void base::read_txt(){
    ifstream file(fileNameTxt);
    if (file.is_open()){
        store new_goods;
        while (file >> new_goods.code >> new_goods.name >> new_goods.price >> new_goods.date){
        goods.push_back(new_goods);
        }
    }
    else{
        cout << "Файл не найден" << endl;
    }
    file.close();
}

void base::sales_per_day(){
    string date1;
    cout << "\nВведите дату, чтобы узнать сумму выручки: ";
    cin >> date1;
    read_txt();
    int sum = 0;
    for (int i = 0; i < goods.size(); i++){
        if (goods[i].date == date1){
            sum += goods[i].price;
        }
    }
    if (sum == 0) cout << "Похоже, что это был трудный день :( выручка равна нулю" << endl;
    else cout << "Выручка за " << date1 << " составила: " << sum/2 << endl;
}

void base::total_sales(){
    ifstream file(fileNameBin, ios::binary);
    if (file.is_open()){
        int sum = 0;
        store new_goods;
        while (file.read(reinterpret_cast<char*>(&new_goods), sizeof(new_goods))) {
            sum += new_goods.amount * new_goods.price;
        }
        cout << endl << "Выручка за все время составила: " << sum << endl;
    }
}
