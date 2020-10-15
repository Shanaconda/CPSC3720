/**
* @author Shannon Abeda
* @date 2020-10-07
*/

/**
* This class implements a deck of derived
* from the base class Card
*/

#ifndef SETOFCARDS_H
#define SETOFCARDS_H

#include <Card.h>
#include <vector>

class SetOfCards : public Card {
 public:
   /**
   * Default Constructor
   * @param none
   * return none
   */
  SetOfCards();
  /**
  * Default virtual Constructor
  * @param none
  * @return none
  */
  virtual ~SetOfCards();
  /**
  * Creates a newDeck
  * @param none
  * @return none
  */
  void newDeck();
  /**
  * Method draws from the deck
  * given that the deck is not = 0
  * @param none
  * @return Card from deck
  */
  Card draw();
  /**
  * Method returns the size of the deck
  * Only use for GTesting to make sure
  * @param none
  * @return size of deck
  */
  int getSizeDeck();

 private:
  std::vector<Card> Deck;
};

#endif // SETOFCARDS_H
