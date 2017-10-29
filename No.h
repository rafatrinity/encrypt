//
// Created by rafael on 18/10/17.
//

#ifndef APS_NO_H
#define APS_NO_H
#include <bits/stdc++.h>
using namespace std;
class No {
	No* dir;
	No* esq;
    bool folha;
    char letra; //usado somente nas folhas
    unsigned long qt;
    vector<bool> dicionario;
public:
	No *getDir() const;

	void setDir(No *dir);

	No *getEsq() const;

	void setEsq(No *esq);

	char getLetra() const;

	const vector<bool> &getDicionario() const;

	void setDicionario(const vector<bool> &dicionario);

	unsigned long getQt() const;

	bool ehFolha();

    bool temDir();

    bool temEsq();

	No(No *esq, No *dir, unsigned long qt);

	No(unsigned long qt, char letra);

	No();

};


#endif //APS_NO_H
