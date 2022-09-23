//============================================================================
// Name        : Questão02.cpp
// Author      : Guilherme P.
// Version     :
// Copyright   : 23/09/2022
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
// Recebe o vetor, O elemnto a ser inserido, a quantidade atual de elementos deve ser passado por referência,  tamanho maximo do vetor.
void inserirSemRepetir(int v[], int element, int &qtd, int max);
// A função percorre e imprime todos elementos do vetor, recebe o vetor, e o tamanho
void listar(int v[], int indice);
// Verifica a existencia de Ambiguidade no vetor
int paridade(int G[], int termo, int qtd);
// Une as duas listas em uma só
void potara(int R[], int v1[], int v2[], int tam1, int tam2);
//retorna o maior entre dois numeros
int maior(int a, int b);
//main
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int maximo=10;
	int qtd1=0;
	int qtd2=0;
	int lista1[10];
	int lista2[10];
	int listaR[20];
	//10, 34 e 5   4, 7 e 9
	inserirSemRepetir(lista1,10, qtd1, maximo);

	inserirSemRepetir(lista1,34, qtd1, maximo);
	inserirSemRepetir(lista1,5, qtd1, maximo);
	inserirSemRepetir(lista2, 4, qtd2, maximo);
	inserirSemRepetir(lista2,7, qtd2, maximo);
	inserirSemRepetir(lista2,9, qtd2, maximo);

	potara(listaR, lista1, lista2, qtd1, qtd2);


	listar(lista1, qtd1);
	listar(lista2, qtd2);
	listar(listaR, (qtd1 + qtd2));
	return 0;
}

void inserirSemRepetir(int v[], int element, int &qtd, int max){
	if(qtd >= max){
		cout << "A Lista está cheia" << endl;
	}else if(paridade(v, element, qtd)){
			cout << "Elemento já está contido na lista" << endl;
	}else {
		v[qtd]= element;
		qtd++;
	}


}

int paridade(int G[], int termo, int qtd){
	for(int i=0; i <= qtd; i++){
		if(G[i] == termo){
		return 1;
	}
  }
	return 0;
}
void listar(int v[], int tam){
	for(int i=0; i < tam; i++){
		cout << v[i] << " ";
	}
    cout << endl;
}
void potara(int R[], int v1[], int v2[], int tam1, int tam2){
	int stop = maior(tam1, tam2);
	int p=0;
	for(int i=0; i < stop; i++){
		R[p] = v1[i];
		R[p+1] = v2[i];
		p+=2;
	}

}
int maior(int a, int b){
	if(a<b){
		return b;
	}
	return a;
}
