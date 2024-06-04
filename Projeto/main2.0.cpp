#include <iostream>
#include <climits>
#include <string>
#include <list>
using namespace std;

#define quantidade 100

struct pokemon
{
    string nome;
    string tipo;
    int local[1];
    int codigo;
};

struct treenode
{
    pokemon new_pokemon;
    treenode *left;
    treenode *right;
};

struct cidades
{
	bool centro_pokemon;
	string nome;
};
 
struct no
{
	int destino;
	int peso ;
	cidades info;
 
	list<no> arestas;
};

typedef treenode *treenodeptr;

void adicionarAresta(no cidades[], int origem, int destino, int peso)
{
	cidades[origem].arestas.push_back( {destino, 1});
}

void insert_nome(treenodeptr &arvore, pokemon new_pokemon)
{
	if(arvore == NULL){ 
		arvore = new treenode;
        arvore -> new_pokemon = new_pokemon; 
		arvore -> left = NULL; 
		arvore -> right = NULL;
	}else if(arvore -> new_pokemon.nome > new_pokemon.nome)
		insert_nome(arvore -> left, new_pokemon); 
	else
		insert_nome(arvore -> right, new_pokemon);
}

void insert_tipo(treenodeptr &arvore, pokemon new_pokemon)
{
	if(arvore == NULL){ 
		arvore = new treenode;
        arvore -> new_pokemon = new_pokemon; 
		arvore -> left = NULL; 
		arvore -> right = NULL;
	}else if(arvore -> new_pokemon.tipo > new_pokemon.tipo)
		insert_tipo(arvore -> left, new_pokemon); 
	else
		insert_tipo(arvore -> right, new_pokemon);
}

void mostraInfo(treenodeptr &arvore)
{
    cout << "Nome: " << arvore -> new_pokemon.nome << endl;
    cout << "Tipo: " << arvore -> new_pokemon.tipo << endl;
    cout << "Codigo: " << arvore -> new_pokemon.codigo << endl;
    cout << "Localização: x = " << arvore -> new_pokemon.local[0] << " Localização: y = " << arvore -> new_pokemon.local[1] << endl;
}

void exibir(treenodeptr &arvore)
{
    if (arvore != NULL)
    {
        exibir(arvore->left);
        mostraInfo(arvore);
        exibir(arvore->right);
    }
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
			getline(cin >> ws, cidades[i].info.nome);
		}
		while (cidades[i].info.nome.empty());
 
		cout << "Essa cidade tem um centro Pokemon? (Sim/Não)" << endl;
		do
		{
			getline(cin >> ws, test);
		}
		while (test.empty());
 
		if (test == "Sim")
		{
			cidades[i].info.centro_pokemon = true;
		}
		else if(test == "Não")
		{
			cidades[i].info.centro_pokemon = false;
		}
 
		cout << "Essa cidade tem alguma cidade vizinha? (Sim/Não)" << endl;
		do
		{
			getline(cin >> ws, test);
		}
		while (test.empty());
 
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
		else if(test == "Não")
		{
			cidades[i].arestas.push_back( {0, 0});
		}
	}
	cout << "-------------------------------------------------------------------" << endl;
 
}

void menu()
{
    setlocale(LC_ALL, "Portugese");
    cout << "------------------------Selecione uma opção-----------------------" << endl;
    cout << "1 - Inserir Pokemon" << endl;
    cout << "2 - Encontrar Pokemon por nome" << endl;
    cout << "3 - Exibir Pokemons por nomes" << endl;
    cout << "4 - Exibir Pokemons por tipo" << endl;
    cout << "5 - Exibir quantos Pokemons tem de cada tipo" << endl;
    cout << "0 - Sair" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void exibir_city(no cidades[], int num_cidades)
{
	cout << "----------------------Exibir Grafo--------------------------" << endl;
	list<no>::iterator p;
 
	for (int i = 0; i < num_cidades; i++)
	{
		cout << "Cidade: " << cidades[i].info.nome << endl;
		cout << "Centro Pokemon: ";
		cout << (cidades[i].info.centro_pokemon ? "Sim" : "Não") << endl;
 
		cout << "Cidades vizinhas: ";
 
		for (p = cidades[i].arestas.begin(); p != cidades[i].arestas.end(); p++)
		{
			cout << p->destino << " " << p->peso << endl;
		}
	}
	cout << "-------------------------------------------------------------------" << endl;
}

void shortest_path_dijkstra(no cidades [], int vertices, int start, int end)
{
	bool intree[vertices];
	int distance[vertices], parent[vertices], saltos[vertices];
 
	for(int u = 0; u < vertices; u++)
	{
		intree[u] = false;
		distance[u] = INT_MAX;
		parent[u] = -1;
	}
		distance[start] = 0;
		int v = start;
		while(intree[v] == false)
		{
			intree[v] = true;
			list<no>::iterator p;
			for(p = cidades[v].arestas.begin(); p != cidades[v].arestas.end(); p++)
			{
				int dest = p->destino;
				int weight = p->peso;
				if(distance[dest] > distance[v] + weight)
				{
					distance[dest] = distance[v] + weight;
					parent[dest] = v;
				}
			}
			v = 0;
			int dist = INT_MAX;
			for(int u = 0; u < vertices; u++)
			{
				if(intree[u] == false && distance[u] < dist)
				{
					dist = distance[u];
					v = u;
				}
			}
		}
		for(int i = 0; i < vertices ; i++)
		{
			if(cidades[i].info.centro_pokemon)
			{
				cout << distance[i] << " ";
			}
		}
 
 
}

treenodeptr search(treenodeptr arvore, string pokemon_nome)
{
	if(arvore == NULL)
		return NULL; 
    else if(arvore -> new_pokemon.nome == pokemon_nome)
		return arvore;
    else if(arvore -> new_pokemon.nome > pokemon_nome)
		return search(arvore -> left, pokemon_nome); 
    else
		return search(arvore -> right, pokemon_nome); 
}

int main()
{
    treenodeptr ar_nome = NULL;
    treenodeptr ar_tipo = NULL;
    treenodeptr res = NULL;
    no cidades[quantidade];
    int num_cidades;
    int opcao = -1;
    int terra = 0;
    int agua = 0;
    int fogo = 0;
    pokemon aux;

    while (opcao != 0)
    {
        menu();
        cout << "Opção: "; cin >> opcao;
            cout << endl;

        switch (opcao)
        {
        case 0:
            cout << "Programa finalizado!" << endl;
            break;
        case 1:
            cout << "Digite o nome do Pokemon: ";
            cin >> aux.nome;
            cout << "Digite o tipo do Pokemon (Terra/Fogo/Agua): ";
            cin >> aux.tipo;
            cout << "Digite a localização do Pokemon: ";
            cin >> aux.local[0] >> aux.local[1];
            cout << "Digite o numero do Pokemon: ";
            cin >> aux.codigo;

            if (aux.tipo == "Terra")
                terra++;
            else if(aux.tipo == "Agua")
                agua++;
            else if(aux.tipo == "Fogo")
                fogo++;

            insert_nome(ar_nome, aux);
            insert_tipo(ar_tipo, aux);
            break;
        case 2:
            cout << "Digite o nome do Pokemon que deseja encontrar: ";
            cin >> aux.nome; cout << endl;
            res = search(ar_nome, aux.nome);

            if (res == NULL)
                cout << "Pokemon não encontrado!" << endl;
            else
                cout << "Pokemon encontrado!" << endl;

            break;
        case 3:
            cout << "------------------ Pokemons Cadastrados por nomes ------------------" << endl;
            exibir(ar_nome);
            break;
        case 4:
            cout << "------------------ Pokemons Cadastrados por tipos ------------------" << endl;
            exibir(ar_tipo);
            break;
        case 5:
            cout << "---------------- Quantidade de Pokemons de cada tipo ---------------" << endl;
            cout << "Fogo: " << fogo << endl;
            cout << "Agua: " << agua << endl;
            cout << "Terra: " << terra << endl;
            break;
        case 6:
			cout << "Digite a quantida de cidades que deseja cadastrar: ";
			cin >> num_cidades;
			cadastro_city(cidades, num_cidades);
			break;
        case 7:
            exibir_city(cidades, num_cidades);
            break;
        case 8:
            shortest_path_dijkstra(cidades,num_cidades,0,num_cidades);
            break;
        default:
            cout << "Opcao Invalida!" << endl;
            break;
        }
    }

    tdestruir(ar_tipo);
    
    return 0;
}