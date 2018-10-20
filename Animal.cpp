#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
  std::cout << "Hi Feline." << std::endl;
  setAge(1);
  setBaseFoodCost(10);
}


Animal::Animal(int daysOld) {
  std::cout << "Hi Felicia." << std::endl;
  setAge(daysOld);
  setBaseFoodCost(10);
}

Animal::~Animal() {
  std::cout << "Bye Felicia." << std::endl;
}


int Animal::getAge() {
  return age;
}


void Animal::setAge(int daysOld) {
  age = daysOld;
}


int Animal::getBaseFoodCost() {
  return baseFoodCost;
}


void Animal::setBaseFoodCost(int dollars) {
  baseFoodCost = dollars;
}


int Animal::getCost() {
  return cost;
}


void Animal::setCost(int dollars) {
  cost = dollars;
}


int Animal::getNumberOfBabies() {
  return numberOfBabies;
}


void Animal::setNumberOfBabies(int babies) {
  numberOfBabies = babies;
}


int Animal::getPayoff() {
  return payoff;
}


void Animal::setPayoff(int pay) {
  payoff = pay;
}
