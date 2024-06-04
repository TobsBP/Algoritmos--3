#include <iostream>
using namespace std;

struct treenode
{
	int info;
	treenode* esq;
	treenode* dir;
};

typedef treenode* treenodeptr;

treenodeptr tinsert(treenodeptr &p, int x)
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
		if (x < p->info)
			p->esq = tinsert(p->esq, x); // Recursivamente inserir à esquerda
		else
			p->dir = tinsert(p->dir, x); // Recursivamente inserir à direita
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
		return tsearch(p->esq, x); // Recursivamente buscar à esquerda
	else
		return tsearch(p->dir, x); // Recursivamente buscar à direita
}

treenodeptr tmenor(treenodeptr &raiz)
{
	treenodeptr t;

	t = raiz;
	if(t->esq == NULL)
	{
		raiz = raiz->dir;
		return t;
	}
	else
		return tmenor(raiz->esq);
}

int tremove(treenodeptr &raiz, int x)
{
	treenodeptr p;

	if(raiz == NULL)
		return 1;
	if(x == raiz->info)
	{
		p = raiz;
		if(raiz->esq == NULL)
			raiz = raiz->dir;
		else
		{
			if(raiz->dir == NULL)
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
	else if(x < raiz->info)
		return tremove(raiz->esq, x);
	else
		return tremove(raiz->dir, x);
}

int main()
{
    treenodeptr arvore = NULL;
    int i, N, x;
    char op;

    cin >> N;

    for (i = 1; i <= N; i++)
    {
        cin >> op >> x;

        switch (op)
        {
        case 'i':
            tinsert(arvore, x);
            break;
        case 'r':
            tremove(arvore, x);
            break;
        case 'b':
            if(tsearch(arvore, x) == NULL)
                cout << "Nao" << endl;
            else
                cout << "Sim" << endl;
        default:
            break;
        }
    }

    return 0;
}