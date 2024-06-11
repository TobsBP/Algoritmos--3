#include <iostream>
using namespace std;

// Representação de um nó de árvore binária
struct treenode {
    int info;
    int altura;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode* treenodeptr;

// Calcula a altura do nó
int height(treenodeptr p) {
    if (p == nullptr)
        return 0;
    return p->altura;
}

// Atualiza a altura do nó
int updateHeight(treenodeptr p) {
    if (p == nullptr)
        return 0;
    return 1 + max(height(p->left), height(p->right));
}

// Rotaciona à direita-direita
treenodeptr rotacionarDirDir(treenodeptr p) {
    treenodeptr right = p->right;
    p->right = right->left;
    right->left = p;
    p->altura = updateHeight(p);
    right->altura = updateHeight(right);
    return right;
}

// Rotaciona à esquerda-esquerda
treenodeptr rotacionarEsqEsq(treenodeptr p) {
    treenodeptr left = p->left;
    p->left = left->right;
    left->right = p;
    p->altura = updateHeight(p);
    left->altura = updateHeight(left);
    return left;
}

// Rotaciona à esquerda-direita
treenodeptr rotacionarEsqDir(treenodeptr p) {
    p->left = rotacionarDirDir(p->left);
    return rotacionarEsqEsq(p);
}

// Rotaciona à direita-esquerda
treenodeptr rotacionarDirEsq(treenodeptr p) {
    p->right = rotacionarEsqEsq(p->right);
    return rotacionarDirDir(p);
}

// Calcula o fator de balanceamento do nó
int balanceFactor(treenodeptr p) {
    if (p == nullptr)
        return 0;
    return height(p->left) - height(p->right);
}

// Balanceia a árvore
treenodeptr balancear(treenodeptr p) {
    if (p == nullptr)
        return nullptr;

    p->altura = updateHeight(p);
    int fator = balanceFactor(p);

    if (fator > 1) {
        if (balanceFactor(p->left) < 0)
            p = rotacionarEsqDir(p);
        else
            p = rotacionarEsqEsq(p);
    } else if (fator < -1) {
        if (balanceFactor(p->right) > 0)
            p = rotacionarDirEsq(p);
        else
            p = rotacionarDirDir(p);
    }
    return p;
}

// Insere um valor dado na árvore binária
treenodeptr insert(treenodeptr p, int x) {
    if (p == nullptr) {
        p = new treenode;
        p->info = x;
        p->left = nullptr;
        p->right = nullptr;
        p->altura = 1;
    } else if (x < p->info) {
        p->left = insert(p->left, x);
    } else {
        p->right = insert(p->right, x);
    }
    return p;
}

// Insere um valor dado na árvore AVL e a balanceia
treenodeptr AVLinsert(treenodeptr p, int x) {
    if (p == nullptr) {
        p = new treenode;
        p->info = x;
        p->left = nullptr;
        p->right = nullptr;
        p->altura = 1;
    } else if (x < p->info) {
        p->left = AVLinsert(p->left, x);
    } else {
        p->right = AVLinsert(p->right, x);
    }
    return balancear(p);
}

// Encontra o número procurado na árvore
bool search(treenode* p, int x, int &cont) {
    cont++;
    if (p == nullptr)
        return false;
    else if (p->info == x)
        return true;
    else if (x < p->info)
        return search(p->left, x, cont);
    else
        return search(p->right, x, cont);
}

int main() {
    treenodeptr arvore = nullptr;
    treenodeptr arvoreAVL = nullptr;
    int x, cont = 0;

    cin >> x;
    while (x != 0) {
        arvore = insert(arvore, x);
        arvoreAVL = AVLinsert(arvoreAVL, x);
        cin >> x;
    }

    cin >> x;

    search(arvore, x, cont);
    cout << "Arvore normal: " << cont << endl;

    cont = 0;
    search(arvoreAVL, x, cont);
    cout << "AVL: " << cont << endl;

    return 0;
}
