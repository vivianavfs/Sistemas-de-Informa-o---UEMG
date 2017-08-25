#include <iostream>

using namespace std;

struct celula
{
	int valor;
	celula *prox;
};

celula *insereNoInicio(celula *lista, int num){
	celula *nova = new celula;
	nova->valor = num;
	nova->prox = lista;
	return nova;
}

void print(celula *lista){
	
	if(lista==NULL){
		cout << "\nLista Vazia!!!\n";
	}else{
		celula *aux = lista;
		while(aux!=NULL){
			cout << aux->valor << " ";
			aux = aux->prox;
		}
	}

}

/*
int maior(celula *lista){
	if(lista==NULL){
		cout << "\nLista Vazia!!!\n";
		return 0;
	}else{
		celula *aux = lista;
		int maior = lista->valor;
		while(aux!=NULL){
			cout << "\n -- D - comp: " << maior << " eh menor que " << aux->valor;
			if(maior < aux->valor)
			{
				maior = aux->valor;
				cout << "\n -- D - maior atual: " << maior;
			}
			aux = aux->prox;
		}
		return maior;
	}
	
}
*/

//correção
int maiorElemento(celula *lista){
	int maior = lista->valor;
	celula * aux = lista->prox;
	while(aux != NULL){
		if(aux->valor > maior)
			maior = aux->valor;
		aux = aux->prox;
	}
	return maior;
}

//maior que o parametro
void maiorQue(celula *lista, int num){
	celula * aux = lista->prox;
	while(aux != NULL){
		if(aux->valor > num){
			cout << aux->valor << " ";
		}
		aux = aux->prox;
	}
}



int main()
{
	//inserir no inicio da lista e achar maior valor
	celula *lista = NULL;
	lista = insereNoInicio(lista,20);
	lista = insereNoInicio(lista,5);
	lista = insereNoInicio(lista,45);
	lista = insereNoInicio(lista,1);
	lista = insereNoInicio(lista,10);
	lista = insereNoInicio(lista,1);
	print(lista);
	//cout << "\nMaior: " << maior(lista);
	cout << "\nMaior: " << maiorElemento(lista);
	cout << "\nMaior que 10\n";
	maiorQue(lista,10);
	
    return 0;       
}
