//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_NODE_H
#define DSA_NODE_H


class Node{
private:
    int data;
    Node* next;
    //additional needed data for row and cols
    int row;
    int col;

    friend class SMLList;
public:
    Node();
    // Overloading
    Node(int data);
    Node(int data, Node* next);
    ~Node();
};


#endif //DSA_NODE_H
