//cards.cpp
//Authors: Dylan Cocoletzi
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Data::operator=(const Data& source){
    suit = source.suit;
    value = source.value;
}

bool operator==(const Data& one, const Data& two){
    if((one.suit == two.suit) && (one.value == two.value))
        return true;
    return false;
}

bool operator<(const Data& one, const Data& two){
    string oneSuit = one.suit;
    string oneValue = one.value;
    string twoSuit = two.suit;
    string twoValue = two.value;

    if(one.value == "a")
        oneValue = "1";

    if(two.value == "a")
        twoValue = "1";

    if(one.value == "j")
        oneValue = "11";

    if(two.value == "j")
        twoValue = "11";

    if(one.value == "q")
        oneValue = "12";

    if(two.value == "q")
        twoValue = "12";

    if(one.value == "k")
        oneValue = "13";

    if(two.value == "k")
        twoValue = "13";

    if(one.suit == "h")
        oneSuit = "t";

    if(two.suit == "h")
        twoSuit = "t";

    int oneIntValue = stoi(oneValue);
    int twoIntValue = stoi(twoValue);

    if(oneSuit == twoSuit){
        if(oneIntValue < twoIntValue)
            return true;
    }
    if(oneSuit < twoSuit)
        return true;

    return false;
}

bool operator>(const Data& one, const Data& two){
    string oneSuit = one.suit;
    string oneValue = one.value;
    string twoSuit = two.suit;
    string twoValue = two.value;

    if(one.value == "a")
        oneValue = "1";

    if(two.value == "a")
        twoValue = "1";

    if(one.value == "j")
        oneValue = "11";

    if(two.value == "j")
        twoValue = "11";

    if(one.value == "q")
        oneValue = "12";

    if(two.value == "q")
        twoValue = "12";

    if(one.value == "k")
        oneValue = "13";

    if(two.value == "k")
        twoValue = "13";

    if(one.suit == "h")
        oneSuit = "t";

    if(two.suit == "h")
        twoSuit = "t";

    int oneIntValue = stoi(oneValue);
    int twoIntValue = stoi(twoValue);

    if(oneSuit == twoSuit){
        if(oneIntValue > twoIntValue)
            return true;
    }
    if(oneSuit > twoSuit)
        return true;

    return false;
}

ostream& operator<<(ostream& outs, const Data& source){
    outs << source.suit << " " << source.value;
    return outs;
}

void CardBST::clear(Node *n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

bool CardBST::insert(string suit, string value){
    if(!root){
        root = new Node(suit, value);
        return true;
    }
    return insert(suit, value, root);
}

bool CardBST::insert(string suit, string value, Node *n){
    Data temp(suit, value);
    if(temp == n->info)
        return false;
    if(temp < n->info){
        if(n->left)
            return insert(suit, value, n->left);
        else{
            n->left = new Node(suit, value);
            n->left->parent = n;
            return true;
        }
    }
    else{
        if(n->right)
            return insert(suit, value, n->right);
        else{
            n->right = new Node(suit, value);
            n->right->parent = n;
            return true;
        }
    }
}

void CardBST::printInOrder(Node *n) const{
    if(n){
        printInOrder(n->left);
        cout << n->info << " \n";
        printInOrder(n->right);
    }
}

CardBST::Node* CardBST::getNodeFor(string suit, string value, Node *n)const{
    Data temp(suit, value);
    if(n){
        while(n){
            // cout << temp << endl;
            // cout << n->info << endl;
            if(n->info == temp){
                return n;
            }else if(temp < n->info){
                n = n->left;
            }else{
                n = n->right;
            }
        }
        return NULL;
    }else{
        return NULL;
    }
}

bool CardBST::contains(string suit, string value) const{
    if(getNodeFor(suit, value, root) == NULL)
        return false;
    else
        return true;
}

CardBST::Node* CardBST::getPredecessorNode(string suit, string value){
    Node *n = getNodeFor(suit, value, root);
    if(n){
        if((n->right == nullptr && n->left == nullptr) && n->parent == nullptr){
            return NULL;
        }else if(n->left != nullptr){
            n = n->left;
            while(n->right != nullptr){
                n = n->right;
            }
            return n;
        }else{
            Node *p = n->parent;
            if(p->right != nullptr && p->right->info == n->info){
                return p;
            }else{
                while(!(p->info == root->info)){
                    p = p->parent;
                    if(p->info < n->info){
                        return p;
                    }
                }
                return NULL;
            }
        }
    }else{
        return NULL;
    }
}

Data CardBST::getPredecessor(string suit, string value){
    Data temp("0", "0");
    Node *n = getPredecessorNode(suit, value);
    if(n != nullptr)
        return n->info;
    else
        return temp;
}

CardBST::Node* CardBST::getSuccessorNode(string suit, string value){
    Node *n = getNodeFor(suit, value, root);
    if(n){
        if((n->left == nullptr && n->right == nullptr) && n->parent == nullptr){
            return NULL;
        }else if(n->right != nullptr){
            n = n->right;
            while(n->left != nullptr){
                n = n->left;
            }
            return n;
        }else{
            Node *p = n->parent;
            if(p->left != nullptr && p->left->info == n->info){
                return p;
            }else{
                while(!(p->info == root->info)){
                    p = p->parent;
                    if(p->info > n->info){
                        return p;
                    }
                }
                return NULL;
            }
        }
    }else{
        return NULL;
    }
}

Data CardBST::getSuccessor(string suit, string value){
    Data temp("0", "0");
    Node *n = getSuccessorNode(suit, value);
    if(n != nullptr)
        return n->info;
    else   
        return temp;
}

bool CardBST::remove(string suit, string value){
    Node *n = getNodeFor(suit, value, root);
    if(n){
        if((n->left == nullptr && n->right == nullptr) && n->parent == nullptr){
            delete n;
            root = nullptr;
            return true;
        }else if(n->right == nullptr && n->left == nullptr){
            Node *p = n->parent;
            if((p->right != nullptr) && p->right->info == n->info){
                delete n;
                p->right = nullptr;
                return true;
            }else{
                delete n;
                p->left = nullptr;
                return true;
            }
        }else {
            if(n->right == nullptr || n->left == nullptr){
                if(n->parent == nullptr){
                    if(n->left != nullptr){
                        n->left->parent = nullptr;
                        root = n->left;
                        delete n;
                        return true;
                    }else{
                        n->right->parent = nullptr;
                        root = n->right;
                        delete n;
                        return true;
                    }
                }else{
                    if(n->left != nullptr){
                        Node *c = n->left;
                        Node *p = n->parent;
                        if(p->info < n->info){
                            p->right = c;
                            c->parent = p;
                            delete n;
                            return true;
                        }else{
                            p->left = c;
                            c->parent = p;
                            delete n;
                            return true;
                        }
                    }else{
                        Node *c = n->right;
                        Node *p = n->parent;
                        if(p->info < n->info){
                            p->right = c;
                            c->parent = p;
                            delete n;
                            return true;
                        }else{
                            p->left = c;
                            c->parent = p;
                            delete n;
                            return true;
                        }
                    }
                }
            }else if((n->right != nullptr && n->left != nullptr) && n->parent == nullptr){
                if(n->right->left == nullptr){
                    Node *newRoot = n->right;
                    Node *c = n->left;
                    newRoot->left = c;
                    c->parent = newRoot;
                    newRoot->parent = nullptr;
                    root = newRoot;
                    delete n;
                    return true;
                }else{
                    Node *newRoot = n->right;
                    Node *c = n->left;
                    Node *p = getSuccessorNode(n->info.getSuit(), n->info.getValue());
                    p->left = c;
                    c->parent = p;
                    newRoot->parent = nullptr;
                    root = newRoot;
                    delete n;
                    return true;
                }
            }else{
                Node *newHead = getSuccessorNode(n->info.getSuit(), n->info.getValue());
                Node *c = n->left;
                Node *Head = n->right;
                Node *Star = n->parent;
                if(n->info < Star->info){
                    Star->left = Head;// maybe should be Star->right
                    Head->parent = Star;
                    c->parent = newHead;
                    newHead->left = c;
                    delete n;
                    return true;
                }else{
                    Star->right = Head;
                    Head->parent = Star;
                    c->parent = newHead;
                    newHead->left = c;
                    delete n;
                    return true;
                }
            }
        }
    }else{
        return false; 
    }
}

CardBST::Node* CardBST::copy(const Node *n){
    if(n == nullptr)
        return nullptr;
    Node *copyNode = new Node;
    copyNode->info = n->info;
    copyNode->left = copy(n->left);
    copyNode->right = copy(n->right);
    return copyNode;
}

CardBST::CardBST(const CardBST& source){
    root = copy(source.root);
}

CardBST CardBST::operator=(const CardBST& n){
    if(n.root == nullptr){
        clear(root);
        return *this;
    }
    clear(root);
    root = copy(n.root);
    return *this;
}

CardBST::Node* CardBST::getMaxNode()const{
    Node *n = root;
    while(n && n->right){
        n = n->right;
    }
    return n;
}

Data CardBST::MaxInfo()const{
    Node *n = getMaxNode();
    return n->info;
}

CardBST::Node* CardBST::getMinNode()const{
    Node *n = root;
    while(n && n->left){
        n = n->left;
    }
    return n;
}

Data CardBST::MinInfo()const{
    Node *n = getMinNode();
    return n->info;
}

void CardBST::playgame(CardBST& n){
    if(this->root == nullptr || n.root == nullptr){
        cout << "Alice's cards:\n";
        this->printInOrder();
        cout << endl;
        cout << "Bob's cards:\n";
        n.printInOrder();
    }else{
        Node *playerOne = this->getMinNode();
        Node *playerTwo = n.getMaxNode();
        int turns = 1;
        while((this->root != nullptr && n.root != nullptr) && (playerOne != nullptr && playerTwo != nullptr)){
            if(turns % 2 != 0){
                if(n.contains(playerOne->info.getSuit(), playerOne->info.getValue())){
                    cout << "Alice picked matching card " << playerOne->info << endl;
                    if(playerOne->info == playerTwo->info){
                        Node *temp = playerTwo;
                        Node *temp2 = playerOne;
                        playerTwo = n.getPredecessorNode(playerTwo->info.getSuit(), playerTwo->info.getValue());
                        n.remove(temp->info.getSuit(), temp->info.getValue());
                        playerOne = this->getSuccessorNode(playerOne->info.getSuit(), playerOne->info.getValue());
                        this->remove(temp2->info.getSuit(), temp2->info.getValue());
                        turns = turns + 1;
                    }else{
                        Node *temp = playerOne;
                        n.remove(playerOne->info.getSuit(), playerOne->info.getValue());
                        playerOne = this->getSuccessorNode(playerOne->info.getSuit(), playerOne->info.getValue());
                        this->remove(temp->info.getSuit(), temp->info.getValue());
                        turns = turns + 1;
                    }
                }else{
                    Node *max = this->getMaxNode();
                    if(playerOne->info == max->info)
                        playerOne = nullptr;
                    else
                        playerOne = this->getSuccessorNode(playerOne->info.getSuit(), playerOne->info.getValue());
                }
            }else{
                if(this->contains(playerTwo->info.getSuit(), playerTwo->info.getValue())){
                    cout << "Bob picked matching card " << playerTwo->info << endl;
                    if(playerTwo->info == playerOne->info){
                        Node *temp = playerOne;
                        Node *temp2 = playerTwo;
                        playerOne = this->getSuccessorNode(playerOne->info.getSuit(), playerTwo->info.getValue());
                        this->remove(temp->info.getSuit(), temp->info.getValue());
                        playerTwo = n.getPredecessorNode(temp2->info.getSuit(), temp2->info.getValue());
                        n.remove(temp2->info.getSuit(), temp2->info.getValue());
                        turns = turns + 1;
                    }else{
                        Node *temp2 = playerTwo;
                        this->remove(playerTwo->info.getSuit(), playerTwo->info.getValue());
                        playerTwo = n.getPredecessorNode(playerTwo->info.getSuit(), playerTwo->info.getValue());
                        n.remove(temp2->info.getSuit(), temp2->info.getValue());
                        turns = turns + 1;
                    }
                }else{
                    Node *min = n.getMinNode();
                    if(playerTwo->info == min->info)
                        playerTwo = nullptr;
                    else
                        playerTwo = n.getPredecessorNode(playerTwo->info.getSuit(), playerTwo->info.getValue());
                }
            }
        }
        cout << endl;
        cout << "Alice's cards:\n";
        this->printInOrder();
        cout << endl;
        cout << "Bob's cards:\n";
        n.printInOrder();
    }
}
