/*********************************************************************
** Description: Specification file for the Turtle class.
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal {

private:

public:
  Turtle() : Animal() {
      setBaseFoodCost(getBaseFoodCost() / 2);
      setCost(100);
      setNumberOfBabies(10);
      setPayoff(getCost() / 20);
  }

  Turtle(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost() / 2);
      setCost(100);
      setNumberOfBabies(10);
      setPayoff(getCost() / 20);
  }

};

#endif
