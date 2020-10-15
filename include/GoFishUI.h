#ifndef GOFISHUI_H
#define GOFISHUI_H
#include <string>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"

/**
* @author Shannon Abeda
* @date 2020-10-07
*/

/**
* This class implements a Game interface
*
*/

class GoFishUI {
 public:
  /**
  * Public constructor
  *
  */
  GoFishUI() {}
  /**
  * Virtual deconstructor
  */
  virtual ~GoFishUI() {}
  /**
  * Void function
  * @param none
  * @return none
  * Dsiplays if users does not
  * win round
  */
  virtual void goFish();
  /**
  * Void function
  * @param none
  * @return nothing
  * Display help if user is stuck
  */
  virtual void help();
  /**
  * Game Banner
  * @param none
  * @return nothing
  */
  virtual void gameBanner();
  /**
  * Player win Display
  * @param none
  * @return nothing
  */
  virtual void playerWin();
  /**
  * Plaer lose Display
  * @param none
  * @return nothing
  */
  virtual void playerLose();
  /**
  * User choice for card
  * @param none
  * @return String choice
  */
  std::string choice(Player*p);
  /**
  * Print Player Status
  * @param Player * p
  * @return none
  * Prints player Status
  */
  virtual void printPlayerStats(Player*p);
  /**
  * User name choice
  * @param none
  * @return string userName
  */
  std::string getUserName();
  /**
  * User computer name choice
  * @param none
  * @return string computerName
  */
  std::string getComputerName();
  /**
  * Prints players hand
  * @param Player object
  * @return nothing
  */
  virtual void viewPlayerHand(Player*p);
  /**
  * views player score
  * @param Player object
  * @return none
  */
  virtual void viewPlayerScore(Player*p);
  /**
  * Prints if users plays again
  * @param none
  * @return nothing
  */
  virtual void userPlayAgain();
  /**
  * Ask user if they have card
  * @param none
  * @return true if they do, false if they don't
  */
  bool askUser(Card random, Player*p);
  /**
  * View for computer if they lose their turn
  * @param none
  * @return none
  */
  virtual void goFishComputer();
  /**
  * View if computer wins turns
  * @param none
  * @return none
  */
  virtual void computerPlay();
};
#endif // GoFishUI
