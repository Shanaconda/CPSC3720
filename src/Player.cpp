#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void Player::setName(std::string n) {
  name = n;
}


std::string Player::getName() {
  return name;
}


void Player::addCard(Card C) {
  hand.push_back(C);
}


int Player::handSize() {
  return hand.size();
}


Card Player::removeCard(std::string c) {
unsigned int loc = findCard(c);
Card r = hand[loc];
hand.erase(begin(hand)+loc);
return r;
}

int Player::findCard(std::string c) {
  for (unsigned int i=0; i < hand.size(); i++)
    if (c == hand[i].getVal())
      return i;

      return false;
}

bool Player::hasCard(std::string c) {
  std::string key = c;

  for (unsigned int i=0; i < hand.size(); i++) {
    if (hand[i].getVal() == key) {
      return true;
    }
  }
  return false;
}

bool Player::checkRank(Card c, Card d) {
  if (c.getVal() != d.getVal()) {
    return false;
  }

  return true;
}


void Player::showHand() {
  for (unsigned int i=0; i < hand.size(); i++) {
    std::cout << hand[i];
  }
}
Card Player::randomCard() {
  unsigned int seed = time(NULL);
  int randomIndex = rand_r(&seed) % hand.size();
  Card c = hand[randomIndex];
  return c;
}

bool Player::userPlay(Player*p, Player*p2, std::string choice) {
  bool check = p2->hasCard(choice);
  if (check) {
    p->addCard(p2->removeCard(choice));
    return true;
  } else {
    return false;
  }
}


int Player::scoreCount() {
  for (unsigned int i = 0; i < hand.size(); i++) {
    int sum = 0;
    for (unsigned int j = i+1; j < hand.size(); j++) {
      if (checkRank(hand[i], hand[j])) {
        sum++;
      }

      if (sum == 3) {
        playerScore++;
      }
    }
}
return playerScore;
}
