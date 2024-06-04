#include <iostream>
using namespace std;

// Representação da arvore binaria
struct treenode {
    int info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, int x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    } else if (x < p->info) {
        p->left = insert(p->left, x);
    } else {
        p->right = insert(p->right, x);
    }
    return p;
}

void posOrdem(treenodeptr arvore)
{
    if (arvore != NULL)
    {
        posOrdem(arvore->right);
        cout << arvore->info << endl;
        posOrdem(arvore->left);
    }
}

int main()
{
    treenodeptr arvore = NULL;
    int x;

    cin >> x;

    while (x != -1)
    {
        insert(arvore, x);
        cin >> x;
    }
    
    posOrdem(arvore);

    return 0;
}