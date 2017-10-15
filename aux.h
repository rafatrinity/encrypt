#ifndef auxiliar
#define auxiliar
#include <bits/stdc++.h>
#include "huffman.h"
#include "msg.h"
#include "sis.h"

using namespace std;

string gerar_string(vector<bool> bits) {
    string resultado;
    for(bool bit : bits)
        resultado += bit ? '0':'1';
    return std::__cxx11::string();
}

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

auto le_bin(){
    string nome_arquivo;
    aviso(1);
    cin>>nome_arquivo;
    ifstream arquivo;
    arquivo.open(nome_arquivo);
    deque<bool> saida;
    string lido;
    if(arquivo.is_open()){
        while(!arquivo.eof())
            arquivo >> lido;
        for(char c: lido){
            if(c != arquivo.eof()) {
                bitset<8> byte;
                byte = bitset<8>(static_cast<unsigned long long int>(c));
                cout << bitset<8>(c);
                for (int i = 7; i >= 0; i--)
                    saida.push_back((bool &&) byte[i]);
            }
        }
        cout<<endl;
    }
    else
        erro(1);
    arquivo.close();
    return saida;
}

void salvar_arquivo(vector<bool> bits){
    ofstream file;
    file.open("huffman.txt", ios::binary);
    auto conta = 0;
    bitset<8> toAppend;
    string resultado;
    for(bool bit : bits){
        ++conta;
        toAppend[0] = bit;
        if(conta == 8){
            char c;
            c = char(toAppend.to_ulong());
            resultado += c;
            conta = 0;
            cout<<bitset<8>(static_cast<unsigned long long int>(c));
            toAppend = 0;
        }
        else
            toAppend <<= 1;
    }
    if(conta > 0){
        toAppend <<= (8-conta)-1;
        char c;
        c = char(toAppend.to_ulong());
        resultado += c;
        cout<<bitset<8>(static_cast<unsigned long long int>(c));
    }
    cout<<endl;
    file<<resultado;
    file.close();
}

void pega_texto(bool b){
    Huffman h;
    h = Huffman();
	string texto;
	if(b)
		texto=le_arquivo();
	else
		getline(cin,texto);
	linha();
	sucesso(texto);
	vector<bool> bits;// = h.comprime(texto);
	aviso(2);
	sucesso(gerar_string(bits));
	aviso(3);
	salvar_arquivo(bits);
	aviso(4);
	//for(auto v : h.obter_dicionario())
	//	cout<<"("<<v.first<<","<<bitset<4>(v.second)<<")\n";
	cout<<"\033[0m\n";
	aviso(5);
	//cout<<h.exedente()<<endl;
	getchar();
    //h.getTree();
}

#endif