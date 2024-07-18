#include <iostream>
#include <cmath>
using namespace std;

struct dados
{
    float c;
    int i;
};

// Representação da arvore binaria
struct treenode {
    dados info;
    struct treenode* left;
    struct treenode* right;
};

struct Ponto
{
    int x, y;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, dados x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    } else if (x.c < p->info.c) {
        p->left = insert(p->left, x);
    } else {
        p->right = insert(p->right, x);
    }
    return p;
}

float distancia(Ponto p[])
{
    float comp = sqrt((p[0].x - p[1].x)*(p[0].x - p[1].x) +
        (p[0].y - p[1].y)*(p[0].y - p[1].y));

    float comp_2 = sqrt((p[0].x - p[2].x)*(p[0].x - p[2].x) +
        (p[0].y - p[2].y)*(p[0].y - p[2].y));
    
    return max(comp, comp_2); 
}

void show_ordered(treenodeptr curr){
	if(curr->right != NULL)
		show_ordered(curr->right);
	cout << curr->info.i << ":" << curr->info.c << endl;
	if(curr->left != NULL)
		show_ordered(curr->left);
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
    Ponto p[1000];
    dados aux;
    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> p[j].x >> p[j].y;
        }
        aux.i = i;
        aux.c = distancia(p);
        insert(arvore, aux);
    }
    
    show_ordered(arvore);

    destruct(arvore);
       

    return 0;
}