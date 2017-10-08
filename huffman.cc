#include "huffman.h"
#include <bits/stdc++.h>
using namespace std;

auto Huffman::construir_alfabeto(string texto){
	unorded_multiset<char> uset;
	auto f = [](const unsigned long& a, const unsigned long& b){
		return a<b;
	};
	multimap<unsigned long, shared_ptr<Node>, decltype(f)>letterCounter(f);
	unordered_set<char> skip;
	for(auto v: uset){
		if(skip.count(v)>0)
			continue;
		skip.insert(v);
		auto count = uset.cout(v);
		auto node = shared_ptr<Node>(new Node(count, v));
		letterCounter.insert(pair<unsigned long, decltype(node)>(
			pair<unsigned long, decltype(node)>(count, node)));
	}
	return letterCounter;
}

template <typename T>
auto Huffman::construir_arvore(T alfabeto){
	while(alfabeto.size()){
		auto it = alfabeto.begin();
		auto esq = *it;
		alfabeto.erase(it);
		it = alfabeto.begin();
		auto dir = *it;
		alfabeto.erase(it);
		auto conta = esq.first + dir.first;
		auto parent = decltype(esq)(conta, shared_ptr<Node>(new Node()));
		parent.second->setWeight(esq.second, dir.second);
		alfabeto.insert(parent);
	}
	return alfabeto.begin()->second;
}

template <typename T>
auto Huffman::construir_dicionario(T rootNode){
	queue<pair<char, unsigned long>> codes;
	encode(rootNode,0,&codes);
	auto dicionario = map<char, unsigned long>();
	while(!codes.empty()){
		auto atual = codes.front();
		dicionario[atual.first] = atual.second;
		codes.pop();
	}
	return dicionario;
}

vector<bool> Huffman::comprime(string texto){
	auto rootNode = constroi_arvore(construir_alfabeto(texto));
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

