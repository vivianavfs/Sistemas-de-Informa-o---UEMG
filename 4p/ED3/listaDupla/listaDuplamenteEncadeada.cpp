#include <iostream>

using namespace std;

struct celula
{
	int elem;
	celula *ant;
	celula *prox;
};

struct lista
{
	celula *inicio;
	celula *fim;
};

void imprimir(lista l)
{
	if (l.inicio)
	{
		celula *aux = l.inicio;
		while (aux)
		{
			cout << aux->elem << " ";
			aux = aux->prox;
		}
	}
	else cout << "Lista vazia";
	cout << endl;
}

lista inserirInicio(int valor, lista l)
{
	celula *nova = new celula;
	nova->elem = valor;
	if(l.inicio){
		nova->ant = NULL;
		nova->prox = l.inicio;
		l.inicio->ant = nova;
		l.inicio = nova;
	}
	else
	{
		nova->ant = NULL;
		nova->prox = NULL;
		l.inicio = nova;
		l.fim = nova;
	}
	return l;
}

int main()
{
	//ciando a lista dupla
	lista lista1;
	lista1.inicio = NULL;
	lista1.fim = NULL;

	//inserindo nova celula
	celula *nova = new celula;
	nova->ant = NULL;
	nova->prox = NULL;
	nova->elem = 8;

	//atualizar lista - inicio e fim
	lista1.inicio = nova;
	lista1.fim = nova;
	
	//inserir no fim]
	nova = new celula;
	nova->elem = 10; //coloca valor
	nova->prox = NULL; //null na proxima
	lista1.fim->prox = nova; //atualiza campo proxima da ultima celula da lista
	nova->ant = lista1.fim; //o anterior da nova aponta para a ultima da celula da lista
	lista1.fim = nova; //atualiza o fim para a nova celula

	lista1 = inserirInicio(2,lista1);
	lista1 = inserirInicio(1,lista1);
	imprimir(lista1);
	return 0;
}
