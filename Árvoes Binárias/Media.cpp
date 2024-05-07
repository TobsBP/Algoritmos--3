#include <iostream>
#include <iomanip>

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

float media(treenode* arvore) {
    int soma = 0, cont = 0;

    if (arvore == NULL)
        return 0;
    else {
        soma += arvore->info;
        cont++; // Increment the count for the current node
        if(arvore->left!= NULL)
        {
            soma += media(arvore->left);
            if(arvore->left != NULL)
                cont += 1;
            else
                cont += 0;
        }
        if(arvore->right!= NULL)
        {
            soma += media(arvore->right);
            if(arvore->right != NULL)
                cont += 1;
            else
                cont += 0;
        }
    }
    return (float)soma / cont;
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

    cout << setprecision(2) << fixed << endl;     
    cout << "Media: " << media(arvore) << endl;

    return 0;
}
