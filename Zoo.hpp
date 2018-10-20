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

enum Event { Sickness, Attendance, Birth, Nothing };

class Zoo {

private:
  Menu buyAnimalMenu;
  int money, numPenguins, numTigers, numTurtles,
      penguinArraySize, tigerArraySize, turtleArraySize;
  Animal *penguins, *tigers, *turtles;
  void initMenus();
  Animal* doubleArray(Animal *array, int numOfAnimals, int arraySize);

  void bonusDay();
  void buyAnimal(Animal* animalToBuy, int qty);
  void feedAnimals();
  void increaseAge();
  void nextTurn();
  void randomEvent();
  void receivePayoff();

  bool isAdult(Animal *zooAnimal);
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
