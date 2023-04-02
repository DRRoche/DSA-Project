//
// Created by matt cordeiro on 4/2/23.
//

#include "SMLList.h"

//constructor
SMLList::SMLList() {
    this -> head = nullptr;
    this -> size = 0;
}

//constructor with a single digit aka a 1x1 matrix
SMLList::SMLList(int data) {
    this -> size = 1;
    this-> head = new Node(data);
}

//2D vector constructor to fill in the data, making our robust matrix
SMLList::SMLList(std::vector<std::vector<int> > twoDemVector) {
    this -> head = new Node(twoDemVector[0][0]);
    this -> size = twoDemVector.size();
    Node *temp = head;
    for(int i = 1; i<twoDemVector.size(); i++){
        for(int j = 1; j<twoDemVector.size(); j++){
            temp->next = new Node(twoDemVector[i][j]);
            temp=temp->next;
        }
    }
}

SMLList::~SMLList() {
    //this may need to be changed if someone can just double-check
    delete this->head;
}

//at least matrix addition and matrix multiplication

