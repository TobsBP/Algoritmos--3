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


int maior(treenodeptr arvore) {
    if (arvore == NULL)
        return 0; 
    int left_big = maior(arvore->left);
    int right_big = maior(arvore->right);
    return max(arvore->info, max(left_big, right_big));
}

int menor(treenodeptr arvore) {
    if (arvore == NULL)
        return 10000; 
    int left_min = menor(arvore->left);
    int right_min = menor(arvore->right);
    return min(arvore->info,min(left_min, right_min));
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
    
    int res_1 = maior(arvore);
    int res_2 = menor(arvore);

    cout << res_2 << " e " << res_1 << endl;

    return 0;
}