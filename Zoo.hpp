/*********************************************************************
** Description: Specification file for the Zoo class.
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Menu.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"

enum Event { sickness, attendance, birth };
enum Choice { penguin = 1, tiger, turtle, none };

class Zoo {

private:
  Menu buyAnimalMenu, mainMenu;
  int money, numPenguins, numTigers, numTurtles,
      penguinArraySize, tigerArraySize, turtleArraySize;
  Animal *penguins, *tigers, *turtles;

  void addAnimal(const Choice &animalToAdd, const int &qty, const int &age, bool wasPurchased);

  void feedAnimals();
  void increaseAge();
  void initMenus();
  bool isAdult(Animal &zooAnimal);
  bool nextTurn();
  void purchaseAdultPrompt();
  void randomBirth();
  void randomBonus();
  void randomEvent();
  void randomSickness();
  void receivePayoff();
  Animal* validateArraySize(Animal *array, Choice animal, int numOfAnimals, int arraySize);

  int getMoney();
  void setMoney(int dollars);
  int getPenguins();
  void setPenguins(int newPenguins);
  int getTigers();
  void setTigers(int newTigers);
  int getTurtles();
  void setTurtles(int newTurtles);
  int getPenguinArraySize();
  void setPenguinArraySize(int newArraySize);
  int getTigerArraySize();
  void setTigerArraySize(int newArraySize);
  int getTurtleArraySize();
  void setTurtleArraySize(int newArraySize);

public:
  Zoo();
  ~Zoo();
  void play();

};

#endif
