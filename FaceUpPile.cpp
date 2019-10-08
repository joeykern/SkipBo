#include <iostream>
#include "FaceUpPile.h"
#include "Pile.h"
#include "Card.h"
#include <vector>

// for live game play - must not change!
void FaceUpPile::display() const {
  if (size()) {
    pile[pile.size()-1].display();
  }
  else std::cout << "--";
  std::cout << "/" << size();
}

//removes top card from face up pile and places into new card to be returned 
Card FaceUpPile:: remove() {
  Card c = this->pile.back();
  this->pile.pop_back();
  return c; 
}

Card FaceUpPile:: top() {
  Card c = this->pile.back();
  return c; 
}

