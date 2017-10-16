//
// Created by rafael on 14/10/17.
//

#include "Node.h"

class Node* Node::getRight(){
    return dir;
}

class Node* Node::getLeft() {
    return esq;
}

char Node::getLetter() {
    return letra;
}
void Node::setWeight(class Node* esq, class Node* dir){

}

bool Node::hasLeft() {
    if(esq==nullptr)
        return 0;
    return 1;
}

bool Node::hasRight(){
    if(dir==nullptr)
        return 0;
    return 1;
}

Node::Node() {
    esq = nullptr;
    dir = nullptr;
    letra = nullptr;
}

Node::Node(int count, int v) {

}
