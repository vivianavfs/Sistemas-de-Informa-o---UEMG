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
    cout << "\nEntre com os valores: ";
    do{
    	cout << "\n=> ";
    	cin >> n;
    	if(n>0)
			push(p1,n);
	}while(n>0);
	
    print(p1);
    
    return 0;       
}
