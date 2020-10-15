#ifndef GOFISH_H
#define GOFISH_H
#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"
#include "GoFishUI.h"
#include <string>
#include <iostream>

/**
* @author Shannon Abeda
* @date 2020-10-07
*/

/**
* This class implements a GoFish controller
* class
*/
class GoFish {
 public:
    /**
    * Default constructor
    * @param none
    * @return none
    */
    GoFish();
    /**
    * Deconstructor
    * @param none
    * @return none
    */
    virtual ~GoFish();
    /**
    * Play game function
    * @param none
    * @return none
    */
    void virtual playGame();
    /**
    * Set game function
    * @param none
    * @return none
    */
    void virtual setGame();
    /**
    * View players stats
    * @param none
    * @return none
    */
    void virtual viewPlayerStats(Player*p);


 private:
    GoFishUI* view;
    Player* p1;
    Player* computer;
    SetOfCards* deck;
};
#endif // GoFish_h
