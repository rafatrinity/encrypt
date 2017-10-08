#ifndef auxiliar
#define auxiliar
#include <bits/stdc++.h>
#include "msg.h"
using namespace std;
string le_arquivo(){
	string nome_arquivo;
	cin>>nome_arquivo;
	ifstream arquivo;
	arquivo.open(nome_arquivo);
	stringstream saida;
	if(arquivo.is_open()){
		while(!arquivo.eof()){
			string buffer;
			arquivo >> buffer;
			saida << buffer;
		}
	}
	else
		erro(1);
	arquivo.close();
	return saida.str();
} 
void pega_texto(bool b){
	huff h = huff();
	string texto;
	if(b)
		texto=le_arquivo();
	else
		getline(cin,texto);
	linha();
	sucesso(texto);
	vector<bool> bits = h.comprime(texto);
	aviso(2);
	sucesso(gerar_string(bits));
	aviso(3);
	salvar_arquivo(bits);
	aviso(4);
	for(auto v : h.obter_dicionario())
		cout<<"("<<v.first<<","<<bitset<4>(v.second)<<")\n";
	cout<<"\033[0m\n";
	aviso(5);
	sucesso(h.exedente());
	getchar(); 
}

#endif