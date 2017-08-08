#include <iostream>

using namespace std;

struct celula
{
	int idade;
	string nome;
	celula *proxima;
};

bool Vazia(celula *l){
	if(l==NULL)
		return true;
	else
		return false;
}

void Imprime(celula *lista){
	if(Vazia(lista)){
		cout << "Lista Vazia!" << endl;
	}else{
		celula *aux = lista;
		
		while(aux!=NULL){
			cout << aux->nome << " - " << aux->idade << " anos" << endl;
			aux = aux->proxima;
		}
		
	}
}

celula *InserirInicio(celula *lista, int idade, string nome){
	celula *nova = new celula; //aloca memoria
	nova->idade = idade;
	nova->nome = nome;
	nova->proxima = lista;	
	return nova;
}

int main(int argc, char** argv)
{
	celula *lista = NULL;
	
	/*
	//insere fim
	celula *nova = new celula;
	nova->idade = 20;
	nova->nome = "Maria";
	nova->proxima = NULL;
	lista = nova;
	
	//insere inicio
	nova = new celula;
	nova->idade = 28;
	nova->nome = "João";
	nova->proxima = lista;
	lista = nova;
	*/
	
	lista = InserirInicio(lista,40,"Maria");
	lista = InserirInicio(lista,50,"Joao");
	
	Imprime(lista);
	
	return 0;
}
