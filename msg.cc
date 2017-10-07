#include "sis.h"
#include "msg.h"
#include "menus.h"
using namespace std;
bool b;
void erro(int n){
	cab();
	cout<<"\033[1;31m";
	linha();
	switch(n){
		case 1:
		cout<<"\t\t\nERRO! \n\tO ARQUIVO NÃO PODE SER ABERTO.\n";
		cout<<"CERTIFIQUE-SE SE O NOME FOI DIGITADO CORRETAMENTE, PARA MAIS INFORMAÇÕES SELECIONE A OPÇÃO AJUDA\n";
		break;
	}
	cin>>b;
	cout<<"\033[0m";
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
		sucesso(h.exedente());
		break;
	}
	cin>>b;
	cout<<"\033[0m";
}

void sucesso(string a){
	cout<<"\033[1;32m";
	cout<<a<<endl;
	cout<<"\033[0m";
}
