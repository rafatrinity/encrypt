
typedef struct s{
	char l;
	int qt;
}letra;

void nome(string n, letra *vl[]){
	sort(n.begin(),n.end());
	int t=1;
	for (int i = 0; i < n.size(); i++)
	{
		if(n[i]==n[i+1])
			t++;
		else{
			vl[i]->l=n[i];
			vl[i]->qt=t;
			t=1;
		}
	}
}

void enviar(){
	string nm;
	getline(cin,nm);
	int a=nm.size();
	vector<letra> vl(a);
	nome(nm, vl);
	for (int i = 0; i < vl.size(); i++)
		inserir(raiz,vl[i]);
}