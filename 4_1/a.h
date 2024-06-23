#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class vehicle{
protected:
    string name;
public:
    vehicle(string newName){
        name = newName;
    }
    vehicle(){
        cout << "Введите название транспорта\n";
        cin >> name;
    }
    vehicle(const vehicle& other){
        name = other.name;
    }
    virtual ~vehicle() {}
    virtual void turn() = 0; // поворот транспорта (=0, так как нет определения метода в базовом классе)
    virtual string getRotation() = 0; // виртуальный геттер на поле rotation в car и bicycle
    string getName(); // геттер на поле name
};

class car : public vehicle{
private:
    string rotation = "The car didn't turn";
public:
    car(string newName) : vehicle(newName){}
    car(const car& other) : vehicle(other){
        rotation = other.rotation;
    }
    car() : vehicle(){}
    ~car() override{}
    void turn() override;
    string getRotation() override;
};

class bicycle : public vehicle{
private:
    string rotation = "The bicycle didn't turn";
public:
    bicycle(string newName) : vehicle(newName){}
    bicycle(const bicycle& other) : vehicle(other){
        rotation = other.rotation;
    }
    bicycle() : vehicle(){}
    ~bicycle() override{}
    void turn() override;
    string getRotation() override;
};

class storage{
private:
    vector<bicycle> bicycles;
    vector<car> cars;
public:
    void addBicycle(bicycle newBicycle);
    void addCar(car newCar);
    void save(); // сохранить в файл 
};
