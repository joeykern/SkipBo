#ifndef _FACE_UP_PILE_H
#define _FACE_UP_PILE_H

#include "Pile.h"
#include <algorithm>
#include <vector>

class FaceUpPile : public Pile {
 public:

  virtual void display() const override; 
  

  bool add(Card *c);

  Card top();

  // removes top card of face up pile 
  Card remove(); 

};

#endif 
