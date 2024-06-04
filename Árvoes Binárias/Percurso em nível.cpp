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

void preOrdem(treenodeptr arvore) {
    if (arvore != NULL) {
        cout << arvore->info << " ";
        preOrdem(arvore->left);  
        preOrdem(arvore->right); 
    }
}

void tdestruir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tdestruir(arvore->left);        
        tdestruir(arvore->right);
        delete arvore;
    }
    arvore = NULL;
}

int main() {
    treenodeptr arvore = NULL;
    int num;

    cin >> num;
    while (num != -1)
    {
        insert(arvore, num);
        cin >> num;
    }

    cout << "preOrdem " << endl;
    preOrdem(arvore); cout << endl;

    tdestruir(arvore);

    return 0;
}
