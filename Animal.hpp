/*********************************************************************
** Description: Specification file for the Animal class.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal {

private:


protected:
  int age, baseFoodCost, cost, numberOfBabies, payoff;

public:
  Animal();
  Animal(int daysOld);
  ~Animal();
  int getAge();
  void setAge(int daysOld);
  int getBaseFoodCost();
  void setBaseFoodCost(int dollars);
  int getCost();
  void setCost(int dollars);
  int getNumberOfBabies();
  void setNumberOfBabies(int babies);
  int getPayoff();
  void setPayoff(int pay);


};

#endif
