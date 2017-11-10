#include <iostream>
#include <locale>

using namespace std;

struct celula
{
	int elem;
	celula *esq;
	celula *dir;
};

celula *inserir(celula *raiz, int v)
{
	if(raiz == NULL)
	{
		celula *nova = new celula;
    	nova->elem = v;
    	nova->esq = NULL;
    	nova->dir = NULL;
    	return nova;
	}
	else if(v < raiz->elem)					//se for menor insere a esquerda
		raiz->esq = inserir(raiz->esq, v);
	else if(v > raiz->elem)					//se for maior insere a direita
		raiz->dir = inserir(raiz->dir, v);
	else
	{
		cout << "\nElemento " << raiz->elem << " já existe na árvore\n";
	}
	return raiz;
	
}

void imprimirPreOrdem(celula *raiz, string lado)
{
	if(raiz != NULL)
	{
		cout << lado << ":" << raiz->elem << " ";
		imprimirPreOrdem(raiz->esq, "E");
		imprimirPreOrdem(raiz->dir, "D");
	}
}

void imprimirPosOrdem(celula *raiz, string lado)
{
	if(raiz != NULL)
	{
		imprimirPreOrdem(raiz->esq, "E");
		imprimirPreOrdem(raiz->dir, "D");
		cout << lado << ":" << raiz->elem << " ";
	}
}

int main()
{
	setlocale(LC_ALL,"Portuguese");
	
    celula *raiz = NULL; //cria arvore vazia
    
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 10); //não insere repetido
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 25);
    raiz = inserir(raiz, 19);
    raiz = inserir(raiz, 1);
    
    cout << "\nElementos da árvore Pre Ordem: ";
    imprimirPreOrdem(raiz,"R");
    
    cout << "\nElementos da árvore Pos Ordem: ";
    imprimirPosOrdem(raiz,"R");
    
    cout << endl;
    
    return 0;       
}
