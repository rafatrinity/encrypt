#ifndef HUFFMAN
#define HUFFMAN
#include <bits/stdc++.h>
#include "Node.h"
//#include "huffman.cc"

using namespace std;
class Huffman{
    unordered_map<char, unsigned long> dicionario;
    int overplus;
    class Node* tree;
public:
    auto construir_alfabeto(string texto);
    template <typename T>
    auto construir_dicionario(T rootNode);
    vector<bool> comprime(string texto);
    template <typename T, typename U>
    void cod(T n, unsigned long code, queue<U> *codes);
    class Node* getTree();
    int exedente();
    unordered_map<char, unsigned long> obter_dicionario();
    string descomprime(deque<bool> bits);
    char decod(list<bool> mascara, shared_ptr<Node> atual);
};
#endif