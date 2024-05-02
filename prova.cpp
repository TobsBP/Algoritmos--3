#include <iostream>
#include <string>
#include <list>
using namespace std;

#define INT_MAX 9999999

struct no
{
  int orig;
  int dest;
  int custo;
};

struct Habilidade
{
  string nome;
  int codigo;
  float poder;
  list<no> upgrades;
};

bool bfs(Habilidade adj[], int nVertices, int s)
{
  char state[100];
  int pai[100];
  list<int> Q;
  list<no>::iterator p;
  int u, v;

  for (int u = 0; u < nVertices; u++)
  {
    if (u != s)
    {
      state[u] = 'u'; // Undiscovered
      pai[u] = -1;
    }
  }

  state[s] = 'd';
  pai[s] = -1;
  Q.push_back(s);
  
  while (!Q.empty())
  {
    u = *Q.begin();
    Q.pop_front();

    for (p = adj[u].upgrades.begin(); p != adj[u].upgrades.end(); p++)
    {
      v = p->dest;
      if (state[v] == 'u')
      {
        state[v] = 'd';
        pai[v] = u;
        Q.push_back(v);
      }
    }
    state[u] = 'p'; // processed
  }

  for (int i = 0; i < nVertices; i++)
  {
    if (state[i] == 'd')
    {
      return false;
    }
  }

  return true;
}

void dijkstra(Habilidade adj[], int nVertices, int start, int end, float poder)
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
    for (p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++)
    {
      destino = p->dest;
      weight = p->custo;
      if (distance[destino] > distance[v] + weight && poder > 0)
      {
        distance[destino] = distance[v] + weight;
        poder -= distance[v] + weight;
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
  // Custo para ir do vertice start até o end
  cout << "Custo: " << distance[end] << endl;
}

int main()
{
  int num_habilidades;
  cin >> num_habilidades;

  Habilidade habilidades[num_habilidades];
  float poder_acumulado = 0;

  for (int i = 0; i < num_habilidades; i++)
  {
    habilidades[i].codigo = i;
    cin >> habilidades[i].nome;
    cin >> habilidades[i].poder;
    poder_acumulado += habilidades[i].poder;
  }

  int num_upgrades, origem, destino, custo;
  cin >> num_upgrades;

  for (int j = 0; j < num_upgrades; j++)
  {
    cin >> origem;
    cin >> destino;
    cin >> custo;
    habilidades[origem].upgrades.push_back({origem, destino, custo});
  }

  float poder_desejado;
  cin >> poder_desejado;

  if (bfs(habilidades, num_habilidades, 0))
  {
    dijkstra(habilidades, num_habilidades, 0, poder_desejado, poder_acumulado);
  }

  return 0;
}