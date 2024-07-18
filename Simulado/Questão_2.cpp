#include <iostream>
using namespace std;

// Representação da arvore binaria
struct dados
{
    float espessura;
    float diametro;
    float altura;
    float peso;
    int PF;
    int code;
};

struct treenode {
    dados info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

float calc(dados p)
{
    return p.PF = (p.espessura* p.peso* p.altura) + (p.diametro + p.altura);
}

void show_ordered(treenodeptr curr, int min, int max){
	if(curr->left != NULL && curr->left->info.PF >= min && curr->left->info.PF <= max)
		show_ordered(curr->left, min, max);
	cout << curr->info.code << ":" << curr->info.PF << endl;
	if(curr->right != NULL && curr->right->info.PF >= min && curr->right->info.PF <= max)
		show_ordered(curr->right, min, max);
}

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, dados novo) {
    if (p == NULL) {
        p = new treenode;
        p->info = novo;
        p->left = NULL;
        p->right = NULL;
    } else if (novo.PF < p->info.PF) {
        p->left = insert(p->left, novo);
    } else {
        p->right = insert(p->right, novo);
    }
    return p;
}

void destruct(treenodeptr curr){
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
    int count, max, min;
    dados aux;
    
    cin >> count;
    
    for (int i = 0; i < count; i++)
    {
        cin >> aux.espessura >> aux.peso >> aux.altura >> aux.diametro;
        aux.code = i; aux.PF = calc(aux);
        insert(arvore, aux);
    }

    cin >> min >> max;
    show_ordered(arvore, min, max);
    
    destruct(arvore);
    
    return 0;
}