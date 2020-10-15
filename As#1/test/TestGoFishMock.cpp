#include "GoFishUI.h"
#include "GoFish.h"
#include "Player.h"
#include "SetOfCards.h"
#include "Card.h"
#include <string>
#include "GoFishMock.h"

using ::testing::Return;

TEST(GoFishMock, viewPlayerStatsTest) {
    GoFishMock mock;
    SetOfCards * deck = new SetOfCards();
    Player*p = new Player();
    p->setName("Test");
    for (int i = 0; i < 5; i++) {
    p->addCard(deck->draw());
  }
  EXPECT_CALL(mock, viewPlayerStats(p))
  .Times(1)
  .WillOnce(Return());
  mock.viewPlayerStats(p);

  EXPECT_TRUE(p != NULL);
  delete p;
  delete deck;
}

TEST(GoFishMock, setGameTest) {
  GoFishMock mock;
  EXPECT_CALL(mock, setGame())
  .Times(1)
  .WillOnce(Return());
  mock.setGame();
}

TEST(GoFishMock, playGameTest) {
  GoFishMock mock;
  EXPECT_CALL(mock, playGame())
  .Times(1)
  .WillOnce(Return());
  mock.playGame();
}
