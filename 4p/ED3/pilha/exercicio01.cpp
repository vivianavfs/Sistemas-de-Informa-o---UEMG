#include <iostream>
#include <locale>
#include <string>
#include <cstdlib> 

using namespace std;

struct celula
{
	int elem;
	celula *prox;
};

struct pilha
{
	celula *topo;
};

void print(pilha p)
{
	if(p.topo){
		cout << "\nNúmero cadastrados\n";
		celula *aux = p.topo;
		while(aux){
			cout << aux->elem << endl;
			aux = aux->prox;
		}
		cout << "\n--------------------\n";
	}
}
bool is_number(string str)
{
	bool num = false;
	for(int i = 0;i < str.length();i++) {
		if(isdigit(str[i])) {
			num = true;
		} else {
			num = false;
		}
	}
	return num;
}

void push(pilha &p, int n)
{
	celula *nova = new celula;
	nova->elem = n;
	nova->prox = p.topo;
	p.topo = nova;
}

void cadastra(pilha &p)
{
	string num;
	cout << "\nDigite um número para cadastro ou uma letra para sair: ";
	cin >> num;
	while(is_number(num))
	{
		push(p, atoi(num.c_str()));
		cin >> num;
	}
}

void pares(pilha p)
{
	if(p.topo==NULL){
		cout << "\nPilha Vazia!\n";
	}else{
		cout << "\nNúmeros pares\n";
		celula *aux = p.topo;
		while(aux){
			if(aux->elem%2==0)
				cout << aux->elem << endl;
			aux = aux->prox;
		}
		cout << "\n--------------------\n";
	}
}

void pop(pilha &p)
{
	if(p.topo){
		celula *aux = p.topo;
		p.topo = p.topo->prox;
		delete aux;
	}else{
		cout << "\nPilha Vazia!\n";
	}
}
int main()
{
	setlocale(LC_ALL,"");
	
	pilha p;
	p.topo = NULL;
	
	int op;
    do
	{
		cout << "\n1 - Cadastra número\n";
		cout << "\n2 - Mostrar números pares\n";
		cout << "\n3 - Excluir número\n";
		cout << "\n4 - Sair\n";
		cin >> op;
		
		switch(op)
		{
		case 1:
			cadastra(p);
			print(p);
			break;
		case 2:		
			pares(p);
			break;
		case 3:
			pop(p);
			print(p);
			break;
		case 4:
			cout << "\nBye!\n";
			break;
		default:
			cout << "\nOpção Inválida!\n";
			break;
		}
	} while(op!=4);
    return 0;       
}
