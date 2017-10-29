#include <iostream>

using namespace std;

struct celula
{
	string nome;
	int prioridade;
	celula *prox;
};

struct fila
{
	celula *inicio;
	celula *fim;
};

void imprimir(fila f)
{
	if (f.inicio)
	{
		celula *aux = f.inicio;
		while (aux)
		{
			cout << aux->nome << " - " << aux->prioridade << endl;
			aux = aux->prox;
		}
	}
	else
	{
		cout << "Fila vazia";
	}
	cout << endl;
}

void inserir(fila &f, string n, int p)
{
	celula *nova = new celula;
	nova->nome = n;
	nova->prioridade = p;
	if(f.inicio == NULL)
	{
		nova->prox = NULL;
		f.inicio = nova;
		f.fim = nova;
	}
	else
	{
		celula *aux = f.inicio;
		celula *ant = NULL;
		while(aux != NULL && aux->prioridade >= nova->prioridade)
		{
			ant = aux;
			aux = aux->prox;
		}
		if(aux == f.inicio)
		{
			nova->prox = f.inicio;
			f.inicio = nova;
		}
		else if (aux == NULL)
		{
			f.fim->prox = nova;
			nova->prox = NULL;
			f.fim = nova;
		}
		else
		{
			nova->prox = aux;
			ant->prox = nova;
		}
	}
}

int main()
{
	fila fila1;
	fila1.inicio = NULL;
	fila1.fim = NULL;
	
	inserir(fila1,"Maria", 2);
	inserir(fila1,"Jose", 1);
	inserir(fila1,"Pedro", 5);
	inserir(fila1,"Joao", 3);
	inserir(fila1,"Ana", 2);
	inserir(fila1,"Carlos", 5);
	
	imprimir(fila1);
	return 0;
}
