#include <bits/stdc++.h>
#include "sis.h"
#include "msg.h"

using namespace std;
bool b;
string erro(int n){
	cab();
	switch(n){
		case 1:
			return "\n\t\t\033[1;31mO ARQUIVO NÃO PODE SER ABERTO.\n\tCERTIFIQUE-SE SE O NOME FOI DIGITADO CORRETAMENTE,"
				"\n\t   PARA MAIS INFORMAÇÕES SELECIONE A OPÇÃO AJUDA\n\033[0m";
        default:break;
    }
}

void aviso(int n){
	cout<<"\033[1;36m";
	switch(n){
		case 0:
		cout<<"\n\tDIGITE UM TEXTO QUALQUER.\n";
		break;
		case 1:
		cout<<"\n\tINFORME O NOME DO ARQUIVO.\n";
		break;
		case 2:
		cout<<"\n\tARQUIVO COMPRIMIDO COM SUCESSO!\n";
		break;
		case 3:
		cout<<"\n\tSALVANDO ARQUIVO...\n";
		break;
		case 4:
		cout<<"\n\tDICIONARIO GERADO.\n";
		cout<<"\033[1;32m";
		break;
		case 5:
		cout<<"\n\tTOTAL DE BITS EXEDENTES: ";
		break;
        default:break;
    }
	cout<<"\033[0m";
}

void sucesso(string a){
	cout<<"\033[1;32m";
	cout<<a<<endl;
	cout<<"\033[0m";
}
