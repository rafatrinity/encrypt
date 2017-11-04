#ifndef auxiliar
#define auxiliar
#include <bits/stdc++.h>
#include "huffman.h"
#include "huffman.cc"
#include "msg.h"
#include "sis.h"
#include "menus.h"

using namespace std;
bool e;
void pega_texto(bool b);

string gerar_string(deque<bool> bits) {
    string resultado;
    for(bool bit : bits)
        resultado += bit ? '0':'1';
    return resultado;
}

string le_arquivo(){
	string nome_arquivo, linha, saida;
	cin>>nome_arquivo;
	ifstream arquivo;
	arquivo.open(nome_arquivo);
	if(arquivo.is_open()){
		while(!arquivo.eof()){
			getline (arquivo,linha);
            saida+=linha;
            saida+="\n";
        }
    } 
    else
     e=true;
 arquivo.close();
 return saida;
}

auto le_bin(){
    string nome_arquivo;
    aviso(1);
    cin>>nome_arquivo;
    ifstream arquivo;
    arquivo.open(nome_arquivo);
    deque<bool> saida;
    string lido,linha;
    if(arquivo.is_open()){
        while(!arquivo.eof()){
            getline (arquivo,linha);
            lido+=linha;
        }
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
       cout<<erro(1)<<endl;
   arquivo.close();
   return saida;
}

void salvar_arquivo(deque<bool> bits, string arqv){
    ofstream file;
    file.open(arqv, ios::binary);
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


void pega_texto(bool b) {
    e = false;
    string texto;
    getchar();
    if(b)
        texto=le_arquivo();
    else
        getline(cin,texto);
    if(!e) {
        linha();
        sucesso(texto);
        deque<bool> bits = comprime(texto);
        aviso(2);
        sleep(1);
        sucesso(gerar_string(bits));
        aviso(1);
        cin>>texto;
        salvar_arquivo(bits,texto);
        aviso(3);
        sleep(1);
    }
    else{
        cout<<erro(1)<<endl;
        sleep(1);
        getchar();
    }
}

#endif