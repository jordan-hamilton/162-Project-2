/*********************************************************************
** Description: Specification file for the Tiger class.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"
#include <iostream>

class Tiger : public Animal {

private:

public:
  Tiger() : Animal() {
      std::cout << "Fierce." << std::endl;
      std::cout << "Cost for tiger: " << cost << std::endl;
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
  }

  Tiger(int daysOld) : Animal(daysOld) {
      std::cout << "Fierce and older." << std::endl;
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
  }
};

#endif
