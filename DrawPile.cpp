#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "DrawPile.h"
#include "FaceUpPile.h"
#include "Pile.h"


using std::vector;
using std::ifstream;
// for live game play - must not change!
void DrawPile::display() const {
  std::cout << "[XX]/" << size();
}

DrawPile::DrawPile() {

}

std::string DrawPile::getRand() const{
	return "true";
}

Card DrawPile::remove() {
  //creates new card from back of pile 
  Card c = this->pile.back();
  //removes the card from the drawpile
  this->pile.pop_back();
  
  return c; 
    
} 



void DrawPile::load_draw_pile(std::string filename) {

    int num;
    ifstream readIn;
    readIn.open(filename);
    //while there are still numbers to read in 
    while (readIn >> num) {

      addCard(Card(num));
     
    }

  }

  
void DrawPile::build_to_set(FaceUpPile&  build) {
  //called on set aside pile to add cards to set aside pile 
  for (int i = 0; i < 12; i++) {
  	addCard(build.getCard(i));
  
  }
  //calls faceuppile constructor 
  build = FaceUpPile();
  
}

void DrawPile::set_to_draw(DrawPile& set) {
  //called on draw pile to add cards to draw pile 
  for (int i = 0; i < set.size(); i++) {
    addCard(set.getCard(i)); 
  }
  
  //calls drawpile constructor 
  set = DrawPile(); 
}

  
