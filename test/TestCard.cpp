#include "gtest/gtest.h"
#include "Card.h"

TEST(TestCardClass, constructorTest) {
  Card *c = new Card("1", "C");
  EXPECT_EQ("1", c->getVal());
  EXPECT_EQ("C", c->getSuit());
  delete c;
}
