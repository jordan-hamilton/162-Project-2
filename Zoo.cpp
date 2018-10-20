#include "Zoo.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

Zoo::Zoo() {
  penguins = new Penguin[10];
  tigers = new Tiger[10];
  turtles = new Turtle[10];
  initMenus();
}


Zoo::~Zoo() {
  delete [] penguins;
  delete [] tigers;
  delete [] turtles;
}


void Zoo::play() {

  unsigned seed = time(0);
  srand(seed);

  cout << "Welcome to your zoo!" endl;

  setPenguins(buyAnimalMenu.getIntChoiceFromPrompt("How many penguins would you like to buy?", 1, 2, false));
  setTigers(buyAnimalMenu.getIntChoiceFromPrompt("How many tigers would you like to buy?", 1, 2, false));
  setTurtles(buyAnimalMenu.getIntChoiceFromPrompt("How many turtles would you like to buy?", 1, 2, false));
  
  std::cout << "Number of penguins, tigers and turtles: " << getPenguins() << ", " << getTigers() << ", " << getTurtles();

}


/***********************************************************************************************
** Description: Calls the addMenuItem function on the Zoo's Menu objects to add possible menu
** choices to vectors for the main menu, the menu of sides to select for a die,
** and the type of die.
***********************************************************************************************/
void Zoo::initMenus() {

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
