#ifndef _STOCKPILE_H
#define _STOCKPILE_H

#include "Card.h"
#include "Pile.h"



class StockPile: public Pile {
  
 public:

  StockPile();

  virtual ~StockPile();

  void display() const;

   

};

#endif 

