//
// Created by matt cordeiro on 4/2/23.
//

#include <iostream>
#include "MatrixLinkedList.h"

//constructor
MatrixLinkedList::MatrixLinkedList() {
    this -> head = nullptr;
    this->num_rows = 0;
    this->num_cols = 0;
}

//constructor with a single digit aka a 1x1 matrix
MatrixLinkedList::MatrixLinkedList(int num_rows, int num_cols) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;
    this-> head = nullptr;
}

//2D vector constructor to fill in the data, making our robust matrix
MatrixLinkedList::MatrixLinkedList(std::vector<std::vector<int> > v_matrix) {
    this->num_rows = v_matrix.size();
    this->num_cols = v_matrix[0].size();
    this -> head = nullptr;

    MatrixNode *temp = head;
    for(int i = 0; i<v_matrix.size(); i++){

        for(int j = 0; j<v_matrix[i].size(); j++){
            if (v_matrix[i][j] != 0) {
                if (head == nullptr) {
                    head = new MatrixNode(i, j, v_matrix[i][j], nullptr);
                    temp = head;
                }
                else {
                    temp->next = new MatrixNode(i, j, v_matrix[i][j], nullptr);
                    temp = temp->next;
                }
            }

        }
    }
}

MatrixLinkedList::~MatrixLinkedList() {
    //this may need to be changed if someone can just double-check
    delete this->head;
}

int MatrixLinkedList::getNumRows() {
    return this->num_rows;
}

int MatrixLinkedList::getNumCols() {
    return this->num_cols;
}

void MatrixLinkedList::push_back(int row, int col, int data)
{
    MatrixNode* temp = this->head;

    if (head == nullptr) {
        this->head = new MatrixNode(row, col, data);
    }
    else {
        while (temp->next != nullptr) temp = temp->next;
        temp->next = new MatrixNode(row, col, data);
    }

}

int MatrixLinkedList::nextRowInCol(int col, int row) {
    MatrixNode* temp = head;
    int entry = 0;

    while (temp->getRow() < row && temp->next != nullptr) temp = temp->next;
    while (temp->getRow() == row  && temp->getCol() < col && temp->next != nullptr) temp = temp->next;

    if (temp->getRow() == row && temp->getCol() == col) entry = temp->data;

    return entry;
}

int MatrixLinkedList::nextColInRow(int row, int col) {
    MatrixNode* temp = head;
    int entry = 0;

    while ((temp->getCol() < col || temp->getRow() < row) && temp->next != nullptr) temp = temp->next;

    if (temp->getRow() == row && temp->getCol() == col ) entry = temp->data;

    return entry;
}

std::string MatrixLinkedList::to_string(){
    MatrixNode* temp = head;
    std::string str = "";

    if(head == nullptr){
        str = "No matrix to print\n\n";
    }
    else {
        for (int i = 0; i < this->num_rows; i++) {
            for (int j = 0; j < this->num_cols; j++) {
                if (temp->getRow() == i && temp->getCol() == j) {
                    str += std::to_string(temp->data) + " ";
                    if (temp->next != nullptr) temp = temp->next;
                } else str += "0 ";
            }
            str += "\n";
        }
    }

    return str;
}

