#include <iostream>
#include <string>
#include <list>
using namespace std;

struct no
{
  int v;
  int peso;
};

void bfs(list<no>adj[], int nVertices, int s)
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
    cout << u << endl;

    for (p = adj[u].begin(); p != adj[u].end(); p++)
    {
      v = p->v;
      cout << u << " " << v << endl;
      if (state[v] == 'u')
      {
        state[v] = 'd';
        pai[v] = u;
        Q.push_back(v);
      }
    }
    state[u] = 'p'; // processed
  }
  
}

int main()
{
  int start, num_vert, origem, destino, peso;
  list<no> adj[100];

  cin >> num_vert >> start;

  cin >> origem >> destino >> peso;
  while (origem != -1 && destino != -1 && peso != -1)
  {
    no aux;
    aux.v = destino;
    aux.peso = peso;
    adj[origem].push_back(aux);
    aux.v = origem;
    adj[destino].push_back(aux);
    cin >> origem >> destino >> peso;
  }  

  bfs(adj, num_vert, start);

  return 0;
}