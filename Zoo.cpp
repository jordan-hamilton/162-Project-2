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

  cout << endl << "Welcome to Zoo Tycoon!" << endl;
  cout << "You have $" << getMoney() << " to populate your zoo with animals." << endl << endl;

  addAnimal(penguin, buyAnimalMenu.getIntChoiceFromPrompt("How many penguins would you like to start?", 1, 2, false), 1);
  addAnimal(tiger, buyAnimalMenu.getIntChoiceFromPrompt("How many tigers would you like to start?", 1, 2, false), 1);
  addAnimal(turtle, buyAnimalMenu.getIntChoiceFromPrompt("How many turtles would you like to start?", 1, 2, false), 1);

  do {

    cout << endl << "Day " << day << ":" << endl;
    cout << "Balance: $" << getMoney() << endl;
    day++;

  } while(getMoney() > 0 && nextTurn());

  if (getMoney() <= 0) {
    cout << endl << "You ran out of money!" << endl;
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

Animal* Zoo::validateArraySize(Animal *array, Purchase animal, int numOfAnimals, int arraySize) {

  if (array) {

    if (numOfAnimals >= arraySize) {

      Animal *newArray = nullptr;

      switch(animal) {

        case penguin : newArray = new Penguin[arraySize * 2];
                       setPenguinArraySize(arraySize * 2);
                       break;

        case tiger   : newArray = new Tiger[arraySize * 2];
                       setTigerArraySize(arraySize * 2);
                       break;

        case turtle  : newArray = new Turtle[arraySize * 2];
                       setTurtleArraySize(arraySize * 2);

                       break;

        default: {}

      }

      for (int i = 0; i < arraySize; i++) {
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

  int bonus = rand() % 251 + 250;
  setMoney(getMoney() + numTigers * bonus);

}


void Zoo::addAnimal(const Purchase &animalToAdd, const int &qty, const int &age) {

int loopCounter = 0;

  switch (animalToAdd) {

    case penguin    : setPenguins(getPenguins() + qty);
                      penguins = validateArraySize(penguins, penguin, getPenguins(), getPenguinArraySize());

                      for (int i = 0; (i < getPenguinArraySize() && loopCounter < qty); i++) {
                        cout << "Checking the age of penguin " << i << endl;
                        if (penguins[i].getAge() < 0) {
                          cout << "This penguin's age is " << penguins[i].getAge() << endl;
                          penguins[i].setAge(age);
                          cout << "We've updated the age to " << penguins[i].getAge() << endl;
                          setMoney(getMoney() - penguins[i].getCost());
                          loopCounter++;
                        }

                      }
                      cout << "We added " << loopCounter << " penguins to the zoo." << endl;
                      break;

    case tiger      : setTigers(getTigers() + qty);
                      tigers = validateArraySize(tigers, tiger, getTigers(), getTigerArraySize());

                      for (int i = 0; (i < getTigerArraySize() && loopCounter < qty); i++) {
                        cout << "Checking the age of tiger " << i << endl;
                        if (tigers[i].getAge() < 0) {
                          cout << "This tiger's age is " << tigers[i].getAge() << endl;
                          tigers[i].setAge(age);
                          cout << "We've updated the age to " << tigers[i].getAge() << endl;
                          setMoney(getMoney() - tigers[i].getCost());
                          loopCounter++;
                        }

                      }
                      cout << "We added " << loopCounter << " tigers to the zoo." << endl;
                      break;

    case turtle     : setTurtles(getTurtles() + qty);
                      turtles = validateArraySize(turtles, turtle, getTurtles(), getTurtleArraySize());

                      for (int i = 0; (i < getTurtleArraySize() && loopCounter < qty); i++) {
                        cout << "Checking the age of turtle " << i << endl;
                        if (turtles[i].getAge() < 0) {
                          cout << "This turtle's age is " << turtles[i].getAge() << endl;
                          turtles[i].setAge(age);
                          cout << "We've updated the age to " << turtles[i].getAge() << endl;
                          setMoney(getMoney() - turtles[i].getCost());
                          loopCounter++;
                        }

                      }
                      cout << "We added " << loopCounter << " turtles to the zoo." << endl;
                      break;

    default         : {}

  }

}


void Zoo::feedAnimals() {

  for (int i = 0; i < numPenguins; i++) {
    setMoney(getMoney() - penguins[i].getBaseFoodCost());
  }

  for (int i = 0; i < numTigers; i++) {
    setMoney(getMoney() - tigers[i].getBaseFoodCost());
  }

  for (int i = 0; i < numTurtles; i++) {
    setMoney(getMoney() - turtles[i].getBaseFoodCost());
  }

}


void Zoo::increaseAge() {

  for (int i = 0; i < getPenguinArraySize(); i++) {

    if (penguins[i].getAge() >= 0) {
      penguins[i].increaseAge();
      cout << "Age of penguin " << i << ": " << penguins[i].getAge() << endl;
    }

  }

  for (int i = 0; i < getTigerArraySize(); i++) {

    if (tigers[i].getAge() >= 0) {
      tigers[i].increaseAge();
      cout << "Age of tiger " << i << ": " << tigers[i].getAge() << endl;
    }

  }

  for (int i = 0; i < getTurtleArraySize(); i++) {

    if (turtles[i].getAge() >= 0) {
      turtles[i].increaseAge();
      cout << "Age of turtle " << i << ": " << turtles[i].getAge() << endl;
    }

  }

}


bool Zoo::nextTurn() {

  increaseAge();
  feedAnimals();
  randomEvent();
  receivePayoff();
  purchaseAdultPrompt();

  if (mainMenu.getIntChoiceFromPrompt("\nWhat would you like to do now?", 1, mainMenu.getMenuChoices(), true) == 1) {
    return true;
  } else {
    cout << endl << "Thanks for playing!" << endl << endl;
    return false;
  }

}


void Zoo::purchaseAdultPrompt() {

  Purchase animalToAdd = static_cast<Purchase>(buyAnimalMenu.getIntChoiceFromPrompt("Select an option below to purchase an adult animal today:", 1, buyAnimalMenu.getMenuChoices(), true));

  switch (animalToAdd) {

    case penguin    : addAnimal(penguin, 1, 3);
                      break;
    case tiger      : addAnimal(tiger, 1, 3);
                      break;
    case turtle     : addAnimal(turtle, 1, 3);
                      break;
    default         : {}

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
    default         : {}

  }


}


void Zoo::receivePayoff() {

  for (int i = 0; i < numPenguins; i++) {
    setMoney(getMoney() + penguins[i].getPayoff());
  }

  for (int i = 0; i < numTigers; i++) {
    setMoney(getMoney() + tigers[i].getPayoff());
  }

  for (int i = 0; i < numTurtles; i++) {
    setMoney(getMoney() + turtles[i].getPayoff());
  }

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
