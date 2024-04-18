#include <iostream>
#include <climits>
#include <list>

using namespace std;

#define VERTICES 10 // Maximo delimitado por exemplo

struct no
{
  int v; // Destino
  int peso;
};

void make_aresta(list<no>adj[], int u, int v, int p, int orientado)
{
  no aux;

  //  Cria aresta orientada
  aux.v = v;
  aux.peso = p;
  adj[u].push_back(aux);

  if (orientado == 0)
  {
    aux.v = u;
    adj[v].push_back(aux);
  }
}

void prim(list<no>adj[], int nVertices, int start)
{
  bool intree[nVertices];
  int distance[nVertices];
  int parent[nVertices];
  int u, v, destino;
  int weight, dist;

  for (u = 0; u < nVertices; u++)
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
      destino = p->v;
      weight = p->peso;
      if(distance[destino] > weight && intree[destino]==false)
      {
        distance[destino] = weight;
        parent[destino] = v;
      }
    }

    v = 0;
    dist = INT_MAX;

    for (u = 0; u < nVertices; u++)
    {
      if(intree[u]==false && dist>distance[u])
      {
        dist = distance[u];
        v = u;
      }
    }
  }

  int custo = 0;
  cout << "Arvore Geradora Minima: ";
  for (int i = 0; i < nVertices; i++)
  {
    if (parent[i] != -1) // Se tiver pai, exibe quem é o pai e o indice
    {
      cout << parent[i] << " " << i;
      custo += distance[i];
    }
    cout << endl;
  }

  cout << "Custo: " << custo << endl;
}

int main()
{
  list<no>adj[VERTICES];
  int nVertices;
  int orientado;
  int u, v, p;
  int start;

  cin >> nVertices >> orientado >> start;

  cin >> u >> v >> p;
  while (u != -1 && v != -1 && p != -1)
  {
    make_aresta(adj, u, v, p, orientado);
    cin >> u >> v >> p;
  }
  
  prim(adj, nVertices, start);

  return 0;
}