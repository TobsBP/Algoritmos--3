#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 99999

struct edge
{
  int orig;
  int dest;
  int weigth;
};

int shortest_path_dijkstra(list<edge> adj[], int vertices, int start, int end)
{
  bool intree[vertices];
  int distance[vertices], parent[vertices];

  for (int u = 0; u < vertices; u++)
  {
    intree[u] = false;
    distance[u] = INT_MAX;
    parent[u] = -1;
  }
  distance[start] = 0;
  int v = start;
  while (intree[v] == false)
  {
    intree[v] = true;
    list<edge>::iterator p;
    for (p = adj[v].begin(); p != adj[v].end(); p++)
    {
      int dest = p->dest;
      int weight = p->weigth;
      if (distance[dest] > distance[v] + weight)
      {
        distance[dest] = distance[v] + weight;
        parent[dest] = v;
      }
    }
    v = 0;
    int dist = INT_MAX;
    for (int u = 0; u < vertices; u++)
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
    caminho.push_back(atual); // Dependendo da orgem muda o push
    atual = parent[atual];
  }
  
  cout << caminho.size() << endl;
}

int main()
{

  int nCidades, directed = 0;
  int nEstradas, start, end;

  cin >> nCidades >> nEstradas;

  list<edge> adj[nCidades];

  int v1, v2, w;
  for (int i = 0; i < nEstradas; i++)
  {
    cin >> v1 >> v2 >> w;
    adj[v1].push_back({v1, v2, w});
    if (directed == 0)
      adj[v2].push_back({v2, v1, w});
  }

  cin >> start >> end;
  cout << shortest_path_dijkstra(adj, nCidades, start, end) << endl;

  return 0;
}