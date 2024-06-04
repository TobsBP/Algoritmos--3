#include <iostream>
#include <string>
#include <limits>
#include <clocale>
#include <list>
#include <climits>
using namespace std;
 
/*      INTEGRANTES DO GRUPO
Tobias Bueno Pereira - 418 - GES
Rodrigo Armengol de Oliveira - 294 - GES
Igor de Araújo Fonseca - 479 - GES
Thiago Damas Ferreira Silva - 214 - GEC
André Rocha de Mesquita - 2017 - GEC
*/
 
#define quantidade 100
 
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
 
 
void adicionarAresta(no cidades[], int origem, int destino, int peso)
{
	cidades[origem].arestas.push_back( {destino, 1});
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
 
void exibir_menu()
{
	setlocale(LC_ALL, "Portugese");
	cout << "------------------------Selecione uma opção-----------------------" << endl;
	cout << "1 - Inserir cidades\n2 - Exibir cidades\n3 - Sair" << endl;
	cout << "------------------------------------------------------------------" << endl;
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
 
 
void choose(no cidades[]) // menu de opções
{
	setlocale(LC_ALL, "Portugese");
	int option, num_cidades;
 
	do
	{
		exibir_menu();
		cout << "Opção: ";
		while (!(cin >> option) || option < 1 || option > 5)
		{
			cout << "Opção inválida. Apenas números entre 1 e 3." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Opção: ";
		}
 
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
			shortest_path_dijkstra(cidades,num_cidades,0,num_cidades);
			break;
		default:
			cout << "Opção inválida. Tente novamente." << endl;
			break;
		}
	}
	while (option != 3);
 
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Programa finalizado com sucesso!!" << endl;
}
 
int main()
{
	no cidades[quantidade];
 
	choose(cidades);


 
	return 0;
}