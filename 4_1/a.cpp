#include "a.h"

string vehicle::getName(){
  return name;
}

void car::turn(){
  cout << "Повернуть машину: (1 - право, 2 - лево)" << endl;
  int turn;
  cin >> turn;
  if (turn == 1) rotation = "The car is turning right";
  else rotation = "The car is turning left";
}

void bicycle::turn(){
  cout << "Повернуть велосипед: (1 - право, 2 - лево)" << endl;
  int turn;
  cin >> turn;
  if (turn == 1) rotation = "The bicycle is turning right";
  else rotation = "The bicycle is turning left";
}

string car::getRotation(){
    return rotation;
}

string bicycle::getRotation(){
  return rotation;
}

void storage::addCar(car newCar){
  cars.push_back(newCar);
}

void storage::addBicycle(bicycle newBicycle){
  bicycles.push_back(newBicycle);
}

void storage::save(){
  ofstream file("storage.txt");
  file << "Cars:" << endl;
  for (int i = 0; i < cars.size(); i++){
    file << "Car name: " << cars[i].getName() << endl;
    file << "Rotation: " << cars[i].getRotation() << endl;
  }
  file << "--------------------------" << endl;
  file << "Bicycles:" << endl;
  for (int i = 0; i < bicycles.size(); i++){
    file << "Bicycle name: " << bicycles[i].getName() << endl;
    file << "Rotation: " << bicycles[i].getRotation() << endl;
  }
  file.close();
}
