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

int main()
{
    treenodeptr arvore = NULL;
    int x, i, count;
    char input;

    cin >> count;

    for (i = 0; i < count; i++)
    {
        cin >> input;

        if (input == 'i')
        {
            cin >> x;
            insert(arvore, x);
        }

        if (input == 'b')
        {
            cin >> x;
            if (search(arvore, x))
                cout << "Sim" << endl;
            else
                cout << "Nao" << endl;
        }
    }



    return 0;
}