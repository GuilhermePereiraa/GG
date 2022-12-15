
no* remover(no *raiz, TipoDaChave chave) { // ponteiro para o inicio da arvore, valor a ser removido, 
                                         // primeiro devemos achar o nó que contem a chave
    if(raiz == NULL){ // verifica se a arvore está vazia
        cout << "Árvore está vazia, valor não encontrado" << endl;
        return NULL; // retorna Nulo
    } else { 
        if(raiz->valor == chave) {
            if(raiz->esquerda == NULL && raiz->direita == NULL) { // verifica se é nó folha (sem subarvores)
                delete raiz;
                cout << "Elemento" <<  chave <<  removido" 
                return NULL;
            }
            else{
                if(raiz->esquerda != NULL && raiz->direita != NULL){ // verifica se é nó com 2 subárvores
                    no *aux = raiz->esquerda; // vai para esquedar do nó a ser removido
                    while(aux->direita != NULL) // depois percore até o nó mais a direita, ou seja
                        aux = aux->direita;     // o maior á esquerda da raiz
                    raiz->valor = aux->valor; // substituo a chave a ser removida pelo maior valor á esquerda 
                    aux = NULL; // o nó anterior agora aponta pra Nulo
                    return raiz; // retorna  a referencia com valor subtituido
                }
                else{ // se chegar aqui significa que o nó possui apenas uma subárvore
                    no *aux;
                    if(raiz->esquerda != NULL) // dando prioridade para esquerda verifico se possui elemento
                        aux = raiz->esquerda;
                    else  // caso contrario o elemento está a direita
                        aux = raiz->direita;
                    delete raiz; // remove a chave
                    return aux; // retorna o proximo nó da lista 
                }
            }
        } else { // elemento não encontrado 
            if(chave < raiz->valor) // verifica se  a chave está a esquerda
                raiz->esquerda = remover(raiz->esquerda, chave); // recurssão
            else // caso contrario está a direita 
                raiz->direita = remover(raiz->direita, chave); // recurssão
            return raiz; // retorna a raiz para a função principal
        }
    }
}
