#include <bits/stdc++.h>
#include "menus.h"

using namespace std;
int main(int argc, char const *argv[])
{
	int m;
	apresenta();
	do{
		int m=menu_principal();
		switch(m){
			case 0:
			fim();
			return 0;
			break;
			case 1:
			menu_compactar();
			break;
			case 2:
			break;
			case 3:
			break;
			default:
			break;
		}	
	}while(m);
}
