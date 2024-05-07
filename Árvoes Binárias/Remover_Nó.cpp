#include <iostream>
#include <list>

using namespace std;

// Representação da arvore binaria
struct treenode
{
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria
treenodeptr insert(treenodeptr &p, int x)
{
    if (p == NULL)
    {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else if (x < p->info)
    {
        p->left = insert(p->left, x);
    }
    else
    {
        p->right = insert(p->right, x);
    }
    return p;
}

// Encontra o numero procurado
treenodeptr search(treenode *p, int x)
{
    if (p == NULL)
        return p;
    else if (p->info == x)
        return p;
    else if (x < p->info)
        return search(p->left, x);
    else
        return search(p->right, x);
}

treenodeptr menor(treenodeptr &raiz)
{
    treenodeptr t = raiz;

    if (t->left == NULL)
    {
        raiz = raiz->right;
        return t;
    }
    else
        return menor(raiz->left);
}

int remove(treenodeptr &raiz, int x)
{
    treenodeptr p;

    if (raiz == NULL)
        return 1;

    if (x == raiz->info)
    {
        p = raiz;
        if (raiz->left == NULL)
            raiz = raiz->right;
        else if (raiz->right == NULL)
            raiz = raiz->left;
        else
        {
            p = menor(raiz->right);
            raiz->info = p->info;
        }
        delete p;
        return 0;
    }
    else if (x < raiz->info)
        return remove(raiz->left, x);
    else
        return remove(raiz->right, x);
}

void exib(treenodeptr arvore)
{
    int menor = 9999;

    if (menor < arvore->info)
        return exib(arvore->left);
    else
        return exib(arvore->right);
}

int main()
{
    treenodeptr arvore = NULL;
    int x, i = 0;
    list<int> res;

    cin >> x;
    while (x != 0)
    {
        insert(arvore, x);
        cin >> x;
    }

    cin >> x;

    while (remove(arvore,x) == 0)
    {
        remove(arvore, x);
    }

    exib(arvore);

    return 0;
}