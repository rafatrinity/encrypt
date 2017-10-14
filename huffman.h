#ifndef HUFMAN
#define HUFMAN
#include <bits/stdc++.h>
using namespace std;
typedef class Huffman{
    auto dicionario;
    auto overplus;
    auto tree;
public:
    auto construir_alfabeto(string texto);
    template <typename T>
    auto construir_arvore(T alfabeto);
    template <typename T>
    auto construir_dicionario(T rootNode);
    vector<bool> comprime(string texto);
    template <typename T, typename U>
    void cod(T n, unsigned long code, queue<U> *codes);
    auto getTree();
    auto exedente();
    auto obter_dicionario();
} huff;
#endif