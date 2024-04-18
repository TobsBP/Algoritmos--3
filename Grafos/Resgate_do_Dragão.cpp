#include <iostream>
#include <list>

#define INT_MAX 999999
#define Vertices 1000

using namespace std;

struct no
{
  int peso = 1;
  int destino;
  int origem;
};

void cria_aresta(list<no> adj[],int origem, int destino, int orientado)
{
  no aux;

  aux.destino = origem;
  aux.destino = destino;
  adj[origem].push_back(aux);

  if (orientado == 0)
  {
    aux.origem = destino;
    aux.destino = origem;
    adj[destino].push_back(aux);
  }
}

void dijkstra(list<no> adj[], int nVertices, int start, int end)
{
  bool intree[nVertices];
  int distance[nVertices];
  int parent[nVertices];
  list<no>::iterator p;
  int v, weight;
  int dist, destino;

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
    for (p = adj[v].begin(); p != adj[v].end(); p++)
    {
      destino = p->destino;
      weight = p->peso;
      if (distance[destino] > distance[v] + weight)
      {
        distance[destino] = distance[v] + weight;
        parent[destino] = v;
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

  // Cria uma lista com o menor caminho
  list<int> caminho;
  int atual = end;
  while (atual != -1) 
  {
    caminho.push_front(atual); // Dependendo da orgem muda o push
    atual = parent[atual];
  }

  // Imprime o numero de salas até o fim
  if (!caminho.empty())
  {
    cout << caminho.size() << endl;
  }else
  {
    cout << "IMPOSSIVEL" << endl;
  }
  
}

int main()
{
  int nVertices, destino, orientado = 1;
  int origem, nCorredores, start, end;
  no aux;

  cin >> nVertices >> nCorredores;

  list<no> *adj = new list<no>[Vertices];

  for (int i = 0; i < nCorredores; i++)
  {
    cin >> origem >> destino;
    cria_aresta(adj, origem, destino, orientado);
  }
  
  cin >> start >> end;

  dijkstra(adj, nVertices, start, end);
  
  return 0;
}