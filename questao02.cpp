//============================================================================
// Name        : questao02.cpp
// Author      : Guilherme P.
// Version     :
// Copyright   : 30/09/2022
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 20
// verifica a existencia de parenteses sendo que so pode fechar se ja ouver algum aberto
void verifique(char vector[],char pilha[], int &topo, int maxi);
//insere parenteses aberto
void empilhar(char pilha[],char caracter, int &topo, int maxi);
// retira em caso de fecha-parenteses
void desempilhar(char pilha[], int &topo);;

int main(void) {
	char vetor[max];
	int topo = -1;
	char pilha[max];
	cout << "Salve geral" << endl; // prints Salve geral
	cin.getline(vetor, max);// recebe os parenteses no vetor[]

	verifique(vetor, pilha, topo, max);// procedimento de analize da entrada de dados
	for(int i = 0; i<= topo; i++){
		cout << pilha[i] << " "; // imprime o resultado
	}

}

void verifique(char vector[],char pilha[], int &topo, int maxi){
	for(int i = 0; i<maxi; i++){						// laço de incremento sequencial
		if(vector[i] == '(')							// condição de abre-parentese,
			empilhar(pilha, vector[i], topo, maxi );
		else if(vector[i] == ')' && topo > -1) 			//condição de fecha-parentese somente se já estiver algum aberto
			desempilhar(pilha, topo);
		else{continue; }								// caso nada aconteça continue a execução
	}
}
void empilhar(char pilha[], char caracter, int &topo, int maxi){
	if(topo < maxi){					//verifica se a lista está cheia
		topo++;							// incrementa, para depois inserir
		pilha[topo] = caracter;			//insere o elemento
	}else cout << "Lista está cheia" << endl;
}
void desempilhar(char pilha[], int &topo){	//procedimento não sera execultado caso a lista esteja vazia
	pilha[topo] = ' ';
	topo--;
}
