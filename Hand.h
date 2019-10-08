#ifndef _HAND_H
#define _HAND_H

#include "Pile.h"

class Hand: public Pile {
 public:
  virtual void display() const override;

  //removes specified card from hand 
  Card remove_hand(int i);

  Card receive_hand(int i); 
};




#endif 
