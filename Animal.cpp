#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
  setAge(1);
  setBaseFoodCost(10);
}


Animal::Animal(int daysOld) {
  setAge(daysOld);
  setBaseFoodCost(10);
}

Animal::~Animal() {

}


void Animal::increaseAge() {
  setAge(getAge() + 1);
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
