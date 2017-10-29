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

bool ordenar(No *a, No *b){//ordena a lista pelo parametro qt
	return a->getQt() > b->getQt();
}

list<No*> gerar_alfabeto(string texto) {
    //separa os caracteres
	cout<<"gerando alfabeto\n";
	unordered_multiset<char> conjunto;
	for(auto c : texto)
		conjunto.insert(c);

	unordered_set<char> skip;
	list<No*> arv;

    for(auto v: conjunto){//percorre os caracteres
    	if(skip.count(v)>0)
    		continue;
    	skip.insert(v);
        unsigned long count = conjunto.count(v);//conta os caracteres
        auto s = new No(count, v);//cria nó
        arv.push_back(s);//insere nó na lista
    }
    arv.sort(ordenar);
    for(const auto &n: arv)
    	cout<<n->getLetra()<<n->getQt()<<", ";
    cout<<endl;
    return arv;
}

No* gerar_arvore(list<No*> folhas){
	cout<<"gerando arvore\n";
	while(true){
        auto it=folhas.begin();//cria um interador apontando pro início da lista
        auto esq=*it;//atribui o valor do iterador
        folhas.erase(it);//remove o primeiro elemento da lista, mas não apaga ele.

        it=folhas.begin();//repete o passo anterior
        auto dir=*it;
        folhas.erase(it);

        auto soma=esq->getQt() + dir->getQt();//pega os 2 primeiros elementos da lista
        // e soma os atributos qt que é a frequencia das letras
        auto raiz = new No(esq,dir,soma);//cria novo nó
        folhas.push_back(raiz);//insere o novo nó na lista
        folhas.sort(ordenar);
        if(folhas.size() <= 1)
        	return raiz;
    }
}

template <typename U>
void codificar(No* no, unsigned long code, queue<U> *codes){
	if(no->ehFolha()){
		cout<<no->getLetra()<<" "<<code<<endl;
		codes->push(U(no->getLetra(), code));
	}
	if(no->temEsq())
		codificar(no->getEsq(), code << 1,codes);
	if(no->temDir())
		codificar(no->getDir(), (code << 1) +1,codes);
}


unordered_map<char, unsigned long> construir_dicionario(No* root){
	aviso(4);
    queue<pair<char, unsigned long>> codes;//cria uma fila de pares
    codificar(root,0,&codes);
    unordered_map<char, unsigned long> dicionario;
    while(!codes.empty()){
    	auto atual = static_cast<pair<char, unsigned long> &&>(codes.front());
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
		if(!bits)
			resultado.push_back(false);
		else{
			vector<bool> subset;
			while(bits){
				auto bit = static_cast<bool>(bits & 1);
				subset.push_back(bit);
				bits>>=1;
			}
			reverse(subset.begin(),subset.end());
			resultado.insert(resultado.end(), subset.begin(), subset.end());
		}
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
	if(atual->ehFolha())
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