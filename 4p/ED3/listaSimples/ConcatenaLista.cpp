#include <iostream>

using namespace std;

struct celula
{
    int valor;
    celula *prox;
};

celula *insereNoFim(celula *lista, int num)
{
    celula *nova = new celula;
    nova->valor = num;

    if(lista==NULL)
    {
        nova->prox = lista;
        return nova;
    }
    else
    {
        celula *aux = lista;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        nova->prox = NULL;
        aux->prox = nova;
        return lista;
    }
}

void print(celula *lista)
{
    if(lista==NULL)
    {
        cout << "\nLista Vazia!\n";
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

celula *concatena(celula *l1, celula *l2)
{
    celula *l3 = NULL;
    celula *aux = l1;
    while(aux!=NULL)
    {
        l3 = insereNoFim(l3,aux->valor);
        aux = aux->prox;
    }
    aux = l2;
    while(aux!=NULL)
    {
        l3 = insereNoFim(l3,aux->valor);
        aux = aux->prox;
    }
    return l3;
}


int main()
{
    celula *l1 = NULL;
    celula *l2 = NULL;

    l1 = insereNoFim(l1,5);
    l1 = insereNoFim(l1,25);
    l1 = insereNoFim(l1,35);
    l1 = insereNoFim(l1,45);
    cout << "\nLista 1: ";
    print(l1);

    l2 = insereNoFim(l2,10);
    l2 = insereNoFim(l2,20);
    l2 = insereNoFim(l2,30);
    cout << "\nLista 2: ";
    print(l2);

    celula *l3 = concatena(l1,l2);
    cout << "\nLista 3: ";
    print(l3);

    return 0;
}
