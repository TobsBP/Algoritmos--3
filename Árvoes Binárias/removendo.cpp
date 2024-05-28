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

void emOrdem(treenodeptr arvore)
{
	if(arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}

void tDestruir(treenodeptr & arvore)
{
	if(arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}

int main()
{
	int x;
	int removeu;
	int numbers;
	treenodeptr arvore = NULL;
	
	while(numbers != 0)
	{

		cin >> numbers;
		if(numbers != 0)
			tinsert(arvore, numbers);
	}
	
	cin >> x; //numero a ser removido;

	do
	{
		removeu = tremove(arvore, x);
	}
	while(removeu == 0);
	
	emOrdem(arvore);

	tDestruir(arvore);

	return 0;
}