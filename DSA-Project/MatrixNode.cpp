//
// Created by matt cordeiro on 4/2/23.
//

#include "MatrixNode.h"
// Default constructor
MatrixNode::MatrixNode(){
    this->data = 0;
    this->next = nullptr;
    this->row = 0;
    this->col = 0;
}

MatrixNode::MatrixNode(int row, int col, int data){
    this->data = data;
    this->next = nullptr;
    this->row = row = 0;
    this->col = col = 0;
}

//this may need a tweak but for right now it'll do
MatrixNode::MatrixNode(int row, int col, int data, MatrixNode* next){
    this->data = data;
    this->next = next;
    this->row = row;
    this->col = col;
}

MatrixNode::~MatrixNode(){
        delete this->next;
}

//getter setter section, open to addition to things that are missing
int MatrixNode::getData() {
    return this->data;
}

void MatrixNode::setData(int data) {
    this->data = data;
}

//row set and get
int MatrixNode::getRow() {
    return this->row;
}

void MatrixNode::setRow(int num_row) {
    this->row = num_row;
}

//row set and get
int MatrixNode::getCol() {
    return this->col;
}

void MatrixNode::setCol(int num_col) {
    this->col = num_col;
}
