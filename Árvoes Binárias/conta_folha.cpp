#include <iostream>

using namespace std;

// Representação da arvore binaria
struct treenode {
    int info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

int contaFolhas(treenodeptr arvore) {
    if (arvore == nullptr)
        return 0;
    if (arvore->left == nullptr && arvore->right == nullptr)
        return 1;
    return contaFolhas(arvore->left) + contaFolhas(arvore->right);
}

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

int main() {
    treenodeptr arvore = NULL;
    int num;

    cin >> num;
    while (num != -1)
    {
        insert(arvore, num);
        cin >> num;
    }
    
    int folhas = contaFolhas(arvore);
    cout << folhas << endl;

    return 0;
}