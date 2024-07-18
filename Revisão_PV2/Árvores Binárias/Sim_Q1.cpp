#include <iostream>
using namespace std;

struct dados
{
    float P, EM, A, D;
    int i, PF; // Preço do produto
};

// Representação da arvore binaria
struct treenode {
    dados info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, dados x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    } else if (x.PF < p->info.PF) {
        p->left = insert(p->left, x);
    } else {
        p->right = insert(p->right, x);
    }
    return p;
}

float calc_PF(dados aux)
{
    // PF = (EM*P*A+D+A)
    return aux.EM * aux.P * aux.A + aux.D + aux.A;
}

void show_ordered(treenodeptr curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->info.i << ":" << curr->info.PF << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

void destruct(treenodeptr &curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

int main()
{
    treenodeptr arvore = NULL;
    dados aux;
    int Tlinhas;

    cin >> Tlinhas;

    for (int i = 0; i < Tlinhas; i++)
    {
        cin >> aux.EM >> aux.P >> aux.A >> aux.D;
        aux.PF = calc_PF(aux); aux.i = i;
        insert(arvore, aux);
    }
    
    show_ordered(arvore);

    destruct(arvore);

    return 0;
}