#include <iostream>
#include <list>

using namespace std;

struct treenode {
    int info;
    struct treenode *left;
    struct treenode *right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na árvore binária
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

// Função para imprimir a árvore em nível
void emNivel(treenodeptr t) {
    if (t == NULL)
        return;

    list<treenodeptr> q;
    q.push_back(t);

    while (!q.empty()) {
        treenodeptr n = q.front();
        q.pop_front();

        cout << n->info << " ";

        if (n->left != NULL)
            q.push_back(n->left);
        if (n->right != NULL)
            q.push_back(n->right);
    }
}

int main() {
    treenodeptr arvore = NULL;
    int x;

    // Inserindo alguns valores na árvore
    cin >> x;
    while (x != -1)
    {
        insert(arvore, x);
        cin >> x;
    }
    
    // Imprimindo a árvore em nível
    emNivel(arvore);

    return 0;
}
