#include <iostream>
using namespace std;

struct treenode
{
    int info;
    treenode *left;
    treenode *right;    
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

int descobrir(treenodeptr arvore)
{
    if (arvore == NULL) 
        return 0;
    if (arvore->info <= 1) 
        return 0;
    if (arvore->info == 2)
        return 1;
    if (arvore->info % 2 == 0) 
        return 0;
    for (int i = 3; i * i <= arvore->info; i += 2) {
        if (arvore->info % i == 0) 
            return 0;
    }
    return 1;
}

int contaPrimos(treenodeptr arvore)
{
    if (arvore == NULL)
        return 0;

    int impar = descobrir(arvore);
    impar += contaPrimos(arvore->left);
    impar += contaPrimos(arvore->right);

    return impar;
}

int main()
{
    treenodeptr arvore = NULL;
    int num;

    cin >> num;
    while (num != -1)
    {
        insert(arvore, num);
        cin >> num;
    }
    
    cout << contaPrimos(arvore) << " numeros primos"<< endl;

    return 0;
}