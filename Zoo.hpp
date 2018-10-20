/*********************************************************************
** Description: Specification file for the Zoo class.
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Animal.hpp"
#include "Penguin.hpp"
#include "Tiger.hpp"
#include "Turtle.hpp"

class Zoo {

private:
  int money, numPenguins, numTigers, numTurtles;
  Animal *penguins, *tigers, *turtles;
  int getMoney();
  void setMoney(int dollars);
  int getPenguins();
  void setPenguins(int newPenguins);
  int getTigers();
  void setTigers(int newTigers);
  int getTurtles();
  void setTurtles(int newTurtles);
  bool isAdult(Animal *zooAnimal);

public:
  Zoo();
  ~Zoo();
  void play();

};

#endif
