#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

struct celula
{
	int elemento;
	celula *proxima;
};


void ImprimirListaEPosicao(celula *lista)
{
	celula *aux = lista;
	if (!lista)
		cout << "Lista vazia";
	else
	{
		while (aux != NULL)
		{
			cout << aux->elemento << " - " << aux << endl;
			aux = aux->proxima;
		}
	}
}

celula *InserirNoFim(celula *lista, int valor)
{
	celula *nova = new celula;
	nova->elemento = valor;
	if (!lista)  //lista == NULL
	{
		nova->proxima = lista;
		return nova;
	}
	else
	{
		celula *aux = lista; //procura pelo fim da lista
		while (aux->proxima != NULL)
		{
			aux = aux->proxima;
		}
		aux->proxima = nova;
		nova->proxima = NULL;
		return lista;
	}
}

celula *menorNoInicio(celula *lista)
{
    if(lista)
    {
        celula *aux = lista;
        celula *menor = aux;
        celula *ant = NULL;

        while(aux->proxima)
        {
            ant = aux;
            if(aux->elemento<menor->elemento)
                menor = aux;
            aux = aux->proxima;
        }
        if(aux->elemento<menor->elemento)
                menor = aux;
        if(ant == NULL){ //somente um elemento
            return lista;
        }else{
            //cout << "\n ant: " << ant->elemento << " - " << ant << endl;
            //cout << "\n menor: " << menor->elemento << " - " << menor << endl;
            ant->proxima = menor->proxima;
            menor->proxima = lista;
            return menor;
        }
    }
    return NULL;
}



int main()
{
	celula *l1 = NULL;
	l1 = InserirNoFim(l1, 20);
	l1 = InserirNoFim(l1, 25);
	l1 = InserirNoFim(l1, 50);
	l1 = InserirNoFim(l1, 2);

	cout << "\nantes: \n";
	ImprimirListaEPosicao(l1);

	l1 = menorNoInicio(l1);

	cout << "\ndepois: \n";
	ImprimirListaEPosicao(l1);


	return 0;
}
