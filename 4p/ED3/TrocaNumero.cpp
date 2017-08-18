#include <iostream>

using namespace std;

struct celula
{
	int num;
	celula *prox;
};

void ImprimirLista(celula *lista) {
    celula *aux = lista;
    if (!lista)
        cout << "Lista vazia";
    else {
        while (aux != NULL) {
            cout << aux->num << endl;
            aux = aux->prox;
        }
    }
}

celula *InserirNoInicio(celula *lista, int num) {
    celula *nova = new celula;
    nova->num = num;
    nova->prox = lista;
    return nova;
}


void troca(celula *lista, int num1, int num2){
	if(lista==NULL){
		cout << "Lista Vazia!" << endl;
	}else{
		celula *aux = lista;
		while(aux!=NULL && aux->num != num1)
		{
			aux = aux->prox;
		}
		if(aux == NULL){
			cout << "\nNumero não encontrado!\n";
		}else{
			aux->num = num2;
		}
	}
}

int main()
{
    celula *lista = NULL;
    lista = InserirNoInicio(lista,10);
    lista = InserirNoInicio(lista,20);
    lista = InserirNoInicio(lista,30);
    lista = InserirNoInicio(lista,40);
    lista = InserirNoInicio(lista,50);
    cout << "\nLista antes\n";
    ImprimirLista(lista);
    troca(lista,50,5);
    cout << "\nLista depois\n";
    ImprimirLista(lista);
    return 0;       
}
