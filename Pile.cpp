#include <vector>
#include <string>
#include <algorithm>
#include <random> 
#include "Pile.h"
#include "Player.h" 
using std::istream;
// for saving game state - must not change!
std::string Pile::toString() const {
  std::string result;
  result.append(std::to_string(size()));
  result.append("\n");
  // add all the pile elements to the string, at most 20 per line
  for (int i=0; i < size(); ++i) {
    if (i % 20 == 0 && i != 0)
      result.append("\n");
    else if (i != 0)
      result.append(" ");
    result.append(pile[i].toString());
  }
  result.append("\n");
  return result;
}

void Pile::readIn(istream & is) {
  is >> name;

  int num_cards; 
  is >> num_cards;
  for (int i = 0; i < num_cards; i++) {
    int val;
    is >> val;
    Card c(val);
    addCard(c); 
  }
}

//checks if the pile is empty 
bool Pile::isEmpty() const {
  return pile.size() == 0;

}

int Pile::getSize() const {
  return pile.size();
}

//shuffles by randomly switching cards from beginning of pile to end of pile 
void Pile::shuffle() {
  std::random_shuffle(this->pile.begin(), this->pile.end());
}

