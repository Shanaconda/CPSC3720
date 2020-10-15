#ifndef GOFISHVIEWMOCK_H_
#define GOFISHVIEWMOCK_H_
#include "gmock/gmock.h"
#include "GoFishUI.h"
#include "Player.h"

/**
* @author Shannon Abeda
* @date 2020-10-13
*/

/**
* This class implements a mock
* of view class GoFishUI
*/

class GoFishUIMock: public GoFishUI {
 public:
   /**
   * Default mock constructor
   * @param none
   * @return none
   */
explicit GoFishUIMock() {}
   /**
   * Default mock deconstructor
   * @param none
   * @return none
   */
virtual ~GoFishUIMock() {}
   /**
   * Mock Method
   * Displays GoFish message
   * @param none
   * @return none
   */
MOCK_METHOD0(goFish, void());
   /**
   * Mock method
   * Displays help message
   * @param none
   * @return none
   */
MOCK_METHOD0(help, void());
   /**
   * Mock method
   * Displays gameBanner
   * @param none
   * @return none
   */
MOCK_METHOD0(gameBanner, void());
   /**
   * Mock method
   * Display if player wins
   * @param none
   * @return none
   */
MOCK_METHOD0(playerWin, void());
   /**
   * Mock method
   * Display if player loses
   * @param none
   * @return none
   */
MOCK_METHOD0(playerLose, void());
   /**
   * Mock method
   * Prints player Stats
   * @param Player
   * @return none
   */
MOCK_METHOD1(printPlayerStats, void(Player*p));
   /**
   * Mock method
   * Prints player hands
   * @param Player
   * @return none
   */
MOCK_METHOD1(viewPlayerHand, void(Player*p));
   /**
   * Mock method
   * Prints player score
   * @param Player
   * @return none
   */
MOCK_METHOD1(viewPlayerScore, void(Player*p));
   /**
   * Mock method
   * Prints if player plays again
   * @param none
   * @return none
   */
MOCK_METHOD0(userPlayAgain, void());
   /**
   * Mock method
   * prints GoFish computer
   * @param none
   * @return none
   */
MOCK_METHOD0(goFishComputer, void());
   /**
   * Mock method
   * prints Computer play
   * @param none
   * @return none
   */
MOCK_METHOD0(computerPlay, void());
};

#endif //GoFishViewMock.h
