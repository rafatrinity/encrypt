#ifndef HUF_C
#define HUF_C
#include <bits/stdc++.h>
#include "huffman.h"
#include "msg.h"

using namespace std;

auto Huffman::construir_alfabeto(string texto){
	unordered_multiset<char> conjunto;
    for(auto c : texto)
        conjunto.insert(c);
	auto f = [](const unsigned long& a, const unsigned long& b){
		return a<b;
	};
	multimap<unsigned long, shared_ptr<Node>, decltype(f)> letterCounter(f);
	unordered_set<char> skip;
	for(auto v: conjunto){
		if(skip.count(v)>0)
			continue;
		skip.insert(v);
		auto count = conjunto.count(v);
		auto node = shared_ptr<Node>(new Node(count, v));
		letterCounter.insert(pair<unsigned long, decltype(node)>(
			pair<unsigned long, decltype(node)>(count, node)));
	}
	return letterCounter;
}

template <typename T>
auto Huffman::construir_arvore(T alfabeto){
	while(alfabeto.size() > 1){
		auto it = alfabeto.begin();
		auto esq = *it;
		alfabeto.erase(it);
		it = alfabeto.begin();
		auto dir = *it;
		alfabeto.erase(it);
		auto conta = esq.first + dir.first;
		auto parent;
        parent = decltype(esq)(conta, shared_ptr<Node>(new Node()));
		parent.second->setWeight(esq.second, dir.second);
		alfabeto.insert(parent);
	}
	return alfabeto.begin()->second;
}

template <typename T>
auto Huffman::construir_dicionario(T rootNode){
	queue<pair<char, unsigned long>> codes;
	cod(rootNode,0,&codes);
	auto dicionario = unordered_map<char, unsigned long>();
	while(!codes.empty()){
		auto atual = static_cast<pair<char, unsigned long> &&>(codes.front());
		dicionario[atual.first] = atual.second;
		codes.pop();
	}
	return dicionario;
}

vector<bool> Huffman::comprime(string texto){
	auto rootNode = construir_arvore(construir_alfabeto(texto));
	this->dicionario = construir_dicionario(rootNode);
	vector<bool> resultado;
	for(auto c: texto){
		auto bits = dicionario[c];
		if(!bits)
			resultado.push_back(0);
		else{
			vector<bool> subset;
			while(bits){
				bool bit = static_cast<bool>(bits & 1);
				subset.push_back(bit);
				bits>>=1;
			}
			reverse(subset.begin(),subset.end());
			resultado.insert(resultado.end(), subset.begin(), subset.end());
		}
	}
	this->tree = rootNode;
	this->overplus = char(8-resultado.size()%8);
	return resultado;
}

template <typename T, typename U>
void Huffman::cod(T n, unsigned long code, queue<U> *codes){
 if(n->hasLeft())
     cod(n->getLeft(), code << 1,codes);
 if(n->hasRight())
     cod(n->getRight(), (code << 1) +1,codes);
 if(!n->hasLeft()&&!n->hasRight())
     codes->push(U(n->getLetter(),code));
}

char Huffman::decod(list<bool> mascara, shared_ptr<Node> atual){
    if(atual == nullptr)
        return '\0';
    if(!atual->hasLeft() && !atual->hasRight())
        return atual->getLetter();
    if(mascara.empty())
        return '\0';
    bool path = mascara.front();
    mascara.pop_front();
    return this->decod(mascara, path ? atual->getRight() : atual->getLeft());
}

auto Huffman::getTree(){
    return tree;
}

string Huffman::descomprime(deque<bool> bits){
    if(this->tree == nullptr)
        erro(1);
    for (int i = 0; i < this->overplus; i++)
        bits.pop_back();
    string resultado;
    list<bool> mascara;
    while(!bits.empty()) {
        mascara.push_back(reinterpret_cast<bool &&>(bits.front()));
        char letra = decod(list <bool>(mascara), tree);
        if (letra != '\0') {
            resultado += letra;
            mascara.clear();
        }
        bits.pop_front();
    }
    return resultado;
}

int Huffman::exedente() {
    return this->overplus;
}
unordered_map<char, unsigned long> Huffman::obter_dicionario(){
    return this->dicionario;
};

#endif