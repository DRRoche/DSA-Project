//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_NODE_H
#define DSA_NODE_H


class MatrixNode{
private:
    int data;
    MatrixNode* next;
    //additional needed data for row and cols
    int row;
    int col;

    friend class MatrixLinkedList;
public:
    MatrixNode();
    // Overloading
    MatrixNode(int row, int col, int data);
    MatrixNode(int row, int col, int data, MatrixNode* next);
    ~MatrixNode();

    //getter and setter
    int getData();
    void setData(int data);
    int getRow();
    void setRow(int data);
    int getCol();
    void setCol(int data);

};


#endif //DSA_NODE_H
