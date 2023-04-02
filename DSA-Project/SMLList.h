//
// Created by matt cordeiro on 4/2/23.
//

#ifndef DSA_SMLLIST_H
#define DSA_SMLLIST_H
#include "node.h"
#include <vector>


class SMLList {
private:
    Node* head;
    unsigned int size;

public:
    SMLList(); // this->head = nullptr;
    SMLList(int data);
    SMLList(std::vector<std::vector<int> > twoDemVector);
    ~SMLList();

    void push_front(int data);
    void push_back(int data);
    void insert(int data, int idx); // For any `idx` > `size`, append the value
    void remove(int data);
    bool contains(int data);
    int get_size();
    std::string to_string();
};


#endif //DSA_SMLLIST_H
