/*********************************************************************
** Description: Specification file for the Tiger class.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal {

private:

public:
  Tiger() : Animal() {
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
      setPayoff(getCost() / 5);
  }

  Tiger(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
      setPayoff(getCost() / 5);
  }

};

#endif
