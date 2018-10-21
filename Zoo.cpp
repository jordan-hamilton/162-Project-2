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

  setMoney(40000);
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

                        if (penguins[i].getAge() < 0) {
                          penguins[i].setAge(age);

                          if (wasPurchased) {
                            setMoney(getMoney() - penguins[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }

                      break;

    case tiger      : setTigers(getTigers() + qty);
                      tigers = validateArraySize(tigers, tiger, getTigers(), getTigerArraySize());

                      for (int i = 0; (i < getTigerArraySize() && qtyAdded < qty); i++) {

                        if (tigers[i].getAge() < 0) {
                          tigers[i].setAge(age);

                          if (wasPurchased) {
                            setMoney(getMoney() - tigers[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }

                      break;

    case turtle     : setTurtles(getTurtles() + qty);
                      turtles = validateArraySize(turtles, turtle, getTurtles(), getTurtleArraySize());

                      for (int i = 0; (i < getTurtleArraySize() && qtyAdded < qty); i++) {

                        if (turtles[i].getAge() < 0) {
                          turtles[i].setAge(age);

                          if (wasPurchased) {
                            setMoney(getMoney() - turtles[i].getCost());
                          }

                          qtyAdded++;
                        }

                      }

                      break;

    default         : {}

  }

}


/***********************************************************************************************
** Description: Loops through each animal array and subtracts the base food cost for each animal
** owned from the player's current money. We search for valid animals in each array by first
** confirming that the age of the animal at an index is at least 0.
***********************************************************************************************/
void Zoo::feedAnimals() {

  for (int i = 0; i < getPenguinArraySize(); i++) {

    if (penguins[i].getAge() >= 0) {
      setMoney(getMoney() - penguins[i].getBaseFoodCost());
    }

  }

  for (int i = 0; i < getTigerArraySize(); i++) {

    if (tigers[i].getAge() >= 0) {
      setMoney(getMoney() - tigers[i].getBaseFoodCost());
    }

  }

  for (int i = 0; i < getTurtleArraySize(); i++) {

    if (turtles[i].getAge() >= 0) {
      setMoney(getMoney() - turtles[i].getBaseFoodCost());
    }

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
    }

  }

  for (int i = 0; i < getTigerArraySize(); i++) {

    if (tigers[i].getAge() >= 0) {
      tigers[i].increaseAge();
    }

  }

  for (int i = 0; i < getTurtleArraySize(); i++) {

    if (turtles[i].getAge() >= 0) {
      turtles[i].increaseAge();
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
** Description: Takes a reference to an animal and calls the getAge function to determine
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


/***********************************************************************************************
** Description: Prompts the user to purchase an animal or skip their turn and not purchase an
** adult animal. If the user chooses to buy an animal, the addAnimal function is called in the
** switch statement, specifying a purchase of one of the selected animal that is 3 days old.
***********************************************************************************************/
void Zoo::purchaseAdultPrompt() {

  int animalToAdd = buyAnimalMenu.getIntChoiceFromPrompt("\nSelect an option below to purchase an adult animal today:", 1, buyAnimalMenu.getMenuChoices(), true);

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

/***********************************************************************************************
** Description: Assigns a random number between 1 and 3 to pregnantAnimal to determine which
** type of animal will have babies during this random event. Depending on the value in the
** pregnantAnimal variable, the proper array is looped through, calling the isAdult function
** until the entire array is looped through or an adult animal is found. If one is found,
** the number of babies associated with that derived class are added to the array using the
** addAnimal function. If no adults are found, no babies are born during this turn.
***********************************************************************************************/
void Zoo::randomBirth() {

  int numOfAdults = 0;

  int pregnantAnimal = rand() % 3 + 1;

  switch (pregnantAnimal) {

    case penguin    : for (int i = 0; (i < getPenguinArraySize() && numOfAdults < 1); i++) {

                        if (isAdult(penguins[i])) {

                          addAnimal(penguin, penguins[i].getNumberOfBabies(), 0, false);
                          numOfAdults++;
                          cout << penguins[i].getNumberOfBabies() << " penguins were born!" << endl;

                        }

                      }

                      break;

    case tiger      : for (int i = 0; (i < getTigerArraySize() && numOfAdults < 1); i++) {

                        if (isAdult(tigers[i])) {

                          addAnimal(tiger, tigers[i].getNumberOfBabies(), 0, false);
                          numOfAdults++;
                          cout << tigers[i].getNumberOfBabies() << " tiger was born!" << endl;

                        }

                      }

                      break;

    case turtle     : for (int i = 0; (i < getTurtleArraySize() && numOfAdults < 1); i++) {

                        if (isAdult(turtles[i])) {

                          addAnimal(turtle, turtles[i].getNumberOfBabies(), 0, false);
                          numOfAdults++;
                          cout << turtles[i].getNumberOfBabies() << " turtles were born!" << endl;

                        }

                      }

                      break;

    default         : {}

  }


}


/***********************************************************************************************
** Description: Assigns a random number between 250 and 500 to bonus to determine how much to
** of a bonus per tiger to add to the player's money during this random event. If the numTigers
** data member indicated there is at least one tiger, the result of the bonus is output to the
** screen. Then, the tigers array is looped through to find valid tigers (those with an age of
** 0 or greater) to add the bonus to the player's money for each valid tiger object.
***********************************************************************************************/
void Zoo::randomBonus() {

  int bonus = rand() % 251 + 250;

  if (getTigers() > 0) {
    cout << "Attendance increase! You collected an additional $"
         << bonus * getTigers() << " in ticket sales today." << endl;
  }

  for (int i = 0; i < getTigerArraySize(); i++) {

    if (tigers[i].getAge() >= 0) {
      setMoney(getMoney() + bonus);
    }

  }

}


void Zoo::randomEvent() {

  int event = rand() % 4;

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


/***********************************************************************************************
** Description: Assigns a random number between 1 and 3 to sickAnimal to determine which
** type of animal will become sick during this random event. Depending on the value in the
** sickAnimal variable, the switch statement checks that there is at least one of this type of
** animal, then sets the age of the last valid animal in the array to an invalid value (-1).
** The numPenguins, numTigers or numTurtles data member is decremented by one with a setter
** function and the result is output to the screen.
***********************************************************************************************/
void Zoo::randomSickness() {

  int sickAnimal = rand() % 3 + 1;

  switch (sickAnimal) {

    case penguin    : if (getPenguins() > 0) {

                        penguins[getPenguins() - 1].setAge(-1);
                        setPenguins(getPenguins() - 1);
                        cout << "A penguin has died!" << endl;

                      }

                      break;

    case tiger      : if (getTigers() > 0) {

                        tigers[getTigers() - 1].setAge(-1);
                        setTigers(getTigers() - 1);
                        cout << "A tiger has died!" << endl;

                      }

                      break;

    case turtle     : if (getTurtles() > 0) {

                        turtles[getTurtles() - 1].setAge(-1);
                        setTurtles(getTurtles() - 1);
                        cout << "A turtle has died!" << endl;

                      }

                      break;

    default         : {}

  }


}


void Zoo::receivePayoff() {

  for (int i = 0; i < getPenguinArraySize(); i++) {

    if (penguins[i].getAge() >= 0) {
      setMoney(getMoney() + penguins[i].getPayoff());
    }

  }

  for (int i = 0; i < getTigerArraySize(); i++) {

    if (tigers[i].getAge() >= 0) {
      setMoney(getMoney() + tigers[i].getPayoff());
    }

  }

  for (int i = 0; i < getTurtleArraySize(); i++) {

    if (turtles[i].getAge() >= 0) {
      setMoney(getMoney() + turtles[i].getPayoff());
    }

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
