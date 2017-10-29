#include <iostream>
#include <locale>

using namespace std;

struct celula
{
    string nome;
    int id;
    celula *prox;
};

struct fila
{
    celula *inicio;
    celula *fim;
};

void print(fila f)
{
    if(f.inicio)
    {
        celula *aux = f.inicio;
        while(aux)
        {
            cout << "Nome: " << aux->nome << " ID: " << aux->id << endl;
            aux = aux->prox;
        }
    }
    else
    {
        cout << "\nNão há aviões aguardando na fila de decolagem\n";
    }
}

void countAvioes(fila f)
{
    int c=0;
    if(f.inicio)
    {
        celula *aux = f.inicio;
        while(aux)
        {
            c++;
            aux = aux->prox;
        }
        cout << "\nQuantidade: " << c << endl;
    }
    else
    {
        cout << "\nNão há aviões aguardando na fila de decolagem\n";
    }
}

void autorizarDecolagem(fila &f)
{
    if(f.inicio)
    {
        celula *aux = f.inicio;
        f.inicio = f.inicio->prox;
        cout << "\nAvião " << aux->nome << " decolando...\n";
        delete aux;
    }
    else
    {
        cout << "\nNão há aviões aguardando na fila de decolagem\n";
    }
}

void addAviao(fila &f, string nome, int id)
{
    celula *nova = new celula;
    nova->nome = nome;
    nova->id = id;
    nova->prox = NULL;
    if(f.inicio)
    {
        f.fim->prox = nova;
    }
    else
    {
        f.inicio = nova;
    }
    f.fim = nova;
}

void primeiro(fila f)
{
    if(f.inicio)
    {
        cout << "\nNome: " << f.inicio->nome << " ID: " << f.inicio->id << endl;

    }
    else
    {
        cout << "\nNão há aviões aguardando na fila de decolagem\n";
    }
}

int main()
{
    setlocale(LC_ALL,"");

    int op;
    fila decolagem;
    decolagem.inicio = NULL;
    decolagem.fim = NULL;

    string nome;
    int id;

    do
    {
        cout << "\n1) Listar o número de aviões aguardando na fila de decolagem\n";
        cout << "\n2) Autorizar a decolagem do primeiro avião da fila\n";
        cout << "\n3) Adicionar um avião à fila de espera\n";
        cout << "\n4) Listar todos os aviões na fila de espera\n";
        cout << "\n5) Listar as características do primeiro avião da fila\n";
        cout << "\n0 - Sair:\n=>";
        cin >> op;

        switch(op)
        {
        case 1:
            countAvioes(decolagem);
            break;
        case 2:
            autorizarDecolagem(decolagem);
            break;
        case 3:
            cout << "\nNome: ";
            cin >> nome;
            cout << "\nID: ";
            cin >> id;

            addAviao(decolagem, nome, id);
            break;
        case 4:
            print(decolagem);
            break;
        case 5:
            primeiro(decolagem);
            break;
        case 0:
            break;
        default:
            cout << "\nOpção Invalida!\n";
            break;
        }

    }while (op!=0);

    return 0;
}
