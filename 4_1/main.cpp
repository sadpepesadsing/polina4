#include <iostream>
#include "a.h"

int main() {
  
  car firstCar; // задаем в консоли
  car secondCar("qwerty");
  
  bicycle firstBicycle; // задаем в консоли
  bicycle secondBicycle("asdfgh");
  
  storage storage; // хранилище 
  
  firstCar.turn(); // поворачиваем только первую машину и первый велосипед
  firstBicycle.turn();
  
  // добавляем трансорт в хранилище
  storage.addCar(firstCar);
  storage.addCar(secondCar);
  storage.addBicycle(firstBicycle);
  storage.addBicycle(secondBicycle);

  // сохраняем
  storage.save();
}
