#include <iostream>
#include <string>
#include <sstream>
#include "Player.h"
#include "Pile.h"
#include "Hand.h"
#include "FaceUpPile.h"
#include "StockPile.h"
#include "Card.h"
#include <vector>

using std::string; 

// for live game play - must not change!
void Player::display() const {
  std::cout << "Current ";
  std::cout << name << ":  Stock{0}: " ;
  stock.display();
  std::cout << std::endl;
  std::cout << "   Discards{1-4}: ";
  for (int i = 0; i < 4; ++i) {
    discard[i].display();
    std::cout << "  ";
  }
  std::cout << std::endl;
  std::cout << "   Hand{5-9}: ";
  hand.display();
  std::cout << std::endl;
}

/* saving state format - must not change!
PlayerName
Stock size
01 02 03  ...
...
Hand size
01 02 03 04 05
Discard1 size
01 02 03 04 ...
...
Discard2 size
...
Discard3 size
...
Discard4 size
...
*/
std::string Player::toString() const {
  std::stringstream result;
  result << name << "\n";
  result << "Stock " << stock.toString();
  result << "Hand " << hand.toString();
  for (int i = 0; i < 4; ++i) {
    result << "Discard" << i << " " << discard[i].toString();
  }
  return result.str();
}

void Player::readIn(std::istream &is) {
  is >> name;

  stock.readIn(is);
  hand.readIn(is);
  for (int i = 0; i < 4; i++) {
    discard[i].readIn(is);
  }
}

//adds card to stockpile 
void Player::add_to_Stock(Card c) {
  stock.addCard(c); 
}

//adds card to hand 
void Player::add_to_Hand(Card c) {
  hand.addCard(c); 
}

//returns size of hand 
int Player::get_size() {
  return hand.size(); 
}

//returns size of stock 
int Player::get_stock_size() {
  return stock.size(); 
}

//removes top card from stock 
Card Player::get_stock() {
  return stock.remove(); 

}

int Player::get_stock_value() {
  
  return stock.top().getValue(); 
}

//removes top card from discard pile 
Card Player::get_discard(int i) {
  return discard[i].remove(); 

}

int Player::get_discard_value(int i) {

  return discard[i].top().getValue(); 
}

//removes specified card from hand 

Card Player::get_hand(int i) {
  return hand.remove_hand(i); 
}

int Player::get_hand_value(int i) {
  return hand.receive_hand(i).getValue(); 
}

//adds card from hand to discard pile 
void Player::get_hd(int i, int j) {
  discard[j].addCard(hand.remove_hand(i)); 
  
}

string Player::getName() {
  return name; 
}


    
