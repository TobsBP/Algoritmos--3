#include <iostream>
#include <iomanip>
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

void show_ordered(treenodeptr curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
    cout << setprecision(0) << fixed; 
	cout << curr->info.code << ":" << curr->info.PF << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
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
    dados aux;
    int count;
    
    cin >> count;
    
    for (int i = 0; i < count; i++)
    {
        cin >> aux.espessura >> aux.peso >> aux.altura >> aux.diametro;
        aux.code = i; aux.PF = calc(aux);
        insert(arvore, aux);
    }

    show_ordered(arvore);
    
    destruct(arvore);
    
    return 0;
}