#include "Menu.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


/***********************************************************************************************
** Description: Prints a list of all options in the options vector for the user to select an
** option from the menu.
***********************************************************************************************/
void Menu::displayMenu() {
  for (unsigned int i = 0; i < options.size(); i++) {
    cout << i + 1 << ") " << options.at(i) << endl;
  }
}


void Menu::addMenuItem(const string &menuItem) {
  options.push_back(menuItem);
}


/***********************************************************************************************
** Description: Takes a reference to a string used to indicate a prompt for the user to enter
** data, followed by references to integers that output valid values to hint that the user
** should enter an integer value within the entered values. Input is passed to validateInput and
** validateRange to verify that the input is an integer and falls within a valid range for the
** prompt, then the integer value the user entered is returned if it was valid. Otherwise, the
** prompt is repeated. A boolean is passed to specify whether the entire menu should be
** displayed along with the prompt for a selection.
***********************************************************************************************/
int Menu::getIntChoiceFromPrompt(const string &prompt, const int &minVal, const int &maxVal, bool displayTheMenu) {

  string userInput;

  do {
    cout << prompt << endl;
    if (displayTheMenu) {
      displayMenu();
    }
    cout << "Valid input range: [" << minVal << " - " << maxVal << "]: ";
    getline(cin, userInput);
  } while(!validateInput(userInput) || !validateRange(stoi(userInput), minVal, maxVal));

return stoi(userInput);

}


/*********************************************************************
** Description: Returns the size of the options vector.
** Used with the getIntChoiceFromPrompt fucntion to determine the
** maximum valid selection for a menu item.
*********************************************************************/
int Menu::getMenuChoices() {
      return options.size();
}


/*********************************************************************
** Description: This function accepts a reference to a string, which
** is then looped through to search for non-digit characters. The
** return value is true is there are only digits in the string passed
** to the function, otherwise, the function returns false.
*********************************************************************/
bool Menu::validateInput(const string &inputStr) {
  bool isValid = true;

  if (inputStr.empty()) {
    isValid = false;
  }

  for (unsigned int i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}


/***********************************************************************************************
** Description: Takes a reference to an integer value to check, and minimum and maximum values.
** If the input is an integer and in the valid range, the function returns true. Otherwise,
** it returns false.
***********************************************************************************************/
bool Menu::validateRange(const int &inputVal, const int &minVal, const int &maxVal) {

  if ((inputVal >= minVal) && (inputVal <= maxVal)) {
    return true;
  } else {
    return false;
  }
}
