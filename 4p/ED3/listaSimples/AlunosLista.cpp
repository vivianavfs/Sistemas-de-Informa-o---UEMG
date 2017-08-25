#include <iostream>

using namespace std;

struct celula
{
	int matricula;
	string nome;
	float media;
	celula *prox;
};

void ImprimirLista(celula *lista) {
    celula *aux = lista;
    if (!lista)
        cout << "Lista vazia";
    else {
        while (aux != NULL) {
            cout << aux->matricula << endl;
            aux = aux->prox;
        }
    }
}

celula *inserirOrdenado(celula *lista, int matricula, string nome, float nota)
{
	
	celula *nova = new celula;
	nova->matricula = matricula;
	nova->nome = nome;
	nova->media = nota;
	if(lista==NULL){ //se lista estiver vazia
		nova->prox = NULL;
		lista = nova;
	}else{
		celula *aux = lista;
		celula *ant = NULL;
		while(aux!=NULL && nova->matricula > aux->matricula)
		{
			ant = aux;
			aux = aux->prox;
		}
		if(ant == NULL){ //inserindo no inicio (é o menor numero da lista)
			nova->prox = lista;
			lista = nova;
		}else //insere no meio ou no final
		{
			ant->prox = nova;
			nova->prox = aux;
		}
	}
	return lista;
}

int main()
{
	celula *lista = NULL;
	lista = inserirOrdenado(lista,10,"Teste 01",8);
	lista = inserirOrdenado(lista,5,"Teste 02",8);
	lista = inserirOrdenado(lista,30,"Teste 03",8);
	lista = inserirOrdenado(lista,40,"Teste 04",8);
	lista = inserirOrdenado(lista,1,"Teste 05",8);
	ImprimirLista(lista);
    return 0;       
}
