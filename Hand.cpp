#include <iostream>
#include "Hand.h"


// for live game play - must not change!
void Hand::display() const {
  int i;
  for (i = 0; i < size(); i++) {
    pile[i].display();
    std::cout << "  ";
  }
  for ( ; i < 5; i++)
    std::cout << "--  ";
}


Card Hand::remove_hand(int i) {
  //creats new card equal to card at index passsed in 
  Card c = this->pile[i];
  //removes card from the hand 
  this->pile.erase(this->pile.begin() + i);
  return c; 
}

Card Hand::receive_hand(int i) {

  Card c = this->pile[i];
  return c; 

}
