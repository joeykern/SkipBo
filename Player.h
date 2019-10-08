#ifndef _PLAYER_H
#define _PLAYER_H

#include "BuildPile.h"
#include "DrawPile.h"
#include "FaceUpPile.h"
#include "Hand.h"
#include <vector>
class Player {
 public:
  
 Player() {

 }
 Player(std::string name): name(name) {

 }

 void display() const ;

 std::string toString() const;

 void readIn(std::istream &);

 //adds a card to player's stockpile   
 void add_to_Stock(Card c);

 //adds a card to player hand 
 void add_to_Hand(Card c);

 //gets the size of a players hand
 int get_size();

 //gets the size of the stock pile 
 int get_stock_size(); 

 //removes top card from stock 
 Card get_stock();

 //returns value of top stock card
 int get_stock_value(); 

 //removes specified card from discard pile 
 Card get_discard(int i);

 //gets value of top card of discard pile
 int get_discard_value(int i); 

 //removes specified card from hand 
 Card get_hand(int i);

 //gets value of specified card in hand
 int get_hand_value(int i); 

 //adds card from hand to discard pile 
 void get_hd(int i, int j);

 //gets name of a player
 std::string getName(); 
 
 
 private:

 std::string name;
 Hand hand;
 int hand_size;
 FaceUpPile stock;
 int stack_size;
 FaceUpPile discard[4];
 int discard_size;
  
};

#endif
