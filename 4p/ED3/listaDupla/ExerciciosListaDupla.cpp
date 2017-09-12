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

lista inserirInicio(int v, lista l)
{
	celula *nova = new celula;
	nova->elem = v;
	if (!l.inicio)
	{
		nova->prox = NULL;
		nova->ant = NULL;
		l.inicio = nova;
		l.fim = nova;
	}
	else
	{
		nova->ant = NULL;
		nova->prox = l.inicio;
		l.inicio->ant = nova;
		l.inicio = nova;
	}
	return l;
}

void imprimirInvertido(lista l)
{
	if (l.fim)
	{
		celula *aux = l.fim;
		while (aux)
		{
			cout << aux->elem << " ";
			aux = aux->ant;
		}
	}
	else cout << "Lista vazia";
	cout << endl;
}

celula *encontra(int v, lista l)
{
	if (l.inicio)
	{
		celula *aux = l.inicio;
		while (aux && aux->elem != v)
		{
			aux = aux->prox;
		}
		if(aux==NULL)
			return NULL;
		else
		{
			return aux;
		}
	}
	else return NULL;
}

int main()
{
	lista l;
	l.inicio = NULL;
	l.fim = NULL;

	l = inserirInicio(10, l);
	l = inserirInicio(2, l);
	l = inserirInicio(3, l);
	l = inserirInicio(7, l);

	//exercicio 01
	imprimirInvertido(l);
	
	//exercicio 02
	celula *valor = encontra(8,l);
	if(valor)
		cout << valor->elem << " - " << valor << endl;
	else
		cout << "NULL" << endl;
	
	//exercicio 03
	

	return 0;
}
