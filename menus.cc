#include "aux.h"

using namespace std;

int menu_principal(){
	cab();
	int m;
	cout<<"\t[1] COMPACTAR\n";
	cout<<"\t[2] DESCOMPACTAR\n";
	cout<<"\t[3] AJUDA\n";
	cout<<"\t[0] SAIR\n";
	cin>>m;
	return m;
}


void menu_compactar(){
	int m=0;
	do{
		cab();
		cout<<"\t[1] DIGITAR UM TEXTO\n";
		cout<<"\t[2] LER UM ARQUIVO DE TEXTO\n";
		cout<<"\t[3] AJUDA\n";
		cout<<"\t[0] VOLTAR\n";
		cin>>m;
		switch(m){
			case 0:
			break;
			case 1:
			aviso(0);
			pega_texto(false);
			break;
			case 2:
			aviso(1);
			pega_texto(true);
			break;
			case 3:
			break;
			default:
			break;
		}
		getchar();
	}while(m);
}

