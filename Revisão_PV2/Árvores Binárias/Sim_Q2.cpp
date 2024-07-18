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

void show_ordered(treenodeptr curr, int PFmin, int PFmax){
	if(curr->left != NULL && curr->left->info.PF >= PFmin && curr->left->info.PF <= PFmax)
		show_ordered(curr->left, PFmin, PFmax);
	cout << curr->info.i << ":" << curr->info.PF << endl;
	if(curr->right != NULL && curr->right->info.PF >= PFmin && curr->right->info.PF <= PFmax)
		show_ordered(curr->right, PFmin, PFmax);
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
    int Tlinhas, PFmin, PFmax;
    dados aux;

    cin >> Tlinhas;

    for (int i = 0; i < Tlinhas; i++)
    {
        cin >> aux.EM >> aux.P >> aux.A >> aux.D;
        aux.PF = calc_PF(aux); aux.i = i;
        insert(arvore, aux);
    }
    
    cin >> PFmin >> PFmax;
    
    show_ordered(arvore, PFmin, PFmax);

    destruct(arvore);

    return 0;
}