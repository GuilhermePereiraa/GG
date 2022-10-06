//============================================================================
// Name        : questao03.cpp
// Author      : Guilherme P.
// Version     :
// Copyright   : 30/09/2022
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define max 20

// Retorna a quantidade de letras inseridas no meu vetor.
int contador(char word[]);
//metodo comparador
int compareTo(char pilhaone[], char pilhatwo[], int topoWord);
//inserir na pilha ( empilhar )
void empilhar(char word[], char v1[], char v2[], int &topo, int maximo);

int main(void) {
	char word[max]={}; // vetor inicializado com nulo/vazio em todas as  20  posiçoes
	int topoWord;		// armazena a topo do vetor Word[]
	char onepilha[max/2]={}; // vetor inicializado com nulo/vazio em todas as alocaçoes
	char twopilha[max/2]={}; // vetor inicializado com nulo/vazio em todas as alocaçoes
	int topo = -1;   // topo seriva para ambas pilhas pois a palavra palindroma possui "equivalencia binaria"

	cout << " -----Salve Geral------ " << endl; // prints Salve geral
	cin.getline(word, max);	//recebe a palavra no vetor word com tamanho maximo definido
	//chamando a função contador
	topoWord = contador(word);
	// chamando a função que empilha o elemento no vetor
	empilhar(word, onepilha, twopilha, topo, topoWord);
		// vamos comparar e verificar se é palindroma
		if(compareTo(onepilha, twopilha, topo))
			cout << word << " È Palindroma" << endl;
		else
			cout << word << ": Não é Palindroma" << endl;
}

int contador(char word[]){
	int i = 0;
	char null = {};  //comparador para contagem
		do{
			i++;
		}while(word[i] != null); cout << " Possui " << i << " Palavras" << endl;

		return i;
}

int compareTo(char pilhaone[], char pilhatwo[], int topo){
	for(int i = 0; i < topo; i++ ){
		if(pilhaone[i] != pilhatwo[i])
			return 0;
	}
	return 1;
}

void empilhar(char word[], char v1[],char v2[], int &topo, int maximo){

	int i = 0;
	int j = maximo-1;
	do{
	topo++;
	v1[topo] = word[i];
	v2[topo] = word[j];
	i++;
	j--;
}while(i <= maximo/2);



}
