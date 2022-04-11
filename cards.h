//cards.h
//Authors: Dylan Cocoletzi
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Data{
    public:
        Data():suit("0"), value("0"){}
        Data(string s, string v):suit(s), value(v){}
        void setSuit(string s){suit = s;}
        void setValue(string v){value = v;}
        string getSuit(){return suit;}
        string getValue(){return value;}
        friend bool operator<(const Data& one, const Data& two);
        friend bool operator>(const Data& one, const Data& two);
        friend bool operator==(const Data& one, const Data& two);
        friend ostream& operator<<(ostream& outs, const Data&source);
        void operator=(const Data& source);
    private:
        string suit;
        string value;
};

class CardBST{
    public:
        CardBST():root(0){}
        ~CardBST(){clear(root);}
        bool insert(string suit, string value);
        void printInOrder() const{printInOrder(root);}
        bool contains(string suit, string value) const;
        Data getPredecessor(string suit, string value);
        Data getSuccessor(string suit, string value);
        bool remove(string suit, string value);
        CardBST(const CardBST& source);
        CardBST operator=(const CardBST& n);
        Data MaxInfo()const;
        Data MinInfo()const;
        void playgame(CardBST& n);
    private:
        struct Node {
            Data info;
            Node *left, *right, *parent; 
            Node(string s= "0", string v = "0"):info(s, v), left(0), right(0), parent(0){}
        };
        Node *root;
        Node* getNodeFor(string suit, string value, Node *n) const;
        void clear(Node *n);
        bool insert(string suit, string value, Node *n);
        void printInOrder(Node *n) const;
        Node* getPredecessorNode(string suit, string value);
        Node* getSuccessorNode(string suit, string value);
        Node* copy(const Node *n);
        Node* getMaxNode()const;
        Node* getMinNode()const;
};

#endif
