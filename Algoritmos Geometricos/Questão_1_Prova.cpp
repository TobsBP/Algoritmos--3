#include <iostream>
#include <list>
using namespace std;

struct dados
{
    float V, E, O;
    int i, T; // Toxidade
};

// Representação da arvore binaria
struct treenode {
    dados info;
    struct treenode* left;
    struct treenode* right;
};

typedef treenode *treenodeptr;

// Insere um valor dado na arvore binaria 
treenodeptr insert(treenodeptr &p, dados x) {
    if (p == NULL) {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    } else if (x.T < p->info.T) {
        p->left = insert(p->left, x);
    } else {
        p->right = insert(p->right, x);
    }
    return p;
}

float calc_T(dados aux)
{
    // T = (V*E*7*7*O)
    return aux.V * aux.E * 7 * aux.E * 7 * aux.O;
}

void show_ordered(treenodeptr curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->info.i << ":" << curr->info.T << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

// Função para imprimir a árvore em nível
void emNivel(treenodeptr t, int Tmin, int Tmax) {
    if (t == NULL)
        return;

    list<treenodeptr> q;
    q.push_back(t);

    while (!q.empty()) {
        treenodeptr n = q.front();
        q.pop_front();

        if (n->info.T > Tmin && n->info.T < Tmax)
            cout << n->info.i << ":" << n->info.T << endl;
        
        if (n->left != NULL)
            q.push_back(n->left);
        if (n->right != NULL)
            q.push_back(n->right);
    }
}

void destruct(treenodeptr &curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

int main()
{
    treenodeptr arvore = NULL;
    int Tlinhas, Tmin, Tmax;
    dados aux;

    cin >> Tlinhas;

    for (int i = 0; i < Tlinhas; i++)
    {
        cin >> aux.V >> aux.E >> aux.O;
        aux.T = calc_T(aux); aux.i = i;
        insert(arvore, aux);
    }

    cin >> Tmin >> Tmax;
    
    emNivel(arvore, Tmin, Tmax);

    destruct(arvore);

    return 0;
}