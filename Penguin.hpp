/*********************************************************************
** Description: Specification file for the Penguin class.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal {

private:

public:
  Penguin() : Animal() {
      setBaseFoodCost(getBaseFoodCost());
      setCost(1000);
      setNumberOfBabies(5);
      setPayoff(getCost() / 10);
  }

  Penguin(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost());
      setCost(1000);
      setNumberOfBabies(5);
      setPayoff(getCost() / 10);
  }

};

#endif
