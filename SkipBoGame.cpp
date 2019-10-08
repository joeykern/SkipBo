#include <iostream>
#include <sstream>
#include <fstream>
#include "SkipBoGame.h"
#include "Pile.h"
#include "Player.h" 
#include <string>
#include <time.h> 

using std::string;
using std::cin; 
using std::cout;
using std::endl;

/* for live game play - must not change format!

drawPile  build_a  build_b  build_c  build_d
playerName  stock_0  
discards: discard_1 discard_2 discard_3 discard_4
hand: card_5 card_6 card_7 card_8 card_9
 */
void SkipBoGame::display() const {
  std::cout << "Draw: ";
  draw.display();
  std::cout << "  Build Piles: ";
  for (int j = 0; j < 4; j++) {
    build[j].display();
    std::cout << " ";
  }
  std::cout << std::endl;
  peep[curp].display();
}

/* for saving state - must not change format!

shuffle numplayers currplayer
PlayerCurp [display]
PlayerCurp+1 [display]
[etc for all players]
Draw [display]
Build_a [display]
Build_b [display]
Build_c [display]
Build_d [display]
*/
std::string SkipBoGame::toString() const {
  std::stringstream result;
  int idx;
  result << shuff << " " << nump << " " << curp << "\n";
  for (int i = 0; i < nump; ++i) {
    idx = (curp+i) % nump;
    result << peep[idx].toString();
  }
  result << "Draw " << draw.toString(); 
  for (int j = 0; j < 4; j++) {
    result << "Build_" << char('a'+j) << " ";
    result << build[j].toString();  
  }
  return result.str();
}

//loads a game input 
void SkipBoGame::load_game(string filename) {
  std::ifstream file;
  
   
  file.open(filename, std::ifstream::in);

  
  file >> shuff;

  
  file >> nump;
  
  file >> curp;


  for (int i = 0; i < nump; i++) {
      peep[i].readIn(file);
    }
  draw.readIn(file);
  for (int i = 0; i < 4; i++) {
    build[i].readIn(file); 
  }
     
}

//creates a deck with 12 of each card 
  void SkipBoGame::make_deck() {
    int index = 0;
  for (int i = 0; i < 12; i++) {

    for (int j = 0; j < 12; i++) {


      draw.addCard(Card(i + 1));
      index++;
  }

  }
  //creates 18 skip bo cards
  while (index < 162) {
    draw.addCard(Card(0));
    index++;
  }

  }

//deals cards to each players stock 
void SkipBoGame::deal_cards() {
  //if (nump >= 2 && nump <= 4) {
  //for the given size of the stock 
    for (int i = 0; i < stock_size; i++) {
      //add one card to each players stock at a time
      for (int j = 0; j < nump; j++) {
	peep[j].add_to_Stock(draw.remove()); 
      }
    }
    //} else if (nump > 4 && nump <= 6) {
    //for (int i = 0; i < stock_size; i++) {
    //for (int j = 0; j < nump; j++) {
    //  peep[j].add_to_Stock(draw.remove());
	
    //}
    //}

    //}
  //cout << draw.toString() << endl;
   
}
//handles gameplay for playing the game 
int SkipBoGame::play_game() {

  //cout << "num players is " << nump << endl;
  //put in instructor cout << "stock size is " << stock_size << endl;

  //input the see if they want to play, quit, or save 
  char input = 0;
  bool newTurn = true;
  bool check = false;
  int turn = 0; 
  //int turn = 0; 
  //  bool onceOver = false;
  //cin >> input;

  //while they dont want to quit 
  while (input != 'q') {
    if (newTurn) {
      if (shuff == "true" && turn == 0) {
	srand (time(NULL)); 
	curp = (rand() % nump);
	//cout << "This rand()" << rand() << endl;
        //cout << "this nump" << nump << endl;				   
	//cout << "THIS CURP " << curp << endl; 
	cout << endl << " >> " << peep[curp].getName() << " turn next" << endl;
	cout << "(p)lay, (s)ave, or (q)uit ? ";
	cin >> input;
      }else {
	cout << endl << " >> " << peep[curp].getName() << " turn next" << endl;
        cout << "(p)lay, (s)ave, or (q)uit ? ";
        cin >> input;

      }
    }
    if (input != 'p' && input != 's' && input != 'q') {
      cout << "illegal command, try again" << endl;
      //newTurn = false; 
    }// else {
    //newTurn = false;
      //}
    //newTurn = true; 
    //if they want to play 
    if (input == 'p') {
      
      //if the hand size is 0
      if (newTurn) {
		
      if (peep[curp].get_size() < 5) {
	//while the hand size is not 5
      while (peep[curp].get_size() != 5) {
	//add cards to the hand 
    	  peep[curp].add_to_Hand(draw.remove()); 
      }
      //display(); 
      }
		
      }
    
      display();
      //    cout << draw.toString() << endl;
      //can be a move or draw cards
      char in;
      //bool isMove = true;

      //while (isMove) {
	
      cout << "(m)ove [start] [end] or (d)raw ? ";

      cin >> in;
      if (in != 'd' && in != 'm') {
	cout << "illegal command, try again" << endl;
	newTurn = false;
	check = true; 
	continue; 
      }
      cout << endl;
      //while (isMove) {
      
      /*while (cin >> in) {
	while (in != 'd' && in != 'm') {
	cout << "illegal command, try again" << endl;
	cout << "(m)ove [start] [end] or (d)raw ? ";
	cin >> in;
	}*/
      // cout << "THIS BE DRAW SIZE BOI" << draw.size() << endl;
      //if the draw pile is empty
      if (draw.size() == 0 || draw.size() < 0) {
	//put the set aside pile in the draw pile 
	draw.set_to_draw(set_aside); 
      }
     
      //if they want to draw 
      if (in == 'd') {
	if (check) {
	  newTurn = true;
	  check = false;
	}
	if (!newTurn && peep[curp].get_size() != 0) {
	  cout << "illegal command, try again" << endl; 
	}else {
	
	//while their hand has less than 5 cards
	
	while (peep[curp].get_size() < 5) {
	  //add hands to the card
	  // if (newTurn) {
	  peep[curp].add_to_Hand(draw.remove());
	  //}else {
	    //newTurn = false; 
	    //continue;
	    
	}
	  
	newTurn = false;
	//isMove = false;
	//}
      }
      }
      //if they want to move 
      //if (in != 0 && in != 10) {
      if (in == 'm') {
	//reads where cards come from and where they should go 
	char source;
	char dest;
	
	cin >> source >> dest;
        newTurn = false;	
	//onceOver = false; 
	if ((source < '0' || source > '9') || (dest < '1' || (dest > '4' && dest < 'a') || dest > 'd'))   {
	  cout << "illegal command, try again" << endl;
	  newTurn = false;
	  continue; 
	} else {
	//if source is stock pile 
	if (source == '0') {
	  //if the destination is a build pile 
	  if (isalpha(dest) && (dest >= 'a' && dest <= 'd') ) {
	    //if the build pile has size less than 12 
	    if (build[dest - 'a'].getSize() < 12) {
	      if ((peep[curp].get_stock_value() != build[dest - 'a'].getSize() + 1)
		  && peep[curp].get_stock_value() != 0) {
		cout << "illegal command, try again" << endl; 
		newTurn = false;
	      }	else {
		build[dest - 'a'].addCard(peep[curp].get_stock());
		if (build[dest - 'a'].getSize() == 12) {
		  set_aside.build_to_set(build[dest - 'a']);
		  cout << "build pile " << dest << " full, set aside" << endl;
		}
		newTurn = false; 
	      //cout << "THIS STOCK SIZE" << peep[curp].get_stock_size() << endl;
	      //checks if the stock size is 0 for a winner
	      }
	      if (!peep[curp].get_stock_size()) {
		cout <<  "GAME OVER - " << peep[curp].getName() << " wins!" << endl;
		return 0;
	      }
	    } else {
	      //cout << " MOVING TO SET ASIDE" << endl;
		//moves build pile to set aside pile 
		set_aside.build_to_set(build[dest-'a']);
		//adds card to new build pile
		if ((peep[curp].get_stock_value() != 1) && peep[curp].get_stock_value() != 0) {
		  cout << "illegal command, try again" << endl;
		  newTurn = false;
		} else {
		  build[dest - 'a'].addCard(peep[curp].get_stock());
		  newTurn = false; 
		}
		}
	  } else {
	    cout << "illegal command, try again" << endl; 
	    newTurn = false;
	  }
	  //card is coming from a discard pile 
	} else if (source > '0' && source < '5') {
	  //card is going to a buildpile 
	  if (isalpha(dest) && (dest >= 'a' && dest <= 'd') ) {
	    if (build[dest - 'a'].getSize() < 12) {
	      if ((peep[curp].get_discard_value(source - '1') != build[dest - 'a'].getSize() + 1                  ) && peep[curp].get_discard_value(source - '1') != 0) {
		cout << "illegal command, try again" << endl; 
	        newTurn = false;
	      } else {
		build[dest - 'a'].addCard(peep[curp].get_discard(source - '1'));
		if (build[dest - 'a'].getSize() == 12) {
		  set_aside.build_to_set(build[dest - 'a']);
		  cout << "build pile " << dest << " full, set aside" << endl; 
		}
		newTurn = false; 
	      }
	    } else {
	      
	      set_aside.build_to_set(build[dest - 'a']);
	      if ((peep[curp].get_discard_value(source - '1') != 1) && peep[curp].get_discard_value(source - '1') != 0) {
                cout << "illegal command, try again" << endl;
	        newTurn = false; 
	      } else {
		build[dest - 'a'].addCard(peep[curp].get_discard(source - '1'));
		newTurn = false; 
	       }
	       }
	  }
	  //card is coming from a hand 
	}else if (source >= '5' && source <= '9') {
	  if ((source - '5') >= peep[curp].get_size()) {
	    cout << "illegal command, try again" << endl;
	    newTurn = false;
	    continue; 
	  }
	  //card is going to a buildpile 
	  if (isalpha(dest) && (dest >= 'a' && dest <= 'd')) {
	    
	    if (build[dest - 'a'].getSize() < 12) {
	       if ((peep[curp].get_hand_value(source - '5') != build[dest - 'a'].getSize() + 1) && peep[curp].get_hand_value(source - '5') != 0) { 
		 cout << "illegal command, try again" << endl; 
	       	 newTurn = false;
	       } else {
		 build[dest - 'a'].addCard(peep[curp].get_hand(source - '5'));
		 if (build[dest - 'a'].getSize() == 12) {
		 set_aside.build_to_set(build[dest - 'a']);
		 cout << "build pile " << dest << " full, set aside" << endl; 
		 }
		 newTurn = false; 
		 
	       }
	    } else {
	      set_aside.build_to_set(build[dest - 'a']);
	       if ((peep[curp].get_hand_value(source - '5') != 1)
		   && peep[curp].get_hand_value(source - '5') != 0) { 
		 cout << "illegal command, try again" << endl; 
	         newTurn = false;
	       } else {
		 build[dest - 'a'].addCard(peep[curp].get_hand(source - '5'));
		 newTurn = false; 
	       }
	       }
	    
	    //card is going to a discard pile 
	  } else if (isdigit(dest) && (dest >= '1' && dest <= '4')) {	    
	    peep[curp].get_hd(source - '5', dest - '1');
	     
	    display(); 
	    //change player turn 
	    if (curp == (nump - 1)) {
	      curp = 0;
	      turn++; 
	       
	      newTurn = true; 
	    } else { 
	    curp++;
	    turn++; 
	    newTurn = true; 
	    }
	  }
	
	}
	
	//cin.get();
	//cin.get(in);
	//cout << "THIS IS IN DER  " << in << endl;
	//if (!cin.get(in)) {
	// cin.putback(in);
	//}
	}
	
       	
	 
      }
    }
  
    //save mode 
    else if (input == 's') {
      cout << "save filename: ";
      string filename;
      cin >> filename; 
      std::ofstream file(filename); 
      
      file << toString();
      file.close();
      return 0; 
    }
    

  }
  cout << "thanks for playing" << endl; 
  return 0;
}
