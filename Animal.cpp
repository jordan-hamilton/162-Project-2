#include "Animal.hpp"


/***********************************************************************************************
** Description: Default constructor that initalizes data members for age and baseFoodCost.
** Age is set to -1 to indicate that this animal may not actually be a part of the zoo, although
** it is an element the array.
***********************************************************************************************/
Animal::Animal() {
  setAge(-1);
  setBaseFoodCost(90);
}


/***********************************************************************************************
** Description: Overloaded constructor that takes an integer to set the age of an animal at the
** time when it is added to the zoo. Also sets the base food cost for animals.
***********************************************************************************************/
Animal::Animal(int daysOld) {
  setAge(daysOld);
  setBaseFoodCost(90);
}


/***********************************************************************************************
** Description: Increments the current age of an animal by one.
***********************************************************************************************/
void Animal::increaseAge() {
  setAge(getAge() + 1);
}


/***********************************************************************************************
** Description: Returns an integer with the age of an animal.
***********************************************************************************************/
int Animal::getAge() {
  return age;
}


/***********************************************************************************************
** Description: Takes an integer to set the age of an animal.
***********************************************************************************************/
void Animal::setAge(int daysOld) {
  age = daysOld;
}


/***********************************************************************************************
** Description: Returns an integer with the cost of an animal's food.
***********************************************************************************************/
int Animal::getBaseFoodCost() {
  return baseFoodCost;
}


/***********************************************************************************************
** Description: Takes an integer to set the daily cost of feeding an animal.
***********************************************************************************************/
void Animal::setBaseFoodCost(int dollars) {
  baseFoodCost = dollars;
}


/***********************************************************************************************
** Description: Returns an integer with the cost of purchasing an animal.
***********************************************************************************************/
int Animal::getCost() {
  return cost;
}


/***********************************************************************************************
** Description: Takes an integer to set the cost of purchasing an animal.
***********************************************************************************************/
void Animal::setCost(int dollars) {
  cost = dollars;
}


/***********************************************************************************************
** Description: Returns an integer with the number of babies an adult animal has.
***********************************************************************************************/
int Animal::getNumberOfBabies() {
  return numberOfBabies;
}


/***********************************************************************************************
** Description: Takes an integer to set the number of babies an adult animal has.
***********************************************************************************************/
void Animal::setNumberOfBabies(int babies) {
  numberOfBabies = babies;
}


/***********************************************************************************************
** Description: Returns an integer with the daily payoff for an animal.
***********************************************************************************************/
int Animal::getPayoff() {
  return payoff;
}


/***********************************************************************************************
** Description: Takes an integer to set the daily payoff for having an animal.
***********************************************************************************************/
void Animal::setPayoff(int pay) {
  payoff = pay;
}
