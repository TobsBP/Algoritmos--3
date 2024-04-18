#include <iostream>
#include <climits>
#include <list>

using namespace std;

#define VERTICES 10

struct no
{
  int peso;
  int v;
};

void cria_aresta(list<no>adj[], int u, int v, int peso, int orientado)
{
  no aux;

  aux.v = v;
  aux.peso = peso;
  adj[u].push_back(aux);

  if (orientado == 0)
  {
    aux.v = u;
    adj[v].push_back(aux);
  }
}

void dijkstra(list<no>adj[], int nVertices, int start, int end)
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
      dest = p->v;
      weight = p->peso;

      if (distance[dest] > distance[v] + weight)
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

  list<int> caminho;
  int atual = end;
  while (atual != -1) 
  {
    caminho.push_front(atual); // Dependendo da ordem muda o push
    atual = parent[atual];
  }

  list<int>::iterator it;
  for (it = caminho.begin(); it != caminho.end(); it++)
  {
    cout << " " << *it;
  }
  cout << endl;

  int custo = distance[end];
  cout << "Custo: " << custo << endl;
}

int main()
{
  int u, v, peso, orientado;
  int nVertices, start, end;
  list<no>adj[VERTICES];

  cin >> nVertices >> orientado >> start >> end;  

  cin >> u >> v >> peso;
  while (u != -1 && v != -1 && peso != -1)
  {
    cria_aresta(adj, u, v, peso, orientado);
    cin >> u >> v >> peso;
  }
  
  dijkstra(adj, nVertices, start, end);

  return 0;
}