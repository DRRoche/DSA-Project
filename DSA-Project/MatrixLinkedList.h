//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_SMLLIST_H
#define DSA_SMLLIST_H
#include "MatrixNode.h"
#include <vector>
#include <vector>
#include <string>

class MatrixLinkedList {
private:
    MatrixNode* head;
    int num_rows;
    int num_cols;
    //unsigned int size;

public:
    MatrixLinkedList(); // this->head = nullptr;
    MatrixLinkedList(int num_rows, int num_cols);
    MatrixLinkedList(std::vector<std::vector<int> > two_dem_vector);
    ~MatrixLinkedList();

    //getter setter center
    int getNumRows();
    int getNumCols();

    //
    void push_back(int row, int col, int data);

    //returns next row with non-zero entry in col
    int nextRowInCol(int col, int cur_row);

    //returns next col with non-zero entry in row
    int nextColInRow(int row, int cur_col);

    //print matrix
    std::string to_string();
};


#endif //DSA_SMLLIST_H
