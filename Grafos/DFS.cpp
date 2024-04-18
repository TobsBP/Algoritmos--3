#include <iostream>
using namespace std;

#define VERTICE 5

// Precisa passar a quantidade de Vertices, curr onde se inicia
void dfs(int adj[VERTICE][VERTICE], bool visited[], int vertices, int curr) 
{
  visited[curr] = true;
  
  cout << curr << endl; // 0 -> 1 -> 4 -> 2 -> 3

  for (int i = 0; i < vertices; i++)
  {
    if(adj[curr][i] != -1 && visited[i] == false) // Ou seja se existir peso existe conexão e não foi visitado
    {
      dfs(adj, visited, vertices, i);
    } 
  } 
}

int main()
{
  int vertices, directed, o, d, p;
  bool visited[vertices];

  cin >> vertices >> directed;
  
  int adj[vertices][vertices];

  for (int i = 0; i < vertices; i++)
  {
    visited[i] = false;
    for (int j = 0; j < vertices; j++)
    {
      adj[i][j] = -1;
    }
  }

  /*
  0: [(2,31),(5,17),(4,18)]

  1: [(1,31),(5,15)]

  2: [(5,28),(4,22)]

  3: [(1,18),(3,22)]

  4: [(2,15),(1,17),(3,28)
  */
 
  while (cin >> o >> d >> p && o != -1 && d != -1 && p != -1)
  {
    adj[o][d] = p;
    if(!directed)
      adj[d][o] = p;
  }
  
  dfs(adj, visited, vertices, 0);

  return 0;
}