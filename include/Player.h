/**
* @author Shannon Abeda
* @date 2020-10-07
*/

/**
* This class implements a Player object
*
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include<iostream>
#include "SetOfCards.h"
#include "Card.h"
#include <vector>
#include "Card.h"


class Player {
 public:
  /**
  * Default constructor
  * Intalizers player score to 0
  * @param none
  * @return none
  */
  Player() {
    playerScore = 0;
  }
  /**
  * Virtual Deconstructor
  * @param none
  * @return none
  */
  virtual ~Player() {}
  /**
  * setter function
  * @param string name
  * @return none
  */
  void setName(std::string n);
  /**
  * Getter method
  * @param none
  * @return string name
  */
  std::string getName();
  /**
  * add card object to players hand
  * @param Card object
  * @return none
  */
  void addCard(Card C); //Adding card to hand
  /**
  * remove card from players hand
  * @param string card value
  * @return Card object from players hand
  */
  Card removeCard(std::string c); //Takes a card from hand
  /**
  * Helper function to find index in vector
  * @param string card value
  * @return int location of card in vector
  */
  int findCard(std::string);
  /**
  * helper function for testing
  * @param none
  * @return int size of players hand
  */
  int handSize();
  /**
  * Displays cards in players  hand
  * @param none
  * @return none
  */
  void showHand();
  /**
  * Userplay function
  * @param Player user Player computer
  * @param SetOfCards deck
  * @param string userChoice
  * @return true if player wins turns
  */
  bool userPlay(Player*p, Player*p2, std::string c);
  /**
  * Function to check if card exists in players
  * hand
  * @param string card value
  * @return true if card is found false if not found
  */
  bool hasCard(std::string c); //Checks if player has card
  /**
  * Function to compare ranks of cards
  * @param Card c
  * @param Card d
  * @return true if card rank is the same
  * @return false if card rank differs
  */
  bool checkRank(Card c, Card d); //Card comparison
  /**
  * Function to calculate players score
  * Checks for amount of four of kind
  * @param none
  * @return int playerScore
  */
  int scoreCount(); //stringScore count
  /**
  * Method finds random card from CPU
  * hand
  * @param none
  * @return Card random
  */
  Card randomCard();


 protected:
  std::string name;
  std::vector<Card> hand;
  int playerScore;
};

#endif // PLAYER_H
