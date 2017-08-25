#include <iostream>

using namespace std;

struct celula
{
    int valor;
    celula *prox;
};

celula *insereOrdenado(celula *lista, int valor)
{
    celula *nova = new celula;
    nova->valor = valor;
    if(lista == NULL)
    {
        nova->prox = NULL;
        return nova;
    }
    else
    {
        celula *aux = lista;
        celula *ant = NULL;
        while(aux!=NULL && nova->valor > aux->valor)
        {
            ant = aux;
            aux = aux->prox;
        }
        if(ant == NULL)
        {
            nova->prox = lista;
            return nova;
        }
        else
        {
            ant->prox = nova;
            nova->prox = aux;
            return lista;
        }

    }
}

void print(celula *lista)
{
    if(lista == NULL)
    {
        cout << "\nLista Vazia!!!\n";
    }
    else
    {
        celula *aux = lista;
        while(aux!=NULL)
        {
            cout << aux->valor << " ";
            aux = aux->prox;
        }
    }
}

celula *removeRepetido(celula *lista)
{
    if(lista == NULL)
    {
        cout << "\nLista Vazia\n";
        return lista;
    }
    else
    {
        celula *aux = lista;
        celula *atual = aux;

        while(aux!=NULL)
        {

            if(aux->valor == atual->valor && aux != lista)
            {
                cout << "\nDeletando -> " << aux->valor << endl;
                atual->prox = aux->prox;
                delete aux;

            }
            else
            {
                atual = aux;
            }
            aux = aux->prox;
        }
        return lista;
    }
}

int main()
{
    celula *lista = NULL;
    lista = insereOrdenado(lista,5);
    lista = insereOrdenado(lista,15);
    lista = insereOrdenado(lista,1);
    lista = insereOrdenado(lista,2);
    lista = insereOrdenado(lista,5);
    lista = insereOrdenado(lista,5);
    lista = insereOrdenado(lista,1);
    lista = insereOrdenado(lista,1);
    lista = insereOrdenado(lista,1);
    lista = insereOrdenado(lista,15);


    lista = removeRepetido(lista);

    print(lista);

    return 0;
}
