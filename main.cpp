#include "SkipBoGame.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int checkValidFile(string filename) {
  ifstream file(filename,std::ios::in);
  if(file) {
    file.close();
    return 1; 
  }else {
    return 0; 
  }
}

int main (int argc, char * argv[]) {
  //making sure correct number of arguments 
  if (argc != 5 && argc != 3) {
    cout << "invalid program usage: invalid number of arguments" << endl;
    return 1; 
  }
  
  else if (argc == 3) {
    
    if (checkValidFile(argv[2])){
    SkipBoGame game(argv[1], argv[2]);
    game.play_game(); 
    return 0;
    }else {
    //  cout << "num players is " << atoi(argv[2]) << endl;
     // cout << "stock size is " << atoi(argv[3]) << endl;

      cout << "invalid program usage: can't open input game file" << endl;
      return 1; 
    }
     
  }



  if (checkValidFile(argv[4])) {
    string one = argv[1]; 
    if (one != "true" && one != "false") {
      cout << "invalid program usage: invalid first argument" << endl;
      return 1; 
    }
    int numPlayers = atoi(argv[2]);
    if (numPlayers < 2 || numPlayers > 6){
      cout << "invalid program usage: num players must be 2-6" << endl;
      return 1;
    } else {
      cout << "num players is " << numPlayers << endl;
    }
    int stockSize = atoi(argv[3]);
    if (stockSize < 0 || stockSize > 30) {
      cout << "invalid program usage: bad stock size" << endl;
      return 1;
    } else {
      cout << "stock size is " << stockSize << endl;
    }
      
    SkipBoGame game(argv[1], atoi(argv[2]), atoi(argv[3]), argv[4]);
    game.play_game();
  
  }else {
    cout << "num players is " << atoi(argv[2]) << endl;
    cout << "stock size is " << atoi(argv[3]) << endl;

    cout << "invalid program usage: can't open deck file" << endl;
    return 1; 
								  
  }
}
