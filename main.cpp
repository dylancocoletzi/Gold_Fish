#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cards.h"

void createBST(CardBST& player1, CardBST& player2,string one, string two);

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  CardBST player1, player2;
  createBST(player1, player2, argc[1], argc[2]);
  player1.playgame(player2);
  return 0;
}

void createBST(CardBST& player1, CardBST& player2,string one,string two){
    ifstream inStream;
    ifstream inStream2;
    inStream.open(one);
    inStream2.open(two);
    vector<string> player1Info;
    vector<string> player2Info;
    string elements;
    string elements2;
    while(inStream >> elements)
        player1Info.push_back(elements);

    while(inStream2 >> elements2)
        player2Info.push_back(elements2);

    for(long unsigned int i=0; i < player1Info.size(); i = i + 2)
        player1.insert(player1Info[i], player1Info[i + 1]);

    for(long unsigned int i=0; i < player2Info.size(); i = i + 2)
        player2.insert(player2Info[i], player2Info[i + 1]);

    inStream.close();
    inStream2.close();
}
