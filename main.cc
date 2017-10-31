#include <bits/stdc++.h>
#include "menus.h"
//versão do compilador C++14 ou superior
using namespace std;
int main(int argc, char const *argv[])
{
	int m;
	apresenta();
	do{
		m=menu_principal();
		switch(m){
			case 0:
			fim();
			return 0;
			case 1:
			menu_compactar();
			break;
			case 2:
			descomprime(le_bin());
			break;
			case 3:
			break;
			default:
			break;
		}	
	}while(true);
}
//olaaaaa mundooo