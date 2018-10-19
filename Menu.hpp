/*********************************************************************
** Description: Specification file for the Menu class.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>

class Menu {

  private:
    std::vector<std::string> options;
    bool validateInput(const std::string &inputStr);
    bool validateRange(const int &inputVal, const int &minVal, const int &maxVal);

  public:
    void addMenuItem(std::string menuItem);
    void displayMenu();
    int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal, bool displayTheMenu);
    int getMenuChoices();

};

#endif
