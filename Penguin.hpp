/*********************************************************************
** Description: Specification file for the Penguin class.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin : public Animal {

private:

public:

  /***********************************************************************************************
  ** Description: Default constructor that initalizes data members for baseFoodCost, cost,
  ** numberOfBabies and payoff. Age is set to -1 by the base class constructor to indicate that
  ** this animal may not actually be a part of the zoo, although it is an element the array.
  ***********************************************************************************************/
  Penguin() : Animal() {
      setBaseFoodCost(getBaseFoodCost());
      setCost(1000);
      setNumberOfBabies(5);
      setPayoff(getCost() / 10);
  }

  /***********************************************************************************************
  ** Description: Overloaded constructor that takes an integer to set the age of a tiger at the
  ** time when it is added to the zoo. Also sets the base food cost, cost, number of babies and
  ** payoff for tigers.
  ***********************************************************************************************/
  Penguin(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost());
      setCost(1000);
      setNumberOfBabies(5);
      setPayoff(getCost() / 10);
  }

};

#endif
