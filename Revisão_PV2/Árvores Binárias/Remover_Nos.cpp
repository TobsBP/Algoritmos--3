#include <iostream>

using namespace std;

struct treenode
{
	int info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode* treenodeptr;

treenodeptr tinsert(treenodeptr &p, int x)
{
	if (p == NULL)
	{
		p = new treenode;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (x < p->info)
			p->left = tinsert(p->left, x); // Recursivamente inserir à esquerda
		else
			p->right = tinsert(p->right, x); // Recursivamente inserir à direita
	}
	return p; // Retornar o ponteiro para o numero raiz da arvore atualizada
}

treenodeptr tsearch(treenodeptr p, int x)
{
	if (p == NULL)
		return NULL;
	else if (x == p->info)
		return p;
	else if (x < p->info)
		return tsearch(p->left, x); // Recursivamente buscar à esquerda
	else
		return tsearch(p->right, x); // Recursivamente buscar à direita
}

treenodeptr tmenor(treenodeptr &raiz)
{
	treenodeptr t;

	t = raiz;
	if(t->left == NULL)
	{
		raiz = raiz->right;
		return t;
	}
	else
		return tmenor(raiz->left);
}

int tremove(treenodeptr &raiz, int x)
{
	treenodeptr p;

	if(raiz == NULL)
		return 1;
	if(x == raiz->info)
	{
		p = raiz;
		if(raiz->left == NULL)
			raiz = raiz->right;
		else
		{
			if(raiz->right == NULL)
				raiz = raiz->left;
			else
			{
				p = tmenor(raiz->right);
				raiz->info = p->info;
			}
		}
		delete p;
		return 0;
	}
	else if(x < raiz->info)
		return tremove(raiz->left, x);
	else
		return tremove(raiz->right, x);
}

void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->left);
		cout << arvore->info << " ";
		emOrdem(arvore->right);
	}
}

void tDestruir(treenodeptr & arvore)
{
	if(arvore != NULL)
	{
		tDestruir(arvore->left);
		tDestruir(arvore->right);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
    treenodeptr arvore = NULL;
    int x;

    cin >> x;

    while (x != 0)
    {
        tinsert(arvore, x);
        cin >> x;
    }
    
    cin >> x;

    while(tsearch(arvore, x) != 0)
        tremove(arvore, x); 

    emOrdem(arvore);

    tDestruir(arvore);

    return 0;
}