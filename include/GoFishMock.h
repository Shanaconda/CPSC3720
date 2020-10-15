#ifndef GOFISHMOCK_H_
#define GOFISHMOCK_H_
#include <string>
#include <iostream>
#include "gmock/gmock.h"
#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"
#include "GoFishUI.h"

/**
* @author Shannon Abeda
* @date 2020-10-12
*/

/**
* This class implements a mock of
* GoFish class
*/


class GoFishMock: public GoFish {
 public:
   /**
   * Default mock constructor
   * @param none
   * @return none
   */
  explicit GoFishMock() {}
  /**
  * Default mock deconstructor
  * @param none
  * @return
  */
  virtual ~GoFishMock() {}
  /**
  * Mock Method
  * Set games
  * @param none
  * @return none
  */
  MOCK_METHOD0(setGame, void());
  /**
  * Mock Method
  * Play games
  * @param none
  * @return none
  */
  MOCK_METHOD0(playGame, void());
  /**
  * Mock method
  * Views players stats
  * @param Player info
  * @return none
  */
  MOCK_METHOD1(viewPlayerStats, void(Player*p));
};

#endif //GoFishMock.h
