#ifndef ENCRYPT_NODE_H
#define ENCRYPT_NODE_H
#include <bits/stdc++.h>
using namespace std;
auto *esq;
auto *dir;
auto letra;
class Node{
public:
    auto setWeight(auto &esq, auto &dir);
    auto getRight();
    auto getLeft();
    auto getLetter();
    auto hasLeft();
    auto hasRight();
    Node(auto count, auto v);
    Node();
};
#endif //ENCRYPT_NODE_H
