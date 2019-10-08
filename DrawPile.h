#ifndef _DRAWPILE_H
#define _DRAWPILE_H

#include "Card.h"
#include "Pile.h"
#include "FaceUpPile.h"

class DrawPile: public Pile {

 public: 
  DrawPile();
  DrawPile(std::string filename); 
  std::string getRand() const;
  virtual void display() const override; //display the card setup

  //remove the back card from the draw pile 

  Card remove();

  //reads in a draw pile 
 void load_draw_pile(std::string filename);

 //puts the build pile into set aside pile 
 void build_to_set(FaceUpPile& build);

 //puts the set aside pile into the draw pile 
 void set_to_draw(DrawPile& set); 
};



#endif
