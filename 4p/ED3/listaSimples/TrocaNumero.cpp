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
		int count = 0;
		while(aux!=NULL)
		{
			if(aux->num == num1){
				aux->num = num2;
				count++;
			}
			aux = aux->prox;
		}
		if(count == 0){
			cout << "\nNumero não encontrado!\n";
		}else{
			cout << "\nQuantidade de trocas: " << count << endl;
		}
	}
}

int main()
{
    celula *lista = NULL;
    lista = InserirNoInicio(lista,5);
    lista = InserirNoInicio(lista,10);
    lista = InserirNoInicio(lista,20);
    lista = InserirNoInicio(lista,5);
    lista = InserirNoInicio(lista,40);
    cout << "\nLista antes\n";
    ImprimirLista(lista);
    troca(lista,5,10);
    cout << "\nLista depois\n";
    ImprimirLista(lista);
    return 0;       
}
