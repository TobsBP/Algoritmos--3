#include <iostream>
#include <list>

using namespace std;

struct no
{
  int destino;
  int peso;
};

void cria_aresta(list<no>adj[], int origem, int destino, int peso, int orientado)
{
  no aux;

  aux.destino = destino;
  aux.peso = peso;
  adj[origem].push_back(aux);

  if (orientado == 0)
  {
    aux.destino = origem;
    adj[destino].push_back(aux);
  }
}

int main()
{
  int destino, origem, peso;
  int nVertices, orientado; // 1 = orientado // 0 = Não orientado

  cin >> nVertices >> orientado;
  list<no> adj[nVertices];

  // Entrada das informações
  cin >> origem >> destino >> peso;
  while (origem != -1 && destino != -1 && peso != -1)
  {
    cria_aresta(adj, origem, destino, peso, orientado); // Cria as arestas no grafo
    cin >> origem >> destino >> peso;
  }
  
  list<no>::iterator p;
  for (int i = 0; i < nVertices; i++)
  {
    for (p = adj[i].begin(); p != adj[i].end(); p++)
    {
      cout << i << " " << p->destino << " " << p->peso << endl;
    }
  }
  
  return 0;
}