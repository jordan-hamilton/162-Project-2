#include "Zoo.hpp"

Zoo::Zoo() {
  penguins = new Penguin[10];
  tigers = new Tiger[10];
  turtles = new Turtle[10];
}


Zoo::~Zoo() {
  delete penguins;
  delete tigers;
  delete turtles;
}


int Zoo::getMoney() {
  return money;
}


void Zoo::setMoney(int dollars) {
  money = dollars;
}


int Zoo::getPenguins() {
  return numPenguins;
}


void Zoo::setPenguins(int newPenguins) {
  numPenguins = newPenguins;
}


int Zoo::getTigers() {
  return numTigers;
}


void Zoo::setTigers(int newTigers) {
  numTigers = newTigers;
}


int Zoo::getTurtles() {
  return numTurtles;
}

void Zoo::setTurtles(int newTurtles) {
  numTurtles = newTurtles;
}


bool Zoo::isAdult(Animal *zooAnimal) {

  if (zooAnimal) {

    if (zooAnimal->getAge() > 2) {

      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }

}
