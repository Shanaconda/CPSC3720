#include "GoFishUI.h"
#include "GoFish.h"
#include "Player.h"
#include "SetOfCards.h"
#include "Card.h"
#include <string>
#include "GoFishUIMock.h"

using ::testing::Return;

TEST(GoFishUIMock, goFishTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, goFish())
  .WillOnce(Return());
  mock.goFish();
}

TEST(GoFishViewMock, goFishComputerTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, goFishComputer())
  .WillOnce(Return());
  mock.goFishComputer();
}

TEST(GoFishUIMock, userPlayAgainTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, userPlayAgain())
  .WillOnce(Return());
  mock.userPlayAgain();
}

TEST(GoFishUIMock, help) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, help())
  .WillOnce(Return());
  mock.help();
}

TEST(GoFishUIMock, gameBannerTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, gameBanner())
  .WillOnce(Return());
  mock.gameBanner();
}

TEST(GoFishViewMock, playerWinTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, playerWin())
  .WillOnce(Return());
  mock.playerWin();
}

TEST(GoFishViewMock, playerLoseTest) {
  GoFishUIMock mock;
  EXPECT_CALL(mock, playerLose())
  .WillOnce(Return());
  mock.playerLose();
}

TEST(GoFishViewMock, PlayerStatsTest) {
  GoFishUIMock mock;
  Player*p = new Player();
  SetOfCards* deck = new SetOfCards();
  p->setName("Test");
  for (int i = 0; i < 5; i++) {
    p->addCard(deck->draw());
  }
  EXPECT_CALL(mock, printPlayerStats(p))
  .WillOnce(Return());

  EXPECT_CALL(mock, viewPlayerHand(p))
  .WillOnce(Return());

  EXPECT_CALL(mock, viewPlayerScore(p))
  .WillOnce(Return());

  mock.printPlayerStats(p);
  mock.viewPlayerHand(p);
  mock.viewPlayerScore(p);

  EXPECT_TRUE(p != NULL);
  delete p;
  delete deck;
}

TEST(GoFishViewMock, computerPlayTest) {
  GoFishUIMock mock;

  EXPECT_CALL(mock, computerPlay())
  .WillOnce(Return());

  mock.computerPlay();
}
