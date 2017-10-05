#include <bits/stdc++.h>
#include "arvore.h"
//#include "encrip.h"
using namespace std;
int main(int argc, char const *argv[])
{
	ArvBin* raiz;
	raiz = cira_arvore();
	//enviar();
	cout<<endl;
	cout<<"qt no "<<qt_no(raiz)<<endl;
	cout<<"altura arvore "<<altura_arvore(raiz)<<endl;
	return 0;
}
