//
// Created by matt cordeiro on 4/2/23.
//

#include "SMLList.h"
#include <vector>

//constructor
MatrixLinkedList::MatrixLinkedList() {
    this -> head = nullptr;
    this -> size = 0;
    this->num_rows = 0;
    this->num_cols = 0;
}

//constructor with a single digit aka a 1x1 matrix
MatrixLinkedList::MatrixLinkedList(int num_rows, int num_cols, int row, int col, int data) {
    this -> size = 1;
    this->num_rows = 1;
    this->num_cols = 1;
    this-> head = new MatrixNode(0,0,data);
}

//2D vector constructor to fill in the data, making our robust matrix
MatrixLinkedList::MatrixLinkedList(std::vector<std::vector<int> > two_dem_vector) {
    this -> head = new MatrixNode(0,0, two_dem_vector[0][0]);
    this -> size = two_dem_vector.size();
    MatrixNode *temp = head;
    for(int i = 1; i<two_dem_vector.size(); i++){
        num_rows++;
        for(int j = 1; j<two_dem_vector.size(); j++){
            num_cols++;
            //MatrixNode wants data, so it will pull the elements at iteration
            temp->next = new MatrixNode(i,j,two_dem_vector[i][j]);
            temp=temp->next;
        }
    }
}

MatrixLinkedList::~MatrixLinkedList() {
    //this may need to be changed if someone can just double-check
    delete this->head;
}

int MatrixLinkedList::getNumRows() {
    return num_rows;
}

int MatrixLinkedList::getNumCols(std::vector<std::vector<int> > tempMatrix) {
    return num_cols;
}

int MatrixLinkedList::nextRowInCol(int col, int cur_row) {
    //given col and our current row
    int next_row = cur_row;
    //we want to create a variable to hold the next row based on the current and then increment
    next_row++;
    //if the next_row is greater or equal to some defining size, then we want to wrap around.
    if(next_row >= num_rows){
        //starts us back at the first index of the matrix.
        next_row = 0;
    }
    return next_row;
}

int MatrixLinkedList::nextColInRow(int row, int cur_col) {
    //given row and our current column
    int next_col = cur_col;
    //we want to create a variable to hold the next column based on the current and then increment
    next_col++;
    //if the next_col is greater or equal to some defining size, then we want to wrap around.
    if(next_col >= num_cols){
        //starts us back at the first index of the matrix.
        next_col = 0;
    }
    return next_col;
}


