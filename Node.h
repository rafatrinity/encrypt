#ifndef ENCRYPT_NODE_H
#define ENCRYPT_NODE_H
#include <bits/stdc++.h>
using namespace std;
class Node* esq;
class Node* dir;
char letra;
class Node{
public:
    void setWeight(class Node* esq, class Node* dir);
    class Node* getRight();
    auto getLeft();
    auto getLetter();
    bool hasLeft();
    bool hasRight();
    Node(int count, int v);
    Node();
};
#endif //ENCRYPT_NODE_H
