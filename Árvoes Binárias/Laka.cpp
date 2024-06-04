#include <iostream>
#include <string>
#include <list>
using namespace std;

// Representation of a binary tree node
struct treenode {
    int info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

// Insert a given value into the binary tree
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

void posOrdem(treenodeptr arvore, list<int> &res) {
    if (arvore != NULL) {
        posOrdem(arvore->left, res);
        posOrdem(arvore->right, res);
        res.push_back(arvore->info);
    }
}

void preOrdem(treenodeptr arvore, list<int> &res) {
    if (arvore != NULL) {
        res.push_back(arvore->info);
        preOrdem(arvore->left, res);
        preOrdem(arvore->right, res);
    }
}

void emOrdem(treenodeptr arvore, list<int> &res) {
    if (arvore != NULL) {
        emOrdem(arvore->left, res);
        res.push_back(arvore->info);
        emOrdem(arvore->right, res);
    }
}

string fast(list<int> res_pos, list<int> res_pre, list<int> res_em, int x) {
    int res_1 = -1, res_2 = -1, res_3 = -1;
    string menor;
    list<int>::iterator p;

    int i = 1;
    for (p = res_pos.begin(); p != res_pos.end(); p++) {
        if (*p == x) {
            res_1 = i;
            break;
        }
        i++;
    }

    i = 1;
    for (p = res_pre.begin(); p != res_pre.end(); p++) {
        if (*p == x) {
            res_2 = i;
            break;
        }
        i++;
    }

    i = 1;
    for (p = res_em.begin(); p != res_em.end(); p++) {
        if (*p == x) {
            res_3 = i;
            break;
        }
        i++;
    }
    
    if (res_1 < res_2 && res_1 < res_3)
        menor = "Pos";
    else if(res_2 < res_1 && res_2 < res_3)
        menor = "Pre";
    else if(res_3 < res_1 && res_3 < res_2)
        menor = "Em";

    return menor;
}

int main() {
    list<int> res_pos, res_em, res_pre;
    treenodeptr arvore = NULL;
    int x;
    string menor;

    cin >> x;

    while (x != -1) {
        insert(arvore, x);
        cin >> x;
    }
    
    cin >> x;

    posOrdem(arvore, res_pos);
    emOrdem(arvore, res_em);
    preOrdem(arvore, res_pre);

    menor = fast(res_pos, res_pre, res_em, x);

    cout << menor << endl;

    return 0;
}
