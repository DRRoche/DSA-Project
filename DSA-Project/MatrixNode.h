//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_NODE_H
#define DSA_NODE_H


class MatrixNode{
private:
    int row;
    int col;
    int data;
    MatrixNode* next;


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
    void setRow(int row);
    int getCol();
    void setCol(int col);

};


#endif //DSA_NODE_H
