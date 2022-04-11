#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cards.h"
using namespace std;

void createBST(CardBST& player1, CardBST& player2,string one, string two);


int main(){
    int num;
    cout << "Menu\n";
    cout << "    1. Test the overloaded comparions for the class Data\n";
    cout << "    2. Test the insert function for the CardBST and also the printInOrder function\n";
    cout << "    3. Test the BST copy constructor\n";
    cout << "    4. Test for the overloaded assignment operator\n";
    cout << "    5. Test the contains function for BST\n";
    cout << "    6. Test for the predecessor function for BST\n";
    cout << "    7. Test for the successor function for BST\n";
    cout << "    8. Test for the remove function for BST\n";
    cout << "    9. Test for the min and max function of BST\n";
    cout << "    10. Test to see if a function can create two BST from two separate files\n";
    cout << "    11. Test for the game being played\n";
    cout << "Enter number to run test\n";
    cin >> num;
    if(num == 1){
        cout << "\nCreates two object type class Data\n";
        cout << "Object Dylan contains h k, and object Alex contains h j\n";
        cout << "Checks if h k < h j which should be false\n";
        Data Dylan, Alex;
        Dylan.setSuit("h");
        Dylan.setValue("k");
        Alex.setSuit("h");
        Alex.setValue("j");
        if((Dylan < Alex))
            cout << "true\n";
        else
            cout << "false\n";
    }
    if(num == 2){
        CardBST player1;
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        cout << "Should also print out from smallest to largest value\n";
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        player1.printInOrder();
        cout << endl;
    }
    if(num == 3){
        CardBST player1;
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        cout << "And creates another BST that contains the first BST as its parameter\n";
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        CardBST player2(player1);
        cout << "First BST information\n";
        player1.printInOrder();
        cout << endl;
        cout << "Second BST information after taking the first BST as its parameter\n";
        player2.printInOrder();
    }
    if(num == 4){
        cout << "\nCreates a first BST with info d 3, h j, h 9\n";
        cout << "Creates second BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        cout << "Then first BST will no have the values of second BST\n";
        CardBST player2, player1;
        cout << "Original first bst\n";
        player2.insert("d", "3");
        player2.insert("h", "j");
        player2.insert("h", "9");
        player2.printInOrder();
        cout << endl;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        cout << "Second BST info\n";
        player1.printInOrder();
        cout << endl;
        player2 = player1;
        cout << "After the assignment operator, first BST info\n";
        player2.printInOrder();
    }
    if(num == 5){
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        CardBST player1;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        cout << "Does the BST contain the node s a\n";
        if(player1.contains("s", "a") == true)
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Answer should be No\n";

        cout << "\nDoes the BST contain the node c a\n";
        if(player1.contains("c", "a") == true)
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Answer should be Yes\n";

        cout << "\nDoes the BST contain the node h 9\n";
        if(player1.contains("h", "9") == true)
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Answer should be Yes\n";

        cout << "\nDoes the BST contain the node c 3\n";
        if(player1.contains("c", "3") == true)
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Answer should be No\n";
        
        cout << "\nDoes the BST contain the node s j\n";
        if(player1.contains("s", "j") == true)
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Answer should be No\n";
    }
    if(num == 6){
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        CardBST player1;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        cout << "predecessor for h 9 is: " << player1.getPredecessor("h", "9") << endl;
        cout << "predecessor for h j is: " << player1.getPredecessor("h", "j") << endl;
        cout << "predecessor for d 3 is: " << player1.getPredecessor("d", "3") << endl;
        cout << "predecessor for c a is: " << player1.getPredecessor("c", "a") << endl;
    }
    if(num == 7){
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        CardBST player1;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        cout <<"successor for c a is: " << player1.getSuccessor("c", "a") << endl;
        cout <<"successor for c k is: " << player1.getSuccessor("c", "k") << endl;
        cout <<"successor for d 3 is: " << player1.getSuccessor("d", "3") << endl;
        cout <<"successor for s 3 is: " << player1.getSuccessor("s", "3") << endl;
        cout <<"successor for h 9 is: " << player1.getSuccessor("h", "9") << endl;
        cout <<"successor for h j is: " << player1.getSuccessor("h", "j") << endl;
    }
    if(num == 8){
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        cout << "Then removes h 9, c k, s 3\n";
        CardBST player1;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        player1.remove("h", "9");
        player1.remove("c", "k");
        player1.remove("s", "3");
        player1.printInOrder();
        cout << endl;
        cout << "Final values left should be c a, d 3, h j\n";
        cout << "\nSecond BST with 30 values from file a1.txt\n";
        cout << "Refer to that file for original BST values\n";
        cout << "Second BST after removing 18 Nodes\n";
        CardBST player2, player3;
        createBST(player2, player3, "a1.txt", "b1.txt");
        player2.remove("c", "a");
        player2.remove("h", "9");
        player2.remove("c", "3");
        player2.remove("s", "q");
        player2.remove("c", "4");
        player2.remove("s", "10");
        player2.remove("c", "7");
        player2.remove("s", "8");
        player2.remove("c", "8");
        player2.remove("s", "5");
        player2.remove("d", "2");
        player2.remove("s", "3");
        player2.remove("d", "3");
        player2.remove("s", "2");
        player2.remove("d", "5");
        player2.remove("d", "k");
        player2.remove("d", "9");
        player2.remove("d", "j");
        player2.printInOrder();
    }
    if(num == 9){
        cout << "\nCreates a BST with card value s 3, c k, c a, d 3, h j, h 9\n";
        CardBST player1;
        player1.insert("s", "3");
        player1.insert("c", "k");
        player1.insert("c", "a");
        player1.insert("d", "3");
        player1.insert("h", "j");
        player1.insert("h", "9");
        cout << "The max node value for this bst is " << player1.MaxInfo() << endl;
        cout << "The min node value for this bst is " << player1.MinInfo() << endl;
    }
    if(num == 10){
        cout << "\nWill create two bst player1 and player2 from files ";
        cout << "alice_cards.txt and bob_cards.txt\n";
        CardBST player1, player2;
        ifstream inStream;
        ifstream inStream2;
        inStream.open("alice_cards.txt");
        inStream2.open("bob_cards.txt");
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
        
        cout << "player1 BST in order\n";
        player1.printInOrder();
        cout << endl;

        cout << "player2 BST in order\n";
        player2.printInOrder();
        cout << endl;
    }
    if(num == 11){
        cout << "\nWill play the final version game with text file ";
        cout << "acards.txt and bcards.txt\n";
        CardBST player1, player2;
        createBST(player1, player2, "acards.txt", "bcards.txt");
        player1.playgame(player2);
    }
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
