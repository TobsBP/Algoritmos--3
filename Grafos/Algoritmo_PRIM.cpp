#include <iostream>
#include <list>
using namespace std;

struct aresta
{
  int peso;
  int destino;
  int origem;
};

int menor_peso_nao_visitado(list<aresta> adj[], bool visitado[], int n)
{
  int min_peso = 9999;
  int min_indice = -1;

  for (int i = 0; i < n; i++)
  {
    list<aresta>::iterator it;
    for (it = adj[i].begin(); it != adj[i].end(); it++)
    {
      aresta a = *(it);
      if (!visitado[a.destino] && a.peso < min_peso)
      {
        min_peso = a.peso;
        min_indice = a.destino;
      }
    }
  }

  return min_indice;
}

void prim(list<aresta> adj[], int n)
{
  bool visitado[n] = {false};

  for (int i = 0; i < n - 1; i++)
  {
    int u = menor_peso_nao_visitado(adj, visitado, n);

    list<aresta>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++)
    {
      aresta a = *(it);
      if (!visitado[a.destino])
      {
        cout << a.origem << " - " << a.destino << endl;
        break;
      }
    }

    visitado[u] = true;
  }
}

int main()
{
  int n, a, origem, destino, peso;

  // Quantidade de vertices e arestas
  cin >> n >> a;

  list<aresta> adj[n];

  // Lista de adj
  for (int i = 0; i < a; i++)
  {
    cin >> origem >> destino >> peso;

    if (peso != 0)
    {
      adj[origem].push_back({peso, destino, origem});
      adj[destino].push_back({peso, origem, destino});
    }
  }

  prim(adj, n);

  return 0;
}
