//
// Created by matt cordeiro on 4/2/23.
//

#include "node.h"
// Default constructor
Node::Node(){
    this->data = 0;
    this->next = nullptr;
    this->row = 0;
    this->col = 0;
}

Node::Node(int data){
    this->data = data;
    this->next = nullptr;
    this->row = 0;
    this->col = 0;
}

//this may need a tweak but for right now it'll do
Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
    this->row = 0;
    this->col = 0;
}

Node::~Node(){
    if(this->next != nullptr){
        delete this->next;
    }
}