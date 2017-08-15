#include <iostream>

using namespace std;

struct celula
{
	float info;
	celula *prox;
};

celula *insereFim(celula *lista, int num){
	celula *nova = new celula;
	nova->info = num;
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
			cout << aux->info << " ";
			aux = aux->prox;
		}
	}
}

celula *constroi(int n, int *vetor){
	celula *aux = NULL;
	for(int i = 0; i < n; i++)
	{
		aux = insereFim(aux, vetor[i]);
	}
	return aux;
}

int main()
{
    cout << "Hello world!\n";
    int v[5] = {3,8,1,7,2};
    celula *lista = constroi(5,v);
    imprime(lista);
    return 0;       
}
