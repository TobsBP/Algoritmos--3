#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 100000

struct no
{
  int peso;
  int destino;
  int origem;
};

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

  // Imprimir o menor caminho
  list<int> caminho;
  int atual = end;
  while (atual != -1) {
    caminho.push_front(atual); // Dependendo da orgem muda o push
    atual = parent[atual];
  }

  list<int>::iterator it;
  for (it = caminho.begin(); it != caminho.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Custo para ir do vertice start até o end
  cout << "Custo: " << distance[end] << endl;
}

int main()
{
  int nVertices, orientado, destino;
  int origem, peso, incial, end;

  // Entrada
  cin >> nVertices >> orientado >> incial >> end;

  // Alocando a lista dinamicamente
  list<no> *adj = new list<no>[nVertices];

  // Criando a lista de adj
  while (cin >> origem >> destino >> peso && origem != -1 && destino != -1 && peso != -1)
  {
    no aux;

    aux.destino = destino;
    aux.origem = origem;
    aux.peso = peso;
    adj[origem].push_back(aux);

    if (orientado == 0)
    {
      aux.origem = destino;
      aux.destino = origem;
      adj[destino].push_back(aux);
    }
  }


  // Chama a função
  dijkstra(adj, nVertices, incial, end);

  // Libera a memoria
  delete[] adj;

  return 0;
}