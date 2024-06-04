#include <iostream>
#include <string>
using namespace std;

struct dados
{
    string nome;
    string tipo;
};

struct treenode
{
    dados info;
    treenode *esq;
    treenode *dir;
};

typedef treenode *treenodeptr;

treenodeptr tinsert(treenodeptr &p, dados x)
{
    if (p == NULL)
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else
    {
        if (x.nome < p->info.nome)
            p->esq = tinsert(p->esq, x); // Recursivamente inserir à esquerda
        else
            p->dir = tinsert(p->dir, x); // Recursivamente inserir à direita
    }
    return p; // Retornar o ponteiro para o numero raiz da arvore atualizada
}

treenodeptr tsearch(treenodeptr p, string x)
{
    if (p == NULL)
        return NULL;
    else if (x == p->info.nome)
        return p;
    else if (x < p->info.nome)
        return tsearch(p->esq, x); // Recursivamente buscar à esquerda
    else
        return tsearch(p->dir, x); // Recursivamente buscar à direita
}

treenodeptr tmenor(treenodeptr &raiz)
{
    treenodeptr t;

    t = raiz;
    if (t->esq == NULL)
    {
        raiz = raiz->dir;
        return t;
    }
    else
        return tmenor(raiz->esq);
}

int tremove(treenodeptr &raiz, dados x)
{
    treenodeptr p;

    if (raiz == NULL)
        return 1;
    if (x.nome == raiz->info.nome && x.tipo == raiz->info.tipo)
    {
        p = raiz;
        if (raiz->esq == NULL)
            raiz = raiz->dir;
        else
        {
            if (raiz->dir == NULL)
                raiz = raiz->esq;
            else
            {
                p = tmenor(raiz->dir);
                raiz->info = p->info;
            }
        }
        delete p;
        return 0;
    }
    else if (x.nome < raiz->info.nome)
        return tremove(raiz->esq, x);
    else
        return tremove(raiz->dir, x);
}

int main()
{
    treenodeptr arvore = NULL;
    treenodeptr res = NULL;
    int res_remove;
    int op;
    dados aux;

    cin >> op;

    while (op != 0)
    {
        switch (op)
        {
            case 1:
                getline(cin >> ws, aux.nome);
                getline(cin >> ws, aux.tipo);
                tinsert(arvore, aux);
                break;
            case 2:
                getline(cin >> ws, aux.nome);
                res = tsearch(arvore, aux.nome);
                if (res == NULL)
                    cout << "Rocha nao encontrada" << endl;
                else
                {
                    cout << "Nome: " << res->info.nome << endl;
                    cout << "Tipo: " << res->info.tipo << endl;
                }
                break;
            case 3:
                getline(cin >> ws, aux.nome);
                getline(cin >> ws, aux.tipo);
                res_remove= tremove(arvore, aux);
                if (res_remove == 0)
                    cout << "Rocha removida com sucesso" << endl;
                else
                    cout << "Rocha nao encontrada para remocao" << endl;
                break;
            default:
                cout << "Operação inválida" << endl;
        }
        cin >> op;
    }

    return 0;
}