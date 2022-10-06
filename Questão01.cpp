//============================================================================
// Name        : Trabalho_Pratico_02
// Author      : Guilherme P.
// Version     :
// Copyright   : 30/09/2022
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 10

int desempilha(int binario[], int &topo);
void pilha(int binario[], int valor , int &topo);

int main(void) {
	int dado;
	int bit[max];
	int topo=-1; // topo da pilha
	int quociente, resto;

	cout << "!!!Hello World!!!" << endl << "Digite o valor natural em decimal para ser convertido em Binário" << endl; // prints !!!Hello World!!!
	cin >> dado;

	do{
		quociente = dado / 2;
		resto = dado % 2;
		pilha(bit, resto, topo); // insere o elemento na pilha
		dado = quociente;
		}while(dado > 0 );
		//immprimir o resultado
		for(int i = topo; i >= 0; i--){
			dado = desempilha(bit, topo);
			cout << dado << " ";
		}
		cout << endl;
}

int desempilha(int binario[], int &topo){
	int remove = binario[topo];
	topo--;
	return remove;
}
void pilha(int binario[], int valor, int &topo){
	if(topo < max){
	topo++;
	binario[topo] = valor;
	}else cout << "lista está cheia, ocorreu overflow" << endl;
}
