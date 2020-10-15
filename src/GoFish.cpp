#include "GoFishUI.h"
#include "GoFish.h"
#include "Player.h"
#include "SetOfCards.h"
#include "Card.h"
#include <string>
#include <iostream>

GoFish::GoFish() {
  view = new GoFishUI;
  p1 = new Player();
  computer = new Player();
  deck = new SetOfCards();
}



GoFish::~GoFish() {
  delete view;
  delete p1;
  delete computer;
  delete deck;
}


void GoFish::playGame() {
  //Game banner display
  view->gameBanner();
  //Setting up intial game
  GoFish::setGame();
  //Displaying how the game functions
  view->help();
  //Display current Player Stats
  GoFish::viewPlayerStats(p1);
  //Conditional loop as long as the deck is not empty
  do {
    start:
    //Get user choice for card
    std::string userChoice = view->choice(p1);
    //Returns true if computer has the card or not
    bool userTurn = p1->userPlay(p1, computer, userChoice);
    if (userTurn) { //If user gains a card, user will play again
      view->userPlayAgain();
      //Player hand view
      view->viewPlayerHand(p1);
      //Player score count
      view->viewPlayerScore(p1);
      //Return to prompt
      goto start;
    } else {
      //User view if they lose
      view->goFish();
      //Player draws from deck again
      p1->addCard(deck->draw());
      //Updated hand
      view->viewPlayerHand(p1);
      //The CPU asks user if they have a random card from their deck
      start2:
      Card random = computer->randomCard();
      bool hasCard = view->askUser(random, p1);
      //If true, card is removed
      if (hasCard) {
        std::string card = random.getVal();
        computer->addCard(p1->removeCard(card));
        view->computerPlay();
        goto start2;
      } else {
        computer->addCard(deck->draw());
        view->goFishComputer();
        goto start;
      }
    }
  } while (deck->getSizeDeck() != 0);

  int computerScore = computer->scoreCount();
  int playerScore = p1->scoreCount();

  if (computerScore > playerScore) {
      view->playerLose();
  } else {
      view->playerWin();
  }
}

void GoFish::setGame() {
  std::string userName;
  std::string computerName;

  //User input
  userName = view->getUserName();

  computerName = view->getComputerName();
  //setting PlayerName
  p1->setName(userName);
  //Setting Ai Name
  computer->setName(computerName);
  //Creating new deck
  deck->newDeck();

  //Drawing from deck
  for (int i = 0; i < 5; i++) {
    p1->addCard(deck->draw());
    computer->addCard(deck->draw());
  }
}

void GoFish::viewPlayerStats(Player*p) {
  //Prints player Status
  view->printPlayerStats(p1);
}
