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

void split(pilha &p1, pilha &par, pilha &impar){
	if(p1.topo){
		celula *aux = p1.topo;
		while(aux)
		{
			if(aux->elem%2==0)
			{
				push(par,aux->elem);
			}
			else
			{
				push(impar,aux->elem);
			}
			aux = aux->prox;
		}
	}
}

int main()
{
    int n;
    
    pilha p1,par,impar;
    p1.topo = NULL;
    par.topo = NULL;
    impar.topo = NULL;
    
    cout << "\nEntre com os valores: ";
    do{
    	cout << "\n=> ";
    	cin >> n;
    	if(n>0)
			push(p1,n);
	}while(n>0);
	
	cout << "\nPilha Original\n";
    print(p1);
    
    split(p1,par,impar);
    
    cout << "\nPilha par\n";
    print(par);
    
    cout << "\nPilha impar\n";
    print(impar);
    
    return 0;       
}
