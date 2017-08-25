#include <iostream>

using namespace std;

struct celula
{
	int valor;
	celula *prox;
};

celula *insereFim(celula *lista, int num){
	celula *nova = new celula;
	nova->valor = num;
	if(lista==NULL){
		nova->prox = lista;
		return nova;
	}else{
		celula *aux = lista;
		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = nova;
		nova->prox = NULL;
		return lista;
	}
}

void imprime(celula *lista){
	if(lista==NULL){
		cout << "\nLista Vazia!!!\n";
	}else{
		celula *aux = lista;
		while(aux!=NULL)
		{
			cout << aux->valor << " ";
			aux = aux->prox;
		}
	}
}

celula *separa(celula *lista, int n){
	if(lista==NULL){
		cout << "\nLista Vazia!!!\n";
		return lista;
	}else{
		celula *aux = lista;
		while(aux!=NULL && aux->valor != n)
		{
			aux = aux->prox;
		}
		if(aux == NULL){
			return NULL;
		}
		else{
			celula *l2 = aux->prox;
			aux->prox = NULL;
			return l2;
		}
	}
}

int main()
{
    celula *l1 = NULL;
    
    
    l1 = insereFim(l1,3);
    l1 = insereFim(l1,17);
    l1 = insereFim(l1,5);
    l1 = insereFim(l1,12);
    l1 = insereFim(l1,1);
    
    imprime(l1);
    
    celula *l2 = separa(l1,5);
    
    cout << "\nLista 1\n";
    imprime(l1);
    
    cout << "\nLista 2\n";
    imprime(l2);
    
    return 0;       
}
