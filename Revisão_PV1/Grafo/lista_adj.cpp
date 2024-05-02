#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v; // vertice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int peso, int orientado)
{
  no aux;
  aux.peso = peso;
  aux.v = v;

  adj[u].push_back(aux);

  if (orientado == 0)
  {
    aux.v = u;
    adj[v].push_back(aux);
  }
}

int main()
{
  int u, v, peso, orientado;
  int nVertices;

  cin >> nVertices >> orientado;

  list<no> adj[nVertices];
  while(cin >> u >> v >> peso && u != -1 && v != -1 && peso != -1)
  {
    cria_aresta(adj, u, v, peso, orientado);
  }

  for (int i = 0; i < nVertices; i++)
  {
    list<no>::iterator p;
    for (p = adj[i].begin(); p != adj[i].end(); p++)
    {
      cout << i << " " << p->v << " " << p->peso << endl;
    }
  }
  

  return 0;
}