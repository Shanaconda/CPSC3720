#include <string>
#include "gtest/gtest.h"
#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"




TEST(TestPlayer, TestConstructor) {
  Player * p = new Player;
  p->setName("Shannon");
  EXPECT_EQ("Shannon", p->getName());
  delete p;
}

TEST(TestPlayer, AddCardToHandTest) {
  Card c("1", "C");
  Player p2;
  p2.addCard(c);

  EXPECT_EQ(1, p2.handSize());
}

TEST(TestPlayer, RankComparisonTest) {
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("2", "C");
  Card c4("3", "D");
  EXPECT_TRUE(p1.checkRank(c2, c1));
  EXPECT_FALSE(p1.checkRank(c3, c4));
}

TEST(TestPlayer, hasCardTest) {
  Player p1;
  Card c1("1", "C");

  p1.addCard(c1);

  EXPECT_TRUE(p1.hasCard("1"));
  EXPECT_FALSE(p1.hasCard("2"));
}

TEST(TestPlayer, scoreTest) {
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("1", "C");
  Card c4("1", "D");

  p1.addCard(c1);
  p1.addCard(c2);
  p1.addCard(c3);
  p1.addCard(c4);

  EXPECT_EQ(1, p1.scoreCount());
}

TEST(TestPlayer, eraseCardTest) {
  Player p1;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("1", "C");
  Card c4("1", "D");

  p1.addCard(c1);
  p1.addCard(c2);
  p1.addCard(c3);
  p1.addCard(c4);

  Card c5 = p1.removeCard("1");

  EXPECT_EQ(3, p1.handSize());
  EXPECT_EQ("1", c5.getVal());
}

TEST(TestPlayer, randomCardGenerator) {
  Player*p = new Player();
  Card c;
  Card c1("1", "C");
  Card c2("1", "D");
  Card c3("1", "C");
  Card c4("1", "D");
  p->addCard(c1);
  p->addCard(c2);
  p->addCard(c3);
  p->addCard(c4);
  c = p->randomCard();
  p->addCard(c);
  EXPECT_EQ(p->handSize(), 5);
  delete p;
}

TEST(TestPlayer, userPlayTest) {
  std::string choice1 = "1";
  std::string choice2 = "2";
  Player*p = new Player();
  Player*c = new Player();
  Card c1("1", "C");
  p->addCard(c1);
  c->addCard(c1);
  bool turn1;
  bool turn2;
  turn1 = p->userPlay(p, c, choice1);
  turn2 = p->userPlay(p, c, choice2);
  EXPECT_TRUE(turn1);
  EXPECT_FALSE(turn2);
  delete p;
  delete c;
}
