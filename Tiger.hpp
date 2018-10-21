/*********************************************************************
** Description: Specification file for the Tiger class.
*********************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger : public Animal {

private:

public:

  /***********************************************************************************************
  ** Description: Default constructor that initalizes data members for baseFoodCost, cost,
  ** numberOfBabies and payoff. Age is set to -1 by the base class constructor to indicate that
  ** this animal may not actually be a part of the zoo, although it is an element the array.
  ***********************************************************************************************/
  Tiger() : Animal() {
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
      setPayoff(getCost() / 5);
  }

  /***********************************************************************************************
  ** Description: Overloaded constructor that takes an integer to set the age of a tiger at the
  ** time when it is added to the zoo. Also sets the base food cost, cost, number of babies and
  ** payoff for tiger.
  ***********************************************************************************************/
  Tiger(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost() * 5);
      setCost(10000);
      setNumberOfBabies(1);
      setPayoff(getCost() / 5);
  }

};

#endif
