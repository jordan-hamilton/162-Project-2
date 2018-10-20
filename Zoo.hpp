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

class Zoo {

private:
  Menu buyAnimalMenu;
  int money, numPenguins, numTigers, numTurtles;
  Animal *penguins, *tigers, *turtles;
  void initMenus();

  void buyAnimal();
  void nextTurn();
  void randomEvent();

  bool isAdult(Animal *zooAnimal);
  int getMoney();
  void setMoney(int dollars);
  int getPenguins();
  void setPenguins(int newPenguins);
  int getTigers();
  void setTigers(int newTigers);
  int getTurtles();
  void setTurtles(int newTurtles);

public:
  Zoo();
  ~Zoo();
  void play();

};

#endif
