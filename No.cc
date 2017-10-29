//
// Created by rafael on 18/10/17.
// 

#include "No.h"
using namespace std;

No *No::getDir() const {
    return No::dir;
}

void No::setDir(No *d) {
    No::dir = d;
}

No *No::getEsq() const {
    return No::esq;
}

void No::setEsq(No *e) {
    No::esq = e;
}

char No::getLetra() const {
    return No::letra;
}

unsigned long No::getQt() const {
    return No::qt;
}

No::No(unsigned long qt, char letra) {
    No::letra = letra;
    No::qt = qt;
    No::folha=true;
    No::esq = nullptr;
    No::dir = nullptr;
}

bool No::ehFolha() {
    return No::folha;
}

No::No(No *e, No *d, unsigned long qt) {
    No::esq=e;
    No::dir=d;
    No::qt=qt;
}

const vector<bool> &No::getDicionario() const {
    return dicionario;
}

void No::setDicionario(const vector<bool> &dicionario) {
    No::dicionario = dicionario;
}

bool No::temDir() {
    return No::dir != nullptr;
}

bool No::temEsq() {
    return No::esq != nullptr;
}

No::No() = default;



