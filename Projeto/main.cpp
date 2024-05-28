#include <iostream>
#include <string>
#include <limits>
#include <clocale>
#include <list>
using namespace std;

/*      INTEGRANTES DO GRUPO
Tobias Bueno Pereira - 418 - GES
Rodrigo Armengol de Oliveira - 294 - GES
Igor de Araújo Fonseca - 479 - GES
Thiago Damas Ferreira Silva - 214 - GEC
André Rocha de Mesquita - 2017 - GEC
*/

#define quantidade 100

struct aresta
{
    int destino;
    int peso;
};

struct no
{
    bool centro_pokemon;
    string nome;
    list<aresta> arestas;
};

void adicionarAresta(no cidades[], int origem,int destino, int peso)
{
    cidades[origem].arestas.push_back({destino, peso});
}

void cadastro_city(no cidades[], int num_cidades) // cadastro de cidades
{
    string test;
    list<no>:: iterator p;
    int v, peso, num_vizinhas;

    setlocale(LC_ALL, "Portugese");
    cout << "----------------------Cadastrar cidade--------------------------" << endl;

    for (int i = 0; i < num_cidades; i++)
    {
        cout << "Digite o nome da cidade: ";
        do
        {
            getline(cin >> ws, cidades[i].nome);
        } while (cidades[i].nome.empty());

        cout << "Essa cidade tem um centro Pokemon? (Sim/Não)" << endl;
        do
        {
            getline(cin >> ws, test);
        } while (test.empty());

        if (test == "Sim"){
            cidades[i].centro_pokemon = true;
        }else if(test == "Não"){
            cidades[i].centro_pokemon= false;
        }

        cout << "Essa cidade tem alguma cidade vizinha? (Sim/Não)" << endl;
        do
        {
            getline(cin >> ws, test);
        } while (test.empty());

        if (test == "Sim")
        {
            cout << "Digite a quantidade de cidades vizinhas: ";
            cin >> num_vizinhas;

            cout << "Digite respectivamente o destino, e a distância: ";
            for (int x = 0; x < num_vizinhas; x++)
            {
                cin >> v >> peso;
                adicionarAresta(cidades, i, v, peso);
            }
        }
        else if(test == "Não"){
            cidades[i].arestas.push_back({0, 0});
        }
    }
    cout << "-------------------------------------------------------------------" << endl;
}

void exibir_menu()
{
    setlocale(LC_ALL, "Portugese");
    cout << "------------------------Selecione uma opção-----------------------" << endl;
    cout << "1 - Inserir cidades\n2 - Exibir cidades\n3 - Cadastrar Pokemon\n4 - Exibir Pokemons\n5 - Sair" << endl;
    cout << "------------------------------------------------------------------" << endl;
}

void exibir_city(no cidades[], int num_cidades)
{
    cout << "----------------------Exibir Grafo--------------------------" << endl;
    list<aresta>::iterator p;

    for (int i = 0; i < num_cidades; i++)
    {
        cout << "Cidade: " << cidades[i].nome << endl;
        cout << "Centro Pokemon: ";
        cout << (cidades[i].centro_pokemon ? "Sim" : "Não") << endl;

        cout << "Cidades vizinhas: ";

        for (p = cidades[i].arestas.begin(); p != cidades[i].arestas.end(); p++)
        {
            cout << p->destino << " " << p->peso << endl;
        }
    }
    cout << "-------------------------------------------------------------------" << endl;
}

struct Pokemon
{
    string nome;
    string tipo;
    int code; 
};

struct treenode
{
    Pokemon info;
    treenode *left;
    treenode *right;
};

typedef treenode *treenodeptr;

treenodeptr insert(treenodeptr &p, Pokemon new_pokemon)
{
    if (p == NULL)
    {
        p = new treenode;
        p->info = new_pokemon;
        p->left = NULL;
        p->right = NULL;
    }
    else if (new_pokemon.nome < p->info.nome)
        p->left = insert(p->left, new_pokemon);
    else if (new_pokemon.nome > p->info.nome)
        p->right = insert(p->right, new_pokemon);

    return p;
}

void mostraInfo(treenodeptr &arvore)
{
    cout << arvore->info.nome << endl;
}

void exib(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        exib(arvore->left);
        mostraInfo(arvore);
        exib(arvore->right);
    }
}

void choose(no cidades[], treenodeptr arvore) // menu de opções
{
    setlocale(LC_ALL, "Portugese");
    int option, num_cidades, count, i;
    Pokemon new_pokemon;

    do
    {
        exibir_menu();
        cout << "Opção: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Digite a quantida de cidades que deseja cadastrar: ";
            cin >> num_cidades;
            cadastro_city(cidades, num_cidades);
            break;
        case 2:
            exibir_city(cidades, num_cidades);
            break;
        case 3:
            cout << "Digite a quantida de Pokemons que deseja cadastrar: ";
            cin >> count;
            for (i = 0; i < count; i++)
            {   
                cout << "Digite o nome do Pokemon: ";
                getline(cin >> ws, new_pokemon.nome);
                cout << "Digite o tipo do Pokemon: ";
                getline(cin >> ws, new_pokemon.tipo);
                cout << "Digite o codigo do Pokemon: ";
                cin >> new_pokemon.code;
                insert(arvore, new_pokemon);
            }
        case 4:
            cout << "Exibir Pokemons cadastrados"<< endl;
            exib(arvore);
            break;
        case 5:
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
    } while (option != 5);

    cout << "-------------------------------------------------------------------" << endl;
    cout << "Programa finalizado com sucesso!!" << endl;
}

void tdestruir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        tdestruir(arvore->left);        
        tdestruir(arvore->right);
        delete arvore;
    }
    arvore = NULL;
}

int main()
{
    no cidades[quantidade];
    treenodeptr arvore = NULL;

    choose(cidades, arvore);

    tdestruir(arvore);

    return 0;
}