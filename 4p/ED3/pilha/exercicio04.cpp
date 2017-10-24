#include <iostream>

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

void push(pilha &p, int n)
{
	celula *nova = new celula;
	nova->elem = n;
	nova->prox = p.topo;
	p.topo = nova;
}

void print(pilha p){
	if(p.topo){
		celula *aux = p.topo;
		while(aux)
		{
			cout << aux->elem << endl;
			aux = aux->prox;
		}
	}
}

int main()
{
    int n;
    pilha p1;
    p1.topo = NULL;
    while(true){
    	cout << "\nDigite um numero: ";
    	cin >> n;
    	if(n<=0)
    		break;
		push(p1,n);
	}
    print(p1);
    
    return 0;       
}
