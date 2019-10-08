#include <iostream>
#include "StockPile.h"
#include "DrawPile.h" 

void StockPile::display() const {

  std::cout << "[" << this->pile.begin().getValue() << "]/" << size(); 
}


StockPile::StockPile() {

  vector<Card> s_pile;

  //initializes size of stock piles   
  if (num_players > 0 && num_players <= 4) {
    //iterates through stock pile size 
    for (int i = 0; i < 30; i++) {
      //iterates through number of players 
      for (int j = 0; j < num_players; j++) {
	//adds card to player stock pile 
	Card c = DrawPile.remove();
	Player[j].s_pile.push_back(c);
      }
    }
      
  } else if (num_players > 4 && num_players <= 6) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < num_players; j++) {

	Card c = DrawPile.remove();
	Player[j].s_pile.push_back(c);
      }
    }
  }
}



  
