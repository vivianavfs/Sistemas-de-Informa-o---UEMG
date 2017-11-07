#include <iostream>

using namespace std;

struct celula
{
	int elem;
	celula *esq;
	celula *dir;
};

int main()
{
	celula *raiz = NULL;
	
	celula *nova = new celula;
	nova->elem = 20;
	nova->esq = NULL;
	nova->dir = NULL;
	
	raiz = nova;
	
	nova = new celula;
	nova->elem = 70;
	nova->esq = NULL;
	nova->dir = NULL;
	
	if(raiz->elem > nova->elem)
		raiz->esq = nova;
	else if(raiz->elem < nova->elem)
		raiz->dir = nova;
	else
		cout << "\né igual\n";
	
	
    return 0;       
}
