/*********************************************************************
** Description: Specification file for the Turtle class.
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle : public Animal {

private:

public:

  /***********************************************************************************************
  ** Description: Default constructor that initalizes data members for baseFoodCost, cost,
  ** numberOfBabies and payoff. Age is set to -1 by the base class constructor to indicate that
  ** this animal may not actually be a part of the zoo, although it is an element the array.
  ***********************************************************************************************/
  Turtle() : Animal() {
      setBaseFoodCost(getBaseFoodCost() / 2);
      setCost(100);
      setNumberOfBabies(10);
      setPayoff(getCost() / 20);
  }


  /***********************************************************************************************
  ** Description: Overloaded constructor that takes an integer to set the age of a turtle at the
  ** time when it is added to the zoo. Also sets the base food cost, cost, number of babies and
  ** payoff for turtles.
  ***********************************************************************************************/
  Turtle(int daysOld) : Animal(daysOld) {
      setBaseFoodCost(getBaseFoodCost() / 2);
      setCost(100);
      setNumberOfBabies(10);
      setPayoff(getCost() / 20);
  }

};

#endif
