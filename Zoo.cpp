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

  int day = 1;
  unsigned seed = time(0);
  srand(seed);

  cout << "Welcome to Zoo Tycoon!" << endl;
  cout << "You have $" << getMoney() << " to populate your zoo with animals." << endl;

  addAnimal(penguin, buyAnimalMenu.getIntChoiceFromPrompt("How many penguins would you like to start?", 1, 2, false), 1);
  addAnimal(tiger, buyAnimalMenu.getIntChoiceFromPrompt("How many tigers would you like to start?", 1, 2, false), 1);
  addAnimal(turtle, buyAnimalMenu.getIntChoiceFromPrompt("How many turtles would you like to start?", 1, 2, false), 1);

  do {
    cout << endl << "Day " << day << ":" << endl;
    day++;
    // displayStats?
  } while(getMoney() > 0 && nextTurn());

  if (getMoney() <= 0) {
    cout << "You ran out of money!" << endl;
    cout << "Thanks for playing!" << endl;
  }

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

  mainMenu.addMenuItem("Continue playing");
  mainMenu.addMenuItem("Quit");

}

Animal* Zoo::checkArraySize(Animal *array, int numOfAnimals, int arraySize) {
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

  int bonus = rand() % 251 + 250;
  cout << "Your bonus is $" << bonus << " per tiger for the day." << endl;
  cout << "Your balance was $" << getMoney() << endl;
  setMoney(getMoney() + numTigers * bonus);

  cout << "It's now $" << getMoney() << endl;
}


void Zoo::addAnimal(Purchase animalToAdd, int qty, int age) {

  int loopCounter = 0;

  switch (animalToAdd) {

    case penguin    : setPenguins(getPenguins() + qty);
                      checkArraySize(penguins, getPenguins(), getPenguinArraySize());
                      do {

                        loopCounter++;
                      } while(loopCounter < qty);
                      break;
    case tiger      : setTigers(getTigers() + qty);
                      checkArraySize(tigers, getTigers(), getTigerArraySize());
                      break;
    case turtle     : setTurtles(getTurtles() + qty);
                      checkArraySize(turtles, getTurtles(), getTurtleArraySize());
                      break;
    case none       : cout << "Nothing interesting happened today." << endl;

  }
  //if (getMoney() > animalToAdd.getCost()) {
  //    setMoney(getMoney() - animalToAdd.getCost());
      //Update number of correct type of animal, add to array
  //}

}


void Zoo::feedAnimals() {
  cout << "Before feeding the penguins, you had $" << getMoney() << endl;
  for (int i = 0; i < numPenguins; i++) {
    setMoney(getMoney() - penguins[i].getBaseFoodCost());
  }
  cout << "After feeding the penguins, you now have $" << getMoney() << endl;

  for (int i = 0; i < numTigers; i++) {
    setMoney(getMoney() - tigers[i].getBaseFoodCost());
  }

  cout << "After feeding the tigers, you now have $" << getMoney() << endl;

  for (int i = 0; i < numTurtles; i++) {
    setMoney(getMoney() - turtles[i].getBaseFoodCost());
  }

  cout << "After feeding the turtles, you now have $" << getMoney() << endl;

}


void Zoo::increaseAge() {

  for (int i = 0; i < penguinArraySize; i++) {

    if (penguins[i].getAge() >= 0) {
      penguins[i].increaseAge();
      cout << "Age of penguin " << i << ": " << penguins[i].getAge() << endl;
    }

  }

  for (int i = 0; i < tigerArraySize; i++) {

    if (tigers[i].getAge() >= 0) {
      tigers[i].increaseAge();
      cout << "Age of tiger " << i << ": " << tigers[i].getAge() << endl;
    }

  }

  for (int i = 0; i < turtleArraySize; i++) {

    if (turtles[i].getAge() >= 0) {
      turtles[i].increaseAge();
      cout << "Age of turtle " << i << ": " << turtles[i].getAge() << endl;
    }

  }

  cout << "They grow up so fast!" << endl;
}


bool Zoo::nextTurn() {
  //A day will follow this flow: Age -> Feed -> Random Event -> Payoff -> Purchase Adult
  increaseAge();
  feedAnimals();
  randomEvent();
  receivePayoff();
  purchaseAdultPrompt();

  if (mainMenu.getIntChoiceFromPrompt("\nWhat would you like to do now?", 1, mainMenu.getMenuChoices(), true) == 1) {
    return true;
  } else {
    cout << "Thanks for playing!" << endl;
    return false;
  }

}


void Zoo::purchaseAdultPrompt() {

  Purchase animalToAdd = static_cast<Purchase>(buyAnimalMenu.getIntChoiceFromPrompt("Select an option below to purchase a new animal today:", 1, buyAnimalMenu.getMenuChoices(), true));

  switch (animalToAdd) {

    case penguin    : cout << "Someone's buying a penguin!" << endl;
                      addAnimal(penguin, 1, 3);
                      break;
    case tiger      : cout << "Someone's buying a tiger!" << endl;
                      addAnimal(tiger, 1, 3);
                      break;
    case turtle     : cout << "Someone's buying a turtle!" << endl;
                      addAnimal(turtle, 1, 3);
                      break;
    case none       : cout << "We didn't want more animals caged up anyway." << endl;

  }
}


void Zoo::randomEvent() {

  int event = rand() % 4;
  cout << "Random event: " << event << endl;
  switch (event) {

    case sickness   : cout << "Someone's gonna die today." << endl;
                      break;
    case attendance : bonusDay();
                      break;
    case birth      : cout << "Someone has baby fever!" << endl;
                      break;
    case nothing    : cout << "Nothing interesting happened today." << endl;

  }


}


void Zoo::receivePayoff() {

  cout << "Your balance was $" << getMoney() << endl;

  cout << "It's now $" << getMoney() << endl;
  for (int i = 0; i < numPenguins; i++) {
    setMoney(getMoney() + penguins[i].getPayoff());
  }

  cout << "With the penguin payoff, your balance is now $" << getMoney() << endl;

  for (int i = 0; i < numTigers; i++) {
    setMoney(getMoney() + tigers[i].getPayoff());
  }

  cout << "With the tiger payoff, your balance is now $" << getMoney() << endl;

  for (int i = 0; i < numTurtles; i++) {
    setMoney(getMoney() + turtles[i].getPayoff());
  }

  cout << "With the turtle payoff, your balance is now $" << getMoney() << endl;

}


bool Zoo::isAdult(Animal &zooAnimal) {

  if (zooAnimal.getAge() >= 3) {
      return true;
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
