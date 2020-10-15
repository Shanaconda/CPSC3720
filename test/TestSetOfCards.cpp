#include "gtest/gtest.h"
#include "Card.h"
#include "SetOfCards.h"

TEST(TestSetOfCards, newDeck) {
  SetOfCards * c = new SetOfCards();
  c->newDeck();
  EXPECT_EQ(52, c->getSizeDeck());
  delete c;
}

TEST(TestSetOfCards, drawFromDeck) {
  SetOfCards * c = new SetOfCards();
  Card d;
  c->newDeck();
  d = c->draw();
  EXPECT_EQ(51, c->getSizeDeck());
  delete c;
}
