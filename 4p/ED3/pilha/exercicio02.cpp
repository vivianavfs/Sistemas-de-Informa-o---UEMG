#include <iostream>

using namespace std;

struct celula
{
	char elem;
	celula *prox;
};

struct pilha
{
	celula *topo;
};

void print(pilha p)
{
	if(p.topo){
		celula *aux = p.topo;
		while(aux){
			cout << aux->elem;
			aux = aux->prox;
		}
	}
}

void push(pilha &p, char c)
{
	celula *nova = new celula;
	nova->elem = c;
	nova->prox = p.topo;
	p.topo = nova;
}

int main()
{
	setlocale(LC_ALL,"");
	
	string palavra;
	pilha p;
	p.topo = NULL;
	
    cout << "Digite uma palavra: ";
    cin >> palavra;
    
    for(int i = 0; i < palavra.length(); i++)
	{
		push(p,palavra[i]);
	}
	
	print(p);
    
    return 0;       
}
