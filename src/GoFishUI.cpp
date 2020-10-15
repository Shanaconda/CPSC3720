#include "GoFishUI.h"
#include <string>
#include <iostream>
#include "Player.h"
#include "Card.h"
#include "SetOfCards.h"

void GoFishUI::goFish() {
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout<< "GOFISH ";
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
}

void GoFishUI::goFishComputer() {
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
  std::cout<< "The computer lost their turn ";
  std::cout<< std::endl;
  std::cout <<"You will play now ";
  std::cout<< std::endl;
  std::cout << "------------------------";
  std::cout<< std::endl;
}

void GoFishUI::computerPlay() {
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
  std::cout<< "The computer got your card";
  std::cout<< std::endl;
  std::cout<< "The computer will play again";
  std::cout<< std::endl;
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
}

void GoFishUI::userPlayAgain() {
  std::cout << "You picked up a card ";
  std::cout << "You will play again" << std::endl;
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
}

bool GoFishUI::askUser(Card random, Player*p) {
  std::string userInput;
  std::string cardNum = random.getVal();
  std::cout << "Do you have a: ";
  std::cout << cardNum << std::endl;
  std::cout << "Type Yes or No: ";
  std::cin >> userInput;

  //Uppercase in case user types yes or no
  toupper(userInput[0]);
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;

  //function to check if user has card in hand
  bool check = p->hasCard(cardNum);

  //Condition to check if user is lying
  if ((userInput == "Yes") && (check == true)) {
      return true;
  } else if ((userInput == "Yes") && (check == false)) {
      std::cout<< "Hey.. it's not cool to cheat";
      std::cout<< std::endl;
      return false;
  } else if ((userInput == "No") && (check == true)) {
      std::cout<< "Don't be stupid.. I am still going ";
      std::cout<< "to take you card" << std::endl;
      return true;
  } else {
    return false;
  }
}


void GoFishUI::help() {
  std::cout<< "-------------------------------";
  std::cout<< "-------------------------------";
  std::cout<< std::endl;
  std::cout<< "The objective of this game is obtain the most four of kinds. \n";
  std::cout<< "Each time you receive a four a kind you will score a point. \n";
  std::cout<< "You will play first and ask the Computer if they have";
  std::cout<< "the card they're looking forward. \n";
  std::cout<< "If they do, they must give up that card"<< std::endl;
  std::cout<< "You will receive the card and add it to your deck (GOFISH).";
  std::cout<< "If you receive a four kind, it will count towards a point. \n";
  std::cout<< "If you don't have that card,";
  std::cout<< "then you will draw a random deck from the deck";
  std::cout<< "and you will give up your turn."<< std::endl;
  std::cout<< "-------------------------------";
  std::cout<< "-------------------------------";
  std::cout<< std::endl;
}


void GoFishUI::gameBanner() {
  std::cout<< "-------------------------------";
  std::cout<< "Welcome to GoFish Game";
  std::cout<< "-------------------------------";
  std::cout<< std::endl;
}

void GoFishUI::playerWin() {
  std::cout << "-----------------------";
  std::cout <<"You won" << std::endl;
  std::cout << "-----------------------";
  std::cout << std::endl;
}

void GoFishUI::playerLose() {
  std::cout << "-----------------------";
  std::cout <<"You lost";
  std::cout << "-----------------------";
  std::cout << std::endl;
}

std::string GoFishUI::choice(Player*p) {
  std::string userChoice;
  bool cheat;
  //User input
  start:
  std::cout << "-----------------------";
  std::cout << std::endl;
  std::cout<< "What Card do you want: ";
  std::cin >> userChoice;
  std::cout << "-----------------------";
  std::cout << std::endl;

  //Checking if user is cheating
  cheat = p->hasCard(userChoice);

  if (cheat) {
    return userChoice;
  } else { //If user is cheating then it will repeat userPrompt
    std::cout<< "You cannot ask for a card that you don't have ";
    std::cout<< std::endl;
    std::cout<< "Try again" << std::endl;
    goto start;
  }
}

void GoFishUI::printPlayerStats(Player*p) {
  //Player name
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
  std::cout<< "This is your current stats";
  std::cout<< std::endl;
  std::cout<< "Player name: " <<p->getName();
  std::cout<< std::endl;
  //Print hand
  std::cout<< "Current hand: ";
  std::cout<< std::endl;
  p->showHand();
  std::cout<< std::endl;
  //Prints score
  std::cout<< "Current Score: " <<p->scoreCount();
  std::cout<< std::endl;
  std::cout << "-----------------------";
  std::cout << "------------------------";
  std::cout << std::endl;
}

std::string GoFishUI::getUserName() {
  std::string userName;
  std::cout << "Please Enter your name: ";
  std::cin >> userName;
  std::cout << "-----------------------";
  std::cout << std::endl;
  return userName;
}

void::GoFishUI::viewPlayerHand(Player*p) {
  std::cout<< "This is your current hand: ";
  std::cout<< std::endl;
  p->showHand();
  std::cout << std::endl;
  std::cout << "-----------------------";
  std::cout<< std::endl;
}

void GoFishUI::viewPlayerScore(Player*p) {
  std::cout << "-----------------------";
  std::cout << std::endl;
  std::cout<< "Current score: ";
  p->scoreCount();
  std::cout << std::endl;
  std::cout << "-----------------------";
  std::cout<< std::endl;
}

std::string GoFishUI::getComputerName() {
  std::string computerName;
  //User input
  std::cout << "Enter your opponents name: ";
  std::cin >> computerName;
  std::cout << "-----------------------";
  std::cout << std::endl;
  return computerName;
}
