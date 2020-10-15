#ifndef CARD_H
#define CARD_H
#include <string>
#include<iostream>

/**
* @author Shannon Abeda
* @date 2020-10-07
*/

/**
* This class implements a Card Object
*
*/

class Card {
 public:
   /**
   * Overloaded operator implemented to
   * output a card object
   *
   */
  friend std::ostream& operator<<(std::ostream& os, const Card& c);
   /**
   * Default constructor
   * @param none
   * @retrun none
   */
  Card();
  /**
  * Virtual deconstructor
  * @param none
  * @return none
  */
  virtual ~Card();
  /**
  * Card constructor
  * @param string value string suit
  * @return none
  */
  Card(std::string v, std::string s);
  /**
  * Getter methods
  * @param none
  * @return string suit
  */
  std::string getSuit() const;
  /**
  * Getter method
  * @param none
  * @return string value
  */
  std::string getVal() const; //Returns Val


 protected:
  std::string suit, val;
};
#endif // CARD_H
