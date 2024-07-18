#include <iostream>

using namespace std;

struct dados
{
    string nome;
    string tipo;
};

// Representação da arvore binaria
struct treenode {
    dados info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, dados aux) {
    if (p == NULL) {
        p = new treenode;
        p->info = aux;
        p->left = NULL;
        p->right = NULL;
    } else if (aux.nome < p->info.nome) {
        p->left = insert(p->left, aux);
    } else {
        p->right = insert(p->right, aux);
    }
    return p;
}

// Encontra o numero procurado
treenodeptr search(treenode* p, string aux) {
    if (p == NULL)
        return NULL;
    else if (p->info.nome == aux)
        return p;
    else if (aux < p->info.nome)
        return search(p->left, aux);
    else
        return search(p->right, aux);
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

int tremove(treenodeptr &raiz, string x)
{
	treenodeptr p;

	if(raiz == NULL)
		return 1;
	if(x == raiz->info.nome)
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
	else if(x < raiz->info.nome)
		return tremove(raiz->left, x);
	else
		return tremove(raiz->right, x);
}

int main()
{
    treenodeptr arvore = NULL;
    treenodeptr res_search = NULL;
    dados aux;
    int op = -1;

    while (op != 0)
    {
        cin >> op;
        switch (op)
        {
        case 0:
            cout << "Finalizando" << endl;
            break;
        case 1:
            cin >> aux.nome >> aux.tipo;
            insert(arvore, aux);
            break;
        case 2:
            cin >> aux.nome;
            res_search = search(arvore, aux.nome);

            if (res_search != NULL)
            {
                cout << res_search->info.nome << endl; 
                cout << res_search->info.tipo << endl;
            }else
                cout << "Rocha nao encontrada" << endl;
            break;
        case 3:
            cin >> aux.nome;
            tremove(arvore, aux.nome);      
            break;
        default:
            cout << "Op errada" << endl;
            break;
        }     
    }
    
    return 0;
}