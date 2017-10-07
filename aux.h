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
	string texto;
	if(b)
		texto=le_arquivo();
	else
		getline(cin,texto);
	sucesso(texto);
}
#endif