#ifndef _SKIPBOGAME_H
#define _SKIPBOGAME_H


#include "Pile.h"
#include "BuildPile.h"
#include "FaceUpPile.h"
#include "DrawPile.h"
#include "Player.h"
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <cstdlib> 


class SkipBoGame {
 public:
  //initializes a game with specified start parameters 
  SkipBoGame (std::string shuff, int num, int stock, std::string start_file):curp(0), nump(num), stock_size(stock), shuff(shuff) {

    
    for (int i = 0; i < nump; i++) {
      peep[i] = Player("Player" + std::to_string(i));
       
    }
    
    
    //    std::cout << "num players is " << nump << std::endl;
    //std::cout << "stock size is " << stock_size << std::endl; 
	  
	  draw.load_draw_pile(start_file);
	  //	  std::cout << draw.toString() << std::endl;
	  if (shuff == "true") {
	    draw.shuffle();
	  }
	  
	  deal_cards(); 
	  //	  std::cout << draw.toString() << std::endl;

	  //	  draw.display(); 
  }
  SkipBoGame (std::string shuff, std::string start_file): shuff(shuff) {
    load_game(start_file);
  }

  void load_game(std::string filename);
  
  std::string toString() const;
  //creates new deck of cards to play with 
  void make_deck(); 
  void display() const;
  //deal cards to stock pile of players 
  void deal_cards();
  //handles game play 
  int play_game();
  
   
  
 private:

    int curp;
    int nump;
    int stock_size; 
    DrawPile draw;
    BuildPile build[4]; 
    Player peep[6];
    std::string shuff;
    DrawPile set_aside; 
  

};

#endif 
