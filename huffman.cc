/*
 * Created by Rafael Trindade on 21/10/17.
 * APS estrutura de dados
 * Universidade: UniCarioca
 * Professor: Ricardo Mesquita
 * https://github.com/rafatrinity
 */

#include "No.cc"
#include "huffman.h"
#include "aux.h"
#include "msg.h"
auto h = new Huffman;
template <typename U>
void codificar(No* no, unsigned long code, queue<U> *codes);

auto gerar_alfabeto(string texto) {
    //separa os caracteres
	cout<<"gerando alfabeto\n";
	unordered_multiset<char> conjunto;
	for(auto c : texto)
		conjunto.insert(c);

	auto x=[](const unsigned long&a, const unsigned long&b){//função de ordenação do map
		return a<b;
	};

	unordered_set<char> skip;
	multimap<unsigned long, No*, decltype(x)>  arv(x);

    for(auto v: conjunto){//percorre os caracteres
    	if(skip.count(v)>0)
    		continue;
    	skip.insert(v);
        unsigned long count = conjunto.count(v);//conta os caracteres
        auto s = new No(count, v);//cria nó
        arv.insert(pair<unsigned long, decltype(s)>(
        pair<unsigned long, decltype(s)>(count, s))); //insere nó na lista
    }
    for(const auto &n: arv)
    	cout<<n.second->getLetra()<<n.second->getQt()<<", ";
    cout<<endl;
    return arv;
}

template<typename T>
No* gerar_arvore(T folhas){
	cout<<"gerando arvore\n";
	while(true){
        auto it=folhas.begin();//cria um interador apontando pro início da lista
        auto esq=*it;//atribui o valor do iterador
        folhas.erase(it);//remove o primeiro elemento da lista, mas não apaga ele.

        it=folhas.begin();//repete o passo anterior
        auto dir=*it;
        folhas.erase(it);

        auto soma=esq.second->getQt() + dir.second->getQt();//soma as frequencias
        auto raiz = new No(esq.second,dir.second,soma);//cria novo nó
        auto m=decltype(esq)(soma,raiz);
        folhas.insert(m);//insere o novo nó na lista
        if(folhas.size() <= 1)
        	return m.second;
    }
}

template <typename U>
void codificar(No* no, string code, queue<U> *codes){
	if(no->temEsq())
		codificar(no->getEsq(), code+'0',codes);
	if(!no->temEsq()&&!no->temDir()){
		cout<<no->getLetra()<<" "<<code<<endl;
		codes->push(U(no->getLetra(), code));
	}
	if(no->temDir())
		codificar(no->getDir(), code+'1',codes);
}


unordered_map<char, string> construir_dicionario(No* root){
	aviso(4);
    queue<pair<char, string>> codes;//cria uma fila de pares
    string s;
    codificar(root,s,&codes);
    unordered_map<char, string> dicionario;
    while(!codes.empty()){
    	auto atual = static_cast<pair<char, string> &&>(codes.front());
    	dicionario[atual.first] = atual.second;
    	codes.pop();
    }
    return dicionario;
}

deque<bool> comprime(string texto){
	No* rootNode = gerar_arvore(gerar_alfabeto(texto));
	auto dicionario = construir_dicionario(rootNode);
	deque<bool> resultado;
	for(auto c: texto){
		auto bits = dicionario[c];
		vector<bool> subset;
		for(auto n: bits){
			if(n=='1')
				subset.push_back(true);
			else if(n=='0')
				subset.push_back(false);
		}
		resultado.insert(resultado.end(), subset.begin(), subset.end());
	}
	h->arvore=rootNode;
	h->extra=(char(8-resultado.size()%8));
	for(auto a: resultado)
		cout<<a;
	cout<<"\nbits extras "<<h->extra<<endl;
	return resultado;
}

char decodificar(list<bool> mascara, No* atual){
	if(atual == nullptr)
		return '\0';
	if(!atual->temEsq()&&!atual->temDir())
		return atual->getLetra();
	if(mascara.empty())
		return '\0';
	bool path = mascara.front();
	mascara.pop_front();
	return decodificar(mascara, path ? atual->getDir() : atual->getEsq());
}

void descomprime(deque<bool> bits){
	aviso(6);
	for (int i = 0; i < h->extra ; i++)
		bits.pop_back();
	string resultado;
	list<bool> mascara;
	while(!bits.empty()) {
		mascara.push_back(reinterpret_cast<bool &&>(bits.front()));
		char letra = decodificar(list<bool> (mascara), h->arvore);
		if (letra != '\0') {
			resultado += letra;
			mascara.clear();
		}
		bits.pop_front();
	}
	sucesso(resultado);
	getchar();
	getchar();
}