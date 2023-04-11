//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_SMLLIST_H
#define DSA_SMLLIST_H
#include "MatrixNode.h"
#include <vector>


class MatrixLinkedList {
private:
    MatrixNode* head;
    int num_rows;
    int num_cols;
    unsigned int size;

public:
    MatrixLinkedList(); // this->head = nullptr;
    MatrixLinkedList(int num_rows, int num_cols, int row, int col, int data);
    MatrixLinkedList(std::vector<std::vector<int> > two_dem_vector);
    ~MatrixLinkedList();

    //getter setter center
    int getNumRows();
    int getNumCols();

    //returns next row with non-zero entry in col
    int nextRowInCol(int col, int cur_row);

    //returns next col with non-zero entry in row
    int nextColInRow(int row, int cur_col);


};


#endif //DSA_SMLLIST_H
