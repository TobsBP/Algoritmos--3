#include <iostream>
#include <climits>
#include <list>

using namespace std;

#define VERTICES 10

struct no
{
  int orig;
  int dist;
  int peso;
  float idh;
};

struct cidade
{
  string nome;
	int codigo;
	float idh;
	list<no> vizinhos;
};

void cria_aresta(list<no>adj[], int u, int v, int peso, float idh, int orientado)
{
  no aux;

  aux.dist = v;
  aux.peso = peso;
  aux.idh = idh;
  adj[u].push_back(aux);

  if (orientado == 0)
  {
    aux.dist = u;
    adj[v].push_back(aux);
  }
}

void dijkstra(list<no>adj[], int nVertices, int start, int end, float idh)
{
  bool intree[nVertices];
  int distance[nVertices];
  int parent[nVertices];
  int v, dest, weight, dist;

  for (int u = 0; u < nVertices; u++)
  {
    intree[u] = false;
    distance[u] = INT_MAX;
    parent[u] = -1;
  }
  
  distance[start] = 0;
  v = start;

  while (intree[v] == false)
  {
    intree[v] = true;
    list<no>::iterator p;
    for (p = adj[v].begin(); p != adj[v].end(); p++)
    {
      dest = p->dist;
      weight = p->peso;

      if (distance[dest] > distance[v] + weight && idh > p->idh)
      {
        distance[dest] = distance[v] + weight;
        parent[dest] = v;
      }
    }
    v = 0;
    dist = INT_MAX;
    for (int u = 0; u < nVertices; u++)
    {
      if (intree[u] == false && dist > distance[u])
      {
        dist = distance[u];
        v = u;
      }
    }
  }

  int custo = distance[end];
  cout << "Custo: " << custo << endl;
}

int main()
{
  int nCidades;

  cin >> nCidades;

  cidade cidades[nCidades];

  // Entrada das cidades, nome, codigo, indice
	for(int i = 0; i < nCidades; i++){
		cidades[i].codigo = i;
		cin >> cidades[i].nome;
		cin >> cidades[i].idh; 
  }

  // Quantidade de caminhos
  int num_estradas, origem, destino, distancia;
	cin >> num_estradas;
	
  list<no> adj[num_estradas];

	for(int j=0; j < num_estradas; j++)
  {  
		cin >> origem >> destino >> distancia;
		cidades[origem].vizinhos.push_back({origem, destino, distancia});
    cria_aresta(adj, origem, destino, cidades[destino].idh, distancia, 0);
  }

  float idh;
  int start, end;
  
  cin >> start >> end >> idh;

  dijkstra(adj, nCidades, start, end, idh);

  return 0;
}