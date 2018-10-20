#include "Zoo.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

Zoo::Zoo() {
  penguins = new Penguin[10];
  setPenguinArraySize(10);
  setPenguins(0);

  tigers = new Tiger[10];
  setTigerArraySize(10);
  setTigers(0);

  turtles = new Turtle[10];
  setTurtleArraySize(10);
  setTurtles(0);

  setMoney(100000);
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

  cout << "Welcome to your zoo!" << endl;
  cout << "You have $" << getMoney() << " to populate your crappy little zoo." << endl;

  setPenguins(buyAnimalMenu.getIntChoiceFromPrompt("How many penguins would you like to buy?", 1, 2, false));
  setTigers(buyAnimalMenu.getIntChoiceFromPrompt("How many tigers would you like to buy?", 1, 2, false));
  setTurtles(buyAnimalMenu.getIntChoiceFromPrompt("How many turtles would you like to buy?", 1, 2, false));

  buyAnimalMenu.getIntChoiceFromPrompt("Select an option below to purchase a new animal today:", 1, buyAnimalMenu.getMenuChoices(), true);
  //std::cout << "Number of penguins, tigers and turtles: "
  //          << getPenguins() << ", " << getTigers() << ", " << getTurtles() << endl;

}


/***********************************************************************************************
** Description: Calls the addMenuItem function on the Zoo's Menu objects to add possible menu
** choices to vectors for the main menu, the menu of sides to select for a die,
** and the type of die.
***********************************************************************************************/
void Zoo::initMenus() {

  buyAnimalMenu.addMenuItem("Penguin ($1,000)");
  buyAnimalMenu.addMenuItem("Tiger   ($10,000)");
  buyAnimalMenu.addMenuItem("Turtle  ($100)");
  buyAnimalMenu.addMenuItem("Skip this turn");

}

Animal* Zoo::doubleArray(Animal *array, int numOfAnimals, int arraySize) {
  if (array) {

    if (numOfAnimals >= arraySize) {

      Animal *newArray = new Animal[arraySize * 2];

      for (int i = 0; i < numOfAnimals; i++) {
        newArray[i] = array[i];
      }

      delete [] array;
      return newArray;

    } else {
      return array;
    }

  }

}


void Zoo::bonusDay() {
  cout << "It's a holiday!" << endl;
  int bonus = rand() % 250 + 250;

}


void Zoo::buyAnimal(Animal *animalToBuy, int qty) {

  if (animalToBuy) {

    if (getMoney() > animalToBuy->getCost()) {
      setMoney(getMoney() - animalToBuy->getCost());
      //Update number of correct type of animal, add to array

    }

  }

}


void Zoo::feedAnimals() {

  for (int i = 0; i < numPenguins; i ++) {
    setMoney(getMoney() - penguins[i].getBaseFoodCost());
  }

  for (int i = 0; i < numTigers; i ++) {
    setMoney(getMoney() - tigers[i].getBaseFoodCost());
  }
  
  for (int i = 0; i < numTurtles; i ++) {
    setMoney(getMoney() - turtles[i].getBaseFoodCost());
  }

}


void Zoo::increaseAge() {

  for (int i = 0; i < numPenguins; i ++) {
    penguins[i].increaseAge();
  }

  for (int i = 0; i < numTigers; i ++) {
    tigers[i].increaseAge();
  }

  for (int i = 0; i < numTurtles; i ++) {
    turtles[i].increaseAge();
  }

  cout << "They grow up so fast!" << endl;
}


void Zoo::nextTurn() {
  //A day will follow this flow: Age -> Feed -> Random Event -> Payoff -> Purchase Adult
  increaseAge();
  feedAnimals();
  randomEvent();
  receivePayoff();
}


void Zoo::randomEvent() {

  int event = rand() % 3;
  cout << "Random event: " << event << endl;
  switch (event) {

    case Sickness   :
                      break;
    case Attendance : bonusDay();
                      break;
    case Birth      :
                      break;
    case Nothing    : cout << "Nothing to report today." << endl;

  }


}


void Zoo::receivePayoff() {

  for (int i = 0; i < numPenguins; i ++) {
    setMoney(getMoney() + penguins[i].getPayoff());
  }

  for (int i = 0; i < numTigers; i ++) {
    setMoney(getMoney() + tigers[i].getPayoff());
  }

  for (int i = 0; i < numTurtles; i ++) {
    setMoney(getMoney() + turtles[i].getPayoff());
  }

}


bool Zoo::isAdult(Animal *zooAnimal) {

  if (zooAnimal) {

    if (zooAnimal->getAge() >= 3) {
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


int Zoo::getPenguinArraySize() {
  return penguinArraySize;
}


void Zoo::setPenguinArraySize(int newArraySize) {
  penguinArraySize = newArraySize;
}


int Zoo::getTigerArraySize() {
  return tigerArraySize;
}


void Zoo::setTigerArraySize(int newArraySize) {
  tigerArraySize = newArraySize;
}


int Zoo::getTurtleArraySize() {
  return turtleArraySize;
}


void Zoo::setTurtleArraySize(int newArraySize) {
  turtleArraySize = newArraySize;
}
