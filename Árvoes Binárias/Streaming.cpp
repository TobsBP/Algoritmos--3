#include <iostream>
#include <string>
using namespace std;

struct info
{
    string nome;
    string genero;
    int duracao;
    int classificacao;
    int ano;
};

struct treenode
{
    info filme;
    treenode *left;
    treenode *right;
};

typedef treenode *treenodeptr;

treenodeptr insert(treenodeptr &p, string nome, string genero, int duracao, int classificacao, int ano)
{
    if (p == NULL)
    {
        p = new treenode;
        p->filme.nome = nome;
        p->filme.genero = genero;
        p->filme.duracao = duracao;
        p->filme.classificacao = classificacao;
        p->filme.ano = ano;
        p->left = NULL;
        p->right = NULL;
    }
    else if (nome < p->filme.nome)
        p->left = insert(p->left, nome, genero, duracao, classificacao, ano);
    else if (nome > p->filme.nome)
        p->right = insert(p->right, nome, genero, duracao, classificacao, ano);

    return p;
}

treenodeptr search(treenodeptr &arvore, string nome)
{
    if (arvore == NULL || arvore->filme.nome == nome)
    {
        return arvore;
    }
    if (nome < arvore->filme.nome)
    {
        return search(arvore->left, nome);
    }
    return search(arvore->right, nome);
}

int main()
{
    treenodeptr arvore = NULL;
    string nome;
    int op;

    cin >> op;
    while(true)
    {
        switch (op)
        {
        case 1:
        {
            string genero;
            int duracao, classificacao, ano;
            getline(cin >> ws, nome);
            getline(cin >> ws, genero);
            cin >> duracao;
            cin >> classificacao;
            cin >> ano;
            arvore = insert(arvore, nome, genero, duracao, classificacao, ano);
            break;
        }
        case 2:
        {
            getline(cin >> ws, nome);
            treenodeptr movie = search(arvore, nome);
            if (movie != nullptr)
            {
                cout << "Nome: " << movie->filme.nome << endl;
                cout << "Genero: " << movie->filme.genero << endl;
                cout << "Duracao: " << movie->filme.duracao << " mins" << endl;
                cout << "Classificacao: " << movie->filme.classificacao << endl;
                cout << "Ano: " << movie->filme.ano << endl;
            }else
                cout << "Filme nao encontrado." << endl;
            
            break;
        }
        default:
            cout << "Operacao invalida" << endl;
            break;
        }
        
        cin >> op;
        if (op == 0)
            break;
    }
    return 0;
}