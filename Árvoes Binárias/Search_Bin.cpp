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

// Encontra o numero procurado
bool search(treenode* p, int x) {
    if (p == NULL)
        return false;
    else if (p->info == x)
        return true;
    else if (x < p->info)
        return search(p->left, x);
    else
        return search(p->right, x);
}

int main() {
    treenodeptr arvore = NULL; // Inicializa a alocação de memoria como null
    int i, count, num; // contadores e entrada

	// Quantidade de numeros
    cin >> count;

	// Chama a func insert para inserir os numeros na arvore
    for (i = 0; i < count; i++) {
        cin >> num;
        insert(arvore, num);
    }

	// Numero a ser encontrado
    cin >> num;

	// Dependendo do que a func search retorna sabe-se foi encontrado ou nao
    if (search(arvore, num) == true) {
        cout << "Encontrado" << endl;
    } else
        cout << "Nao encontrado" << endl;

    return 0;
}
