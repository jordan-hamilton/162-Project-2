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

  addAnimal(penguin, buyAnimalMenu.getIntChoiceFromPrompt("How many penguins would you like to start?", 1, 2, false), 1, true);
  addAnimal(tiger, buyAnimalMenu.getIntChoiceFromPrompt("How many tigers would you like to start?", 1, 2, false), 1, true);
  addAnimal(turtle, buyAnimalMenu.getIntChoiceFromPrompt("How many turtles would you like to start?", 1, 2, false), 1, true);

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


void Zoo::addAnimal(const Choice &animalToAdd, const int &qty, const int &age, bool wasPurchased) {

int qtyAdded = 0;

  switch (animalToAdd) {

    case penguin    : setPenguins(getPenguins() + qty);
                      penguins = validateArraySize(penguins, penguin, getPenguins(), getPenguinArraySize());

                      for (int i = 0; (i < getPenguinArraySize() && qtyAdded < qty); i++) {
                        cout << "Checking the age of penguin " << i << endl;
                        if (penguins[i].getAge() < 0) {
                          cout << "This penguin's age is " << penguins[i].getAge() << endl;
                          penguins[i].setAge(age);
                          cout << "We've updated the age to " << penguins[i].getAge() << endl;

                          if (wasPurchased) {
                            setMoney(getMoney() - penguins[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }
                      cout << "We added " << qtyAdded << " penguins to the zoo." << endl;
                      break;

    case tiger      : setTigers(getTigers() + qty);
                      tigers = validateArraySize(tigers, tiger, getTigers(), getTigerArraySize());

                      for (int i = 0; (i < getTigerArraySize() && qtyAdded < qty); i++) {
                        cout << "Checking the age of tiger " << i << endl;
                        if (tigers[i].getAge() < 0) {
                          cout << "This tiger's age is " << tigers[i].getAge() << endl;
                          tigers[i].setAge(age);
                          cout << "We've updated the age to " << tigers[i].getAge() << endl;

                          if (wasPurchased) {
                            setMoney(getMoney() - tigers[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }
                      cout << "We added " << qtyAdded << " tigers to the zoo." << endl;
                      break;

    case turtle     : setTurtles(getTurtles() + qty);
                      turtles = validateArraySize(turtles, turtle, getTurtles(), getTurtleArraySize());

                      for (int i = 0; (i < getTurtleArraySize() && qtyAdded < qty); i++) {
                        cout << "Checking the age of turtle " << i << endl;
                        if (turtles[i].getAge() < 0) {
                          cout << "This turtle's age is " << turtles[i].getAge() << endl;
                          turtles[i].setAge(age);
                          cout << "We've updated the age to " << turtles[i].getAge() << endl;

                          if (wasPurchased) {
                            setMoney(getMoney() - turtles[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }
                      cout << "We added " << qtyAdded << " turtles to the zoo." << endl;
                      break;

    default         : {}

  }

}


/***********************************************************************************************
** Description: Loops through each array and subtracts the player's current money by the base
** food cost for each of the owned animals owned. We're assuming all animals of the same derived
** class have the same base food cost, so we're not conditionally subtracting the cost by only
** searching for valid animals in the arrays with ages of 0 or greater. Instead, we subtract
** according to the number of animals we've tracked with numPenguins, numTigers, and numTurtles.
***********************************************************************************************/
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


/***********************************************************************************************
** Description: Loops through each array and calls the Animal object's increaseAge function
** to increment the age by one day, if the age of the animal at an index is a valid value
** (0 or older).
***********************************************************************************************/
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


/***********************************************************************************************
** Description: Calls the addMenuItem function on the Zoo's Menu objects to add possible menu
** choices to vectors for the menu to purchase animals and the menu to continue playing or quit
** at the end of each turn.
***********************************************************************************************/
void Zoo::initMenus() {

  buyAnimalMenu.addMenuItem("Penguin ($1,000)");
  buyAnimalMenu.addMenuItem("Tiger   ($10,000)");
  buyAnimalMenu.addMenuItem("Turtle  ($100)");
  buyAnimalMenu.addMenuItem("Skip this turn");

  mainMenu.addMenuItem("Continue playing");
  mainMenu.addMenuItem("Quit");

}


/***********************************************************************************************
** Description: Takes a reference to an animal and calls its getAge function to determine
** whether or not this animal is an adult and can have babies. Returns a boolean, with true
** indicating that the animal is an adult.
***********************************************************************************************/
bool Zoo::isAdult(Animal &zooAnimal) {

  if (zooAnimal.getAge() >= 3) {
      return true;
    } else {
      return false;
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

  int animalToAdd = buyAnimalMenu.getIntChoiceFromPrompt("Select an option below to purchase an adult animal today:", 1, buyAnimalMenu.getMenuChoices(), true);

  switch (animalToAdd) {

    case penguin    : addAnimal(penguin, 1, 3, true);
                      break;
    case tiger      : addAnimal(tiger, 1, 3, true);
                      break;
    case turtle     : addAnimal(turtle, 1, 3, true);
                      break;
    default         : {}

  }

}


void Zoo::randomBirth() {
  cout << "Someone's having babies!" << endl;
}


void Zoo::randomBonus() {

  int bonus = rand() % 251 + 250;
  setMoney(getMoney() + numTigers * bonus);

}


void Zoo::randomEvent() {

  int event = rand() % 4;
  cout << "Random event: " << event << endl;
  switch (event) {

    case sickness   : randomSickness();
                      break;
    case attendance : randomBonus();
                      break;
    case birth      : randomBirth();
                      break;
    default         : {}

  }


}


void Zoo::randomSickness() {

  int sickAnimal = rand() % 3 + 1;

  switch (sickAnimal) {

    case penguin    : penguins[getPenguins() - 1].setAge(-1);
                      setPenguins(getPenguins() - 1);
                      cout << "A penguin just died!" << endl;
                      break;

    case tiger      : tigers[getTigers() - 1].setAge(-1);
                      setTigers(getTigers() - 1);
                      cout << "A tiger just died!" << endl;
                      break;

    case turtle     : turtles[getTurtles() - 1].setAge(-1);
                      setTurtles(getTurtles() - 1);
                      cout << "A turtle just died!" << endl;
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


Animal* Zoo::validateArraySize(Animal *array, Choice animal, int numOfAnimals, int arraySize) {

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
