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
  int money;
  Penguin * penguins;
  Tiger* tigers;
  Turtle* turtles;


public:
  Zoo();
  int getMoney();
  void setMoney(int dollars);

};

#endif
