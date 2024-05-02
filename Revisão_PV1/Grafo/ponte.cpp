#include <iostream>
using namespace std;

#define VERTICE 100

void dfs(int adj[VERTICE][VERTICE], bool visited[], int vertices, int curr) 
{
  visited[curr] = true;

  for (int i = 1; i <= vertices; i++)
  {
    if(adj[curr][i] != -1 && visited[i] == false) // Ou seja se existir peso existe conexão e não foi visitado
    {
      dfs(adj, visited, vertices, i);
    } 
  } 
}

int main()
{
  int adj[100][100];
  int i, j, nCidades;
  int a, b, nCaminhos;

  cin >> nCidades >> nCaminhos;
  bool visited[nCidades];

  for (i = 1; i <= nCidades; i++)
  {
    visited[i] = false;
    for (j = 1; j <= nCidades; j++)
    {
      adj[i][j] = -1;
    }
  }
  
  for (i = 1; i <= nCaminhos; i++)
  {
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  cin >> a >> b;
  adj[a][b] = -1;
  adj[b][a] = -1;

  dfs(adj, visited, nCidades, a);

  for (i = 1; i <= nCidades; i++)
  {
    if (!visited[i])
    {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}